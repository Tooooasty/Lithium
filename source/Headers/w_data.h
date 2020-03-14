/* ---------------------------------------------------------------------------|
 *
 * Distributed under the CC0 public domain license.
 * By Alison Sanderson. Attribution is encouraged, though not required.
 * See licenses/cc0.txt for more information.
 *
 * ---------------------------------------------------------------------------|
 *
 * Exposed world data.
 *
 * ---------------------------------------------------------------------------|
 */
/* decompat-out pk7/lzscript/Constants/w_data.zsc */

enum /* Lith_XHair */
{
   lxh_max = 10,
};

enum /* Lith_WData */
{
   wdata_bossspawned,
   wdata_fun,
   wdata_soulsfreed,
   wdata_dorain,
   wdata_ptid,
   wdata_pclass,
};

enum /* Lith_Fun */
{
   lfun_ragnarok = 1 << 0,
};

enum /* Lith_CBIUpgradeM */
{
   cupg_weapninter,
   cupg_hasupgr1,
   cupg_armorinter,
   cupg_hasupgr2,
   cupg_weapninte2,
   cupg_rdistinter,
   cupg_max
};

enum /* Lith_CBIUpgradeC */
{
   cupg_c_slot3spell,
   cupg_c_slot4spell,
   cupg_c_slot5spell,
   cupg_c_slot6spell,
   cupg_c_slot7spell,
   cupg_c_rdistinter,
};

enum /* Lith_RandomSpawnNum */
{
   lrsn_garmor,
   lrsn_barmor,
   lrsn_hbonus,
   lrsn_abonus,
   lrsn_clip,
   lrsn_clipbx,
};

enum /* Lith_MsgType */
{
   msg_ammo,
   msg_huds,
   msg_full,
   msg_both
};

enum /* Lith_DamageType */
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

enum /* Lith_ScriptNum */
{
   lsc_getfontmetric = 17100,
   lsc_metr_xadv,
   lsc_metr_yofs,
   lsc_metr_tex,
   lsc_metr_w,
   lsc_metr_h,
   lsc_drawplayericon,
   lsc_pdata,
   lsc_wdata,
   lsc_addangle,
   lsc_monsterinfo,
   lsc_raindropspawn,
   lsc_monstertype,
};

enum /* Lith_BossType */
{
   boss_none,
   boss_barons,
   boss_cyberdemon,
   boss_spiderdemon,
   boss_iconofsin,
   boss_other,
};

/* EOF */
