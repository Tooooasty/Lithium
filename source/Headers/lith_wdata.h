// zsc output: pk7/lzscript/Headers/lith_wdata.h

// Copyright © 2016-2017 Alison Sanderson, all rights reserved.

enum // Lith_WData
{
   wdata_bossspawned,
   wdata_enemycheck,
   wdata_fun,
   wdata_soulsfreed,
   wdata_dorain,
   wdata_ptid,
   wdata_pclass,
};

enum // Lith_Fun
{
   lfun_ragnarok = 1 << 0,
};

enum // Lith_CBIUpgradeM
{
   cupg_weapninter,
   cupg_hasupgr1,
   cupg_armorinter,
   cupg_hasupgr2,
   cupg_weapninte2,
   cupg_rdistinter,
   cupg_max
};

enum // Lith_CBIUpgradeC
{
   cupg_c_slot3spell,
   cupg_c_slot4spell,
   cupg_c_slot5spell,
   cupg_c_slot6spell,
   cupg_c_slot7spell,
   cupg_c_rdistinter,
};

enum // Lith_RandomSpawnNum
{
   lrsn_garmor,
   lrsn_barmor,
   lrsn_hbonus,
   lrsn_abonus,
   lrsn_clip,
   lrsn_clipbx,
};

enum // Lith_ArmorSlot
{
   aslot_lower,
   aslot_upper,
   aslot_ring,
   aslot_pauld,
   aslot_max
};

enum // Lith_MsgType
{
   msg_ammo,
   msg_huds,
   msg_full,
   msg_both
};


enum // Lith_DamageType
{
   ldt_bullets,
   ldt_energy,
   ldt_fire,
   ldt_firemagic,
   ldt_magic,
   ldt_melee,
   ldt_shrapnel,
   ldt_ice,
   ldt_hazard,
   ldt_none
};

// EOF
