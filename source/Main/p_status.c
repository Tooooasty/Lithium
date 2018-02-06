// Copyright © 2017 Graham Sanderson, all rights reserved.
#include "lith_common.h"
#include "lith_player.h"
#include "lith_world.h"

// Static Functions ----------------------------------------------------------|

//
// AttrBar
//
static void AttrBar(gui_state_t *g, int x, int y, int w, __str gfx)
{
   Lith_GUI_Clip(g, x, y, w * 2, 8);
   PrintSprite(gfx, x,1, y,1);
   Lith_GUI_ClipRelease(g);
}

//
// DrawAttr
//
static void DrawAttr(gui_state_t *g, int x, int y, player_t *p, int at)
{
   unsigned attr = p->attr.attrs[at];
   __str    name = p->attr.names[at];
   fixed    helptrns = 0.5;

   if(p->attr.points) {
      if(Lith_GUI_Button_Id(g, at, .disabled = p->attr.sup.attrs[at] <= attr, .x = x-42, y-2, Pre(btnprev), .slide = true))
      {
         p->attr.sup.points++;
         p->attr.sup.attrs[at]--;
      }

      if(Lith_GUI_Button_Id(g, at, .disabled = !p->attr.sup.points || p->attr.sup.attrs[at] >= ATTR_MAX,.x = x-42 + guipre.btnprev.w, y-2, Pre(btnnext), .slide = true))
      {
         p->attr.sup.points--;
         p->attr.sup.attrs[at]++;
      }
   }

   PrintTextFmt("%.3S", name);
   PrintText("CHFONT", CR_WHITE, x-24,1, y,1);

   PrintSprite("lgfx/UI/AttrBar1.png", x,1, y,1);

   unsigned satr = p->attr.sup.attrs[at];

   if(satr != attr)
      AttrBar(g, x, y, satr, "lgfx/UI/AttrBar3.png");

   AttrBar(g, x, y, attr, "lgfx/UI/AttrBar2.png");

   if(attr > ATTR_VIS_MAX) {
      int vatr = attr - ATTR_VIS_MAX;
      AttrBar(g, x, y, (vatr / (float)ATTR_VIS_DIFF) * ATTR_VIS_MAX, "lgfx/UI/AttrBar4.png");
      helptrns += 0.3;
   }

   PrintTextFmt("%u/%i", satr, ATTR_VIS_MAX);
   PrintText("CHFONT", CR_WHITE, x+202,1, y,1);

   static __str const helpstrs[at_max] = {
      [at_acc] = "Weapon damage",
      [at_def] = "Armor efficiency",
      [at_str] = "Health capacity",
      [at_vit] = "Health pickup efficiency",
      [at_stm] = "Health regeneration",
      [at_luk] = "Random chance",
      [at_rge] = "Damage buff when hit"
   };

   PrintTextStr(helpstrs[at]);
   PrintTextA("CHFONT", CR_WHITE, x+1,1, y+1,1, helptrns);

   PrintTextFmt("%u/%i", satr, ATTR_VIS_MAX);
   PrintText("CHFONT", CR_WHITE, x+202,1, y,1);
}

//
// StatusInfo
//
static void StatusInfo(gui_state_t *g, int x, int y, __str left, __str right)
{
   PrintTextStr(left);
   PrintText("CHFONT", CR_WHITE, x,1, y,1);
   PrintTextStr(right);
   PrintText("CHFONT", CR_WHITE, x+80,2, y,1);
}

// Extern Functions ----------------------------------------------------------|

//
// Lith_CBITab_Status
//
void Lith_CBITab_Status(gui_state_t *g, player_t *p)
{
   int x = 30, y = 40;
   PrintTextStr(p->name);
   PrintText("CHFONT", CR_WHITE, x,1, y,1);
   y += 10;
   PrintTextStr(p->classname);
   PrintText("CHFONT", CR_WHITE, x,1, y,1);
   StatusInfo(g, x, y += 10, "Lv.",  StrParam("%u", p->attr.level));
   StatusInfo(g, x, y += 10, "HP",   StrParam("%i/%i", p->health, p->maxhealth));
   if(p->pclass & pcl_magicuser)
      StatusInfo(g, x, y += 10, "MP", StrParam("%i/%i", p->mana, p->manamax));
   StatusInfo(g, x, y += 10, "EXP",  StrParam("%lu", p->attr.exp));
   StatusInfo(g, x, y += 10, "Next", StrParam("%lu", p->attr.expnext));
   x = 20;
   if(p->pclass & pcl_magicuser) y += 20;
   else                          y += 30;
   if(p->attr.points) {
      PrintTextFmt("Divide %u points among your attributes.", p->attr.sup.points);
      PrintText("CHFONT", CR_WHITE, x,1, y,1);
   }
   x  = 60;
   y += 10;
   for(int i = 0; i < at_max; i++, y += 10)
      DrawAttr(g, x++, y, p, i);
   if(p->attr.points)
      if(Lith_GUI_Button(g, "Apply", 255, 208))
         p->attr.cur = p->attr.sup;
}

// EOF