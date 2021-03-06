// Copyright © 2016-2017 Alison Sanderson, all rights reserved.
#include "lith_upgrades_common.h"

#define UData UData_lolsords(upgr)

// Extern Functions ----------------------------------------------------------|

stkcall
void Upgr_lolsords_Activate(struct player *p, upgrade_t *upgr)
{
   UData.origweapon = p->weaponclass;
   InvGive("Lith_Sword", 1);
}

stkcall
void Upgr_lolsords_Deactivate(struct player *p, upgrade_t *upgr)
{
   InvTake("Lith_Sword", 1);
   ACS_SetWeapon(UData.origweapon);
}

script
void Upgr_lolsords_Update(struct player *p, upgrade_t *upgr)
{
   ACS_SetWeapon("Lith_Sword");
}

// EOF

