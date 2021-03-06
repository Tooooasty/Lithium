// Copyright © 2016-2017 Alison Sanderson, all rights reserved.
#include "lith_common.h"
#include "lith_player.h"
#include "lith_world.h"

#include <stdio.h>
#include <GDCC.h>

// Extern Objects ------------------------------------------------------------|

__str dbgstat[64], dbgnote[64];
int   dbgstatnum,  dbgnotenum;

// Static Functions ----------------------------------------------------------|

stkcall
static void SetInventory(__str item, int amount)
{
   int s = InvNum(item) - amount;
        if(s < 0) InvTake(item, -s);
   else if(s > 0) InvGive(item,  s);
}

stkcall
static void SetActorInventory(int tid, __str item, int amount)
{
   int s = ACS_CheckActorInventory(tid, item) - amount;
        if(s < 0) ACS_TakeActorInventory(tid, item, -s);
   else if(s > 0) ACS_GiveActorInventory(tid, item,  s);
}

// Extern Functions ----------------------------------------------------------|

script
void Lith_DumpAlloc(void)
{
   __GDCC__alloc_dump();
}

stkcall
void Lith_FadeFlash(int r, int g, int b, fixed amount, fixed seconds)
{
   ACS_FadeTo(r, g, b, amount, 0.0);
   ACS_FadeTo(r, g, b, 0.0, seconds);
}

script
int Lith_GetTID(int tid, int ptr)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_ActivatorTID();
}

script
int Lith_GetPlayerNumber(int tid, int ptr)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_PlayerNumber();
}

script
bool Lith_ValidPointer(int tid, int ptr)
{
   if(tid || ptr)
      return ACS_SetActivator(tid, ptr);
   else
      return true;
}

script
bool Lith_SetPointer(int tid, int ptr, int assign, int tid2, int ptr2, int flags)
{
   if(tid || ptr)
      ACS_SetActivator(tid, ptr);
   return ACS_SetPointer(assign, tid2, ptr2, flags);
}

stkcall
int Lith_CheckActorInventory(int tid, __str item)
{
   if(tid == 0) return InvNum(item);
   else         return ACS_CheckActorInventory(tid, item);
}

stkcall
void Lith_GiveActorInventory(int tid, __str item, int amount)
{
   if(tid == 0) InvGive(item, amount);
   else         ACS_GiveActorInventory(tid, item, amount);
}

stkcall
void Lith_TakeActorInventory(int tid, __str item, int amount)
{
   if(tid == 0) InvTake(item, amount);
   else         ACS_TakeActorInventory(tid, item, amount);
}

stkcall
void Lith_SetActorInventory(int tid, __str item, int amount)
{
   if(tid == 0) SetInventory(item, amount);
   else         SetActorInventory(tid, item, amount);
}

void Lith_DebugStat(__str fmt, ...)
{
   if(!(world.dbgLevel & log_devh)) return;

   va_list vl;

   ACS_BeginPrint();

   va_start(vl, fmt);
   __vnprintf_str(fmt, vl);
   va_end(vl);

   dbgstat[dbgstatnum++] = ACS_EndStrParam();
}

void Lith_DebugNote(__str fmt, ...)
{
   if(!(world.dbgLevel & log_devh)) return;

   va_list vl;

   ACS_BeginPrint();

   va_start(vl, fmt);
   __vnprintf_str(fmt, vl);
   va_end(vl);

   dbgnote[dbgnotenum++] = ACS_EndStrParam();
}

// EOF

