#ifndef LITH_CBI_H
#define LITH_CBI_H

// BIP - Biotic Information Panel
typedef struct bip_s
{
   void *no_data;
} bip_t;

// CBI - Computer/Brain Interface
typedef struct cbi_s
{
   struct dlist_s *ui;
   
   struct cursor_s
   {
      fixed x;
      fixed y;
   } cur;
   
   bool wasinit;
   bool open;
} cbi_t;

[[__call("ScriptI")]]
void Lith_PlayerInitCBI(struct player_s *p);

[[__call("ScriptI")]]
void Lith_PlayerUpdateCBI(struct player_s *p);

[[__call("ScriptI")]]
void Lith_PlayerDrawCBI(struct player_s *p);

#endif
