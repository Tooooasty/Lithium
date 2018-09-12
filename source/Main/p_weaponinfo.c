// This file was generated by wepc.
// Edit only if you aren't going to recompile.
#include "lith_player.h"

// Extern Objects ------------------------------------------------------------|

#define Placeholder1 "MMMMHMHMMMHMMM"
#define Placeholder2 "YOUSONOFABITCH"
#define A(a) "Lith_" a "Ammo"
#define P(a) "weapons/" a "/pickup"
#define N(a) .classname = "Lith_" a, .name = a
#define F(...) .flags = __VA_ARGS__
#define FN(a) .classname = "FD" a, .name = a
#define FDClass(cname) \
   {1, pcl_fdoomer, FN(cname "Fist"),           "YOUSONOFABITCH", AT_None}, \
   {1, pcl_fdoomer, FN(cname "Chainsaw"),       P("cfist"),       AT_None}, \
   {2, pcl_fdoomer, FN(cname "Pistol"),         P("pistol"),      AT_Ammo, "FD" cname "PistolAmmo"}, \
   {3, pcl_fdoomer, FN(cname "Shotgun"),        P("shotgun"),     AT_Ammo, "FD" cname "Shells"}, \
   {3, pcl_fdoomer, FN(cname "SuperShotgun"),   P("ssg"),         AT_Ammo, "FD" cname "Shells"}, \
   {4, pcl_fdoomer, FN(cname "Chaingun"),       P("rifle"),       AT_Ammo, "FD" cname "Bullets"}, \
   {5, pcl_fdoomer, FN(cname "RocketLauncher"), P("rocket"),      AT_Ammo, "FD" cname "Rocket"}, \
   {6, pcl_fdoomer, FN(cname "PlasmaRifle"),    P("plasma"),      AT_Ammo, "FD" cname "Cell"}, \
   {7, pcl_fdoomer, FN(cname "BFG9000"),        P("cannon"),      AT_Ammo, "FD" cname "BFGCharge"},
weaponinfo_t const weaponinfo[weapon_max] = {
   {0, pcl_any, null, "MMMMHMHMMMHMMM"},

   {1, pcl_outcasts, N("ChargeFist"), P("cfist"), AT_None},
   {5, pcl_outcasts, N("MissileLauncher"), P("missile"), AT_AMag, A("Rocket")},
   {6, pcl_outcasts, N("PlasmaDiffuser"), P("plasdiff"), AT_Ammo, A("Plasma")},
   {1, pcl_marine, N("Fist"), Placeholder1, AT_None},
   {2, pcl_marine, N("Pistol"), P("pistol"), AT_NMag},
   {2, pcl_marine, N("Revolver"), P("revolver"), AT_NMag},
   {3, pcl_marine, N("Shotgun"), P("shotgun"), AT_None},
   {3, pcl_marine, N("LazShotgun"), P("lshotgun"), AT_None},
   {3, pcl_marine, N("SuperShotgun"), P("ssg"), AT_Ammo, A("Shell")},
   {4, pcl_marine, N("CombatRifle"), P("rifle"), AT_NMag},
   {4, pcl_marine, N("SniperRifle"), P("sniper"), AT_NMag},
   {5, pcl_marine, N("GrenadeLauncher"), P("rocket"), AT_Ammo, A("Rocket")},
   {6, pcl_marine, N("PlasmaRifle"), P("plasma"), AT_Ammo, A("Plasma")},
   {7, pcl_marine, N("BFG9000"), P("cannon"), AT_Ammo, A("Cannon")},
   {1, pcl_cybermage, N("CFist"), Placeholder2, AT_None},
   {2, pcl_cybermage, N("Mateba"), P("mateba"), AT_NMag},
   {3, pcl_cybermage, N("ShockRifle"), P("erifle"), AT_NMag},
   {3, pcl_cybermage, N("SPAS"), P("cshotgun"), AT_AMag, A("Shell")},
   {4, pcl_cybermage, N("SMG"), P("smg"), AT_NMag},
   {5, pcl_cybermage, N("IonRifle"), P("ionrifle"), AT_AMag, A("Rocket")},
   {6, pcl_cybermage, N("CPlasmaRifle"), P("plasma"), AT_Ammo, A("Plasma")},
   {7, pcl_cybermage, N("StarDestroyer"), P("shipgun"), AT_Ammo, A("Cannon")},
   {0, pcl_cybermage, N("Blade"), Placeholder1, AT_Ammo, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("Delear"), Placeholder1, AT_AMag, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("Feuer"), Placeholder1, AT_Ammo, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("Rend"), Placeholder1, AT_Ammo, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("Hulgyon"), Placeholder1, AT_Ammo, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("StarShot"), Placeholder1, AT_AMag, "Lith_Mana", F(wf_magic)},
   {0, pcl_cybermage, N("Cercle"), Placeholder1, AT_Ammo, "Lith_Mana", F(wf_magic)},
   {2, pcl_darklord, N("700Express"), Placeholder2, AT_NMag},
   {3, pcl_darklord, N("4Bore"), Placeholder2, AT_Ammo, A("Shell")},
   {3, pcl_darklord, N("ShrapnelGun"), Placeholder2, AT_Ammo, A("Shell")},
   {4, pcl_darklord, N("Minigun"), Placeholder2, AT_NMag},
   {5, pcl_darklord, N("DualRocket"), Placeholder2, AT_Ammo, A("Rocket")},
   {6, pcl_darklord, N("FatMac"), Placeholder2, AT_Ammo, A("Plasma")},
   {7, pcl_darklord, N("FortuneGun"), Placeholder2, AT_Ammo, A("Cannon")},
   {0, pcl_any, N("WingsOfDeath"), "MMMMHMHMMMHMMM", AT_None},

   FDClass("Plut")
   FDClass("TNT")
   FDClass("Doom2")
   FDClass("Aliens")
   FDClass("JPCP")
   FDClass("BTSX")
};
#undef FDClass

// Extern Functions ----------------------------------------------------------|

int Lith_WeaponFromName(struct player *p, int name)
{
   switch(p->pclass)
   {
   case pcl_marine:
      switch(name) {
      case wepnam_fist: return weapon_fist;
      case wepnam_chainsaw: return weapon_cfist;
      case wepnam_pistol: return weapon_pistol;
      case wepnam_shotgun: return weapon_shotgun;
      case wepnam_supershotgun: return weapon_ssg;
      case wepnam_chaingun: return weapon_rifle;
      case wepnam_rocketlauncher: return weapon_launcher;
      case wepnam_plasmarifle: return weapon_plasma;
      case wepnam_bfg9000: return weapon_bfg;
      }
   case pcl_cybermage:
      switch(name) {
      case wepnam_fist: return weapon_c_fist;
      case wepnam_chainsaw: return weapon_cfist;
      case wepnam_pistol: return weapon_c_mateba;
      case wepnam_shotgun: return weapon_c_rifle;
      case wepnam_supershotgun: return weapon_c_spas;
      case wepnam_chaingun: return weapon_c_smg;
      case wepnam_rocketlauncher: return weapon_c_sniper;
      case wepnam_plasmarifle: return weapon_c_plasma;
      case wepnam_bfg9000: return weapon_c_shipgun;
      }
   case pcl_darklord:
      switch(name) {
      case wepnam_fist: return weapon_fist;
      case wepnam_chainsaw: return weapon_fist;
      case wepnam_pistol: return weapon_d_700e;
      case wepnam_shotgun: return weapon_d_4bore;
      case wepnam_supershotgun: return weapon_d_launcher;
      case wepnam_chaingun: return weapon_d_minigun;
      case wepnam_rocketlauncher: return weapon_d_rocket;
      case wepnam_plasmarifle: return weapon_d_fatmac;
      case wepnam_bfg9000: return weapon_d_railgun;
      }

   case pcl_fdoomer:
      #define FDClass(cname, ctype) \
         if(p->pcstr == "FD" cname "Player") \
            switch(name) { \
            case wepnam_fist:           return weapon_fd_##ctype##_fist; \
            case wepnam_chainsaw:       return weapon_fd_##ctype##_chainsaw; \
            case wepnam_pistol:         return weapon_fd_##ctype##_pistol; \
            case wepnam_shotgun:        return weapon_fd_##ctype##_shotgun; \
            case wepnam_supershotgun:   return weapon_fd_##ctype##_ssg; \
            case wepnam_chaingun:       return weapon_fd_##ctype##_chaingun; \
            case wepnam_rocketlauncher: return weapon_fd_##ctype##_launcher; \
            case wepnam_plasmarifle:    return weapon_fd_##ctype##_plasma; \
            case wepnam_bfg9000:        return weapon_fd_##ctype##_bfg; \
            }
      FDClass("Plut",   plut)
      FDClass("TNT",    tnt)
      FDClass("Doom2",  doom2)
      FDClass("Aliens", aliens)
      FDClass("JPCP",   jpcp)
      FDClass("BTSX",   btsx)
      #undef FDClass
   }

   return weapon_unknown;
}

// EOF
