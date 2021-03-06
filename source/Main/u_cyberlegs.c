// Copyright © 2016-2017 Alison Sanderson, all rights reserved.
#include "lith_upgrades_common.h"

// Extern Functions ----------------------------------------------------------|

stkcall
void Upgr_CyberLegs_Activate(struct player *p, upgrade_t *upgr)
{
   p->speedmul += 0.2;
   p->jumpboost += 0.5;
}

stkcall
void Upgr_CyberLegs_Deactivate(struct player *p, upgrade_t *upgr)
{
   p->speedmul -= 0.2;
   p->jumpboost -= 0.5;
}

script
void Upgr_CyberLegs_Update(struct player *p, upgrade_t *upgr)
{
   fixed absvel = absk(p->old.velz) * 10.0k;

   if(p->velz == 0 && absvel > 160)
   {
      for(fixed i = absvel; i >= 100; i -= 100)
      {
         int tid;
         ACS_SpawnForced("Lith_ExplodoBoots", p->x, p->y, p->z, tid = ACS_UniqueTID());
         ACS_SetActivator(tid);
         ACS_SetPointer(AAPTR_TARGET, p->tid);
         p->setActivator();
      }
   }
}

// EOF

