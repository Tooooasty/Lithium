// Copyright © 2017 Graham Sanderson, all rights reserved.
// vim: columns=120
#include "lith_player.h"
#include "lith_world.h"
#include "cpk1_upgrades.h"

// Static Objects ------------------------------------------------------------|

#define K(n) .key = n
static upgradeinfo_t const UpgrInfo[] = {
   {{"HeadsUpDis3", "HeadsUpDisp", 0}, pcl_informant, UC_Body, 1, -0.05, UG_HUD, K(UPGR_HeadsUpDis3)},
};
#undef K

// Static Functions ----------------------------------------------------------|

static bool ReinitUpgrades(upgradeinfo_t *ui)
{
   switch(ui->key)
   {
   #define Case(n) return true; case UPGR_##n:
   #define A(n) ui->Activate   = Upgr_##n##_Activate;
   #define D(n) ui->Deactivate = Upgr_##n##_Deactivate;
   #define U(n) ui->Update     = Upgr_##n##_Update;
   #define E(n) ui->Enter      = Upgr_##n##_Enter;
   #define R(n) ui->Render     = Upgr_##n##_Render;
   #include "cpk1_upgradefuncs.h"
      return true;
   }

   return false;
}

static void GSInit()
{
   Lith_UpgradeRegisterReinit(ReinitUpgrades);

   for(int i = 0; i < countof(UpgrInfo); i++)
      Lith_UpgradeRegister(&UpgrInfo[i]);
}

// Scripts -------------------------------------------------------------------|

[[__call("ScriptS"), __script("Open")]]
static void Lith_Cpk1_World()
{
   if(!world.gsinit)
      Lith_GSInitRegister(GSInit);
}

// EOF
