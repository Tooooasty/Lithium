#include "lith_common.h"
#include "lith_log.h"
#include "lith_player.h"
#include "lith_list.h"
#include "lith_hudid.h"

#include <stdio.h>

#define LOG_TIME 140

#define DrawMsg(hid, flags) \
   ( \
      HudMessageF("LOGFONT", "%S", logdata->info), \
      HudMessageParams(HUDMSG_NOWRAP|HUDMSG_FADEOUT|flags, hid, CR_GREEN, 0.1, 262.2 - (10 * i), TICSECOND, 0.1) \
   )


//----------------------------------------------------------------------------
// Extern Functions
//

//
// Lith_LogName
//
[[__call("ScriptS"), __extern("ACS")]]
void Lith_LogName(int name)
{
   player_t *p = LocalPlayer;
   
   switch(name)
   {
#define BOTH(name, str) case name: Lith_Log (p, "%LS", "LITH_TXT_LOG_" str); break;
#define FULL(name, str) case name: Lith_LogF(p, "%LS", "LITH_TXT_LOG_" str); break;
#define HUDS(name, str) case name: Lith_LogH(p, "%LS", "LITH_TXT_LOG_" str); break;
   BOTH(log_default,     "Default")
   BOTH(log_allmap,      "AllMap")
   HUDS(log_armorbonus,  "ArmorBonus")
   BOTH(log_backpack,    "Backpack")
   BOTH(log_berserk,     "Berserk")
   BOTH(log_bluearmor,   "BlueArmor")
   BOTH(log_blursphere,  "BlurSphere")
   BOTH(log_greenarmor,  "GreenArmor")
   HUDS(log_healthbonus, "HealthBonus")
   BOTH(log_infrared,    "InfraRed")
   BOTH(log_invulnerability, "Invulnerability")
   BOTH(log_medikit,     "Medikit")
   BOTH(log_megasphere,  "MegaSphere")
   BOTH(log_radsuit,     "RadSuit")
   BOTH(log_soulsphere,  "SoulSphere")
   BOTH(log_stimpack,    "StimPack")
   BOTH(log_redcard,     "RedCard")
   BOTH(log_bluecard,    "BlueCard")
   BOTH(log_yellowcard,  "YellowCard")
   BOTH(log_redskull,    "RedSkull")
   BOTH(log_blueskull,   "BlueSkull")
   BOTH(log_yellowskull, "YellowSkull")
   BOTH(log_doggosphere, "DoggoSphere")
   BOTH(log_dogs,        "Dogs")
#undef BOTH
#undef FULL
#undef HUDS
   }
}

//
// Lith_Log
//
void Lith_Log(player_t *p, __str fmt, ...)
{
   va_list vl;
   
   va_start(vl, fmt);
   logdata_t *logdata = Lith_LogV(p, fmt, vl);
   va_end(vl);
   
   logdata->time = LOG_TIME;
   Lith_ListLink(&p->loginfo.hud, &logdata->link);
   Lith_ListLink(&p->loginfo.full, &logdata->linkfull);
   
   if(Lith_ListSize(&p->loginfo.hud) > LOG_MAX)
      free(Lith_ListUnlink(p->loginfo.hud.next));
}

//
// Lith_LogF
//
void Lith_LogF(player_t *p, __str fmt, ...)
{
   va_list vl;
   
   va_start(vl, fmt);
   logdata_t *logdata = Lith_LogV(p, fmt, vl);
   va_end(vl);
   
   Lith_ListLink(&p->loginfo.full, &logdata->linkfull);
}

//
// Lith_LogH
//
void Lith_LogH(player_t *p, __str fmt, ...)
{
   va_list vl;
   
   va_start(vl, fmt);
   logdata_t *logdata = Lith_LogV(p, fmt, vl);
   va_end(vl);
   
   logdata->time = LOG_TIME;
   Lith_ListLink(&p->loginfo.hud, &logdata->link);
   
   if(Lith_ListSize(&p->loginfo.hud) > LOG_MAX)
      free(Lith_ListUnlink(p->loginfo.hud.next));
}

//
// Lith_LogV
//
logdata_t *Lith_LogV(player_t *p, __str fmt, va_list vl)
{
   logdata_t *logdata = calloc(1, sizeof(logdata_t));
   Lith_LinkDefault(&logdata->link, logdata);
   Lith_LinkDefault(&logdata->linkfull, logdata);
   
   ACS_BeginPrint();
   __vnprintf_str(fmt, vl);
   
   logdata->info = ACS_EndStrParam();
   logdata->from = ACS_GetLevelInfo(LEVELINFO_LEVELNUM);
   
   return logdata;
}

//
// Lith_PlayerUpdateLog
//
[[__call("ScriptS")]]
void Lith_PlayerUpdateLog(player_t *p)
{
   for(list_t *rover = p->loginfo.hud.next; rover != &p->loginfo.hud;)
   {
      logdata_t *logdata = rover->object;
      
      if(logdata->time == 0)
      {
         list_t *next = rover->next;
         Lith_ListUnlink(rover);
         rover = next;
      }
      else
      {
         logdata->time--;
         rover = rover->next;
      }
   }
}

//
// Lith_HUD_Log
//
[[__call("ScriptS")]]
void Lith_HUD_Log(player_t *p)
{
   ACS_SetHudSize(480, 300);
   
   int i = 0;
   Lith_ForListIter(logdata_t *logdata, p->loginfo.hud, i++)
   {
      DrawMsg(hid_logE + i, HUDMSG_PLAIN);
      
      if(logdata->time > LOG_TIME - 10)
         DrawMsg(hid_logAddE + i, HUDMSG_ADDBLEND);
   }
}

//
// Lith_PlayerLogEntry
//
void Lith_PlayerLogEntry(player_t *p)
{
   logmap_t *logmap = calloc(1, sizeof(logmap_t));
   Lith_LinkDefault(&logmap->link, logmap);
   
   logmap->levelnum = ACS_GetLevelInfo(LEVELINFO_LEVELNUM);
   logmap->name = StrParam("%tS", PRINTNAME_LEVELNAME); // :|
   
   Lith_ListLink(&p->loginfo.maps, &logmap->link);
   
   int seconds = 53 + (p->ticks / 35);
   int minutes = 30 + (seconds  / 60);
   int hours   = 14 + (minutes  / 60);
   int days    = 25 + (hours    / 24); // pls
   
   Lith_LogF(p, "Entered %S at %0.2i:%0.2i:%0.2i %i/7/1649 NE",
      logmap->name, hours % 24, minutes % 60, seconds % 60, days);
}

// EOF

