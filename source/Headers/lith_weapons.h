// zsc output: pk7/lzscript/Headers/lith_weapons.h

// Copyright © 2016-2017 Graham Sanderson, all rights reserved.
enum // Lith_WeaponNum
{
   weapon_unknown,
   weapon_min,

   // Outcast Weapons
   weapon_cfist = weapon_min,
   weapon_missile,
   weapon_plasmadiff,

   // Marine Weapons
   weapon_fist,
   weapon_pistol,
   weapon_revolver,
   weapon_shotgun,
   weapon_lazshotgun,
   weapon_ssg,
   weapon_rifle,
   weapon_sniper,
   weapon_launcher,
   weapon_plasma,
   weapon_bfg,

   // Cyber-Mage Weapons
   weapon_c_fist,
   weapon_c_mateba,
   weapon_c_rifle,
   weapon_c_spas,
   weapon_c_smg,
   weapon_c_sniper,
   weapon_c_plasma,
   weapon_c_shipgun,

   weapon_c_blade,
   weapon_c_delear,
   weapon_c_fire,
   weapon_c_rend,
   weapon_c_hulgyon,
   weapon_c_starshot,
   weapon_c_cercle,

   // Dark Lord Weapons
   weapon_d_700e,
   weapon_d_minigun,
   weapon_d_fatmac,

   // Misc. Weapons
   weapon_wings,

   weapon_max_lith,

   // Final Doomer Weapons
   weapon_fd_plut_fist = weapon_max_lith,
   weapon_fd_plut_chainsaw,
   weapon_fd_plut_pistol,
   weapon_fd_plut_shotgun,
   weapon_fd_plut_ssg,
   weapon_fd_plut_chaingun,
   weapon_fd_plut_launcher,
   weapon_fd_plut_plasma,
   weapon_fd_plut_bfg,

   weapon_fd_tnt_fist,
   weapon_fd_tnt_chainsaw,
   weapon_fd_tnt_pistol,
   weapon_fd_tnt_shotgun,
   weapon_fd_tnt_ssg,
   weapon_fd_tnt_chaingun,
   weapon_fd_tnt_launcher,
   weapon_fd_tnt_plasma,
   weapon_fd_tnt_bfg,

   weapon_fd_doom2_fist,
   weapon_fd_doom2_chainsaw,
   weapon_fd_doom2_pistol,
   weapon_fd_doom2_shotgun,
   weapon_fd_doom2_ssg,
   weapon_fd_doom2_chaingun,
   weapon_fd_doom2_launcher,
   weapon_fd_doom2_plasma,
   weapon_fd_doom2_bfg,

   weapon_fd_aliens_fist,
   weapon_fd_aliens_chainsaw,
   weapon_fd_aliens_pistol,
   weapon_fd_aliens_shotgun,
   weapon_fd_aliens_ssg,
   weapon_fd_aliens_chaingun,
   weapon_fd_aliens_launcher,
   weapon_fd_aliens_plasma,
   weapon_fd_aliens_bfg,

   weapon_fd_jpcp_fist,
   weapon_fd_jpcp_chainsaw,
   weapon_fd_jpcp_pistol,
   weapon_fd_jpcp_shotgun,
   weapon_fd_jpcp_ssg,
   weapon_fd_jpcp_chaingun,
   weapon_fd_jpcp_launcher,
   weapon_fd_jpcp_plasma,
   weapon_fd_jpcp_bfg,

   weapon_fd_btsx_fist,
   weapon_fd_btsx_chainsaw,
   weapon_fd_btsx_pistol,
   weapon_fd_btsx_shotgun,
   weapon_fd_btsx_ssg,
   weapon_fd_btsx_chaingun,
   weapon_fd_btsx_launcher,
   weapon_fd_btsx_plasma,
   weapon_fd_btsx_bfg,

   weapon_max
};

enum // Lith_WeaponName
{
   wepnam_fist,
   wepnam_chainsaw,
   wepnam_pistol,
   wepnam_shotgun,
   wepnam_supershotgun,
   wepnam_chaingun,
   wepnam_rocketlauncher,
   wepnam_plasmarifle,
   wepnam_bfg9000,

   wepnam_max,
};

enum // Lith_RifleMode
{
   rifle_firemode_auto,
   rifle_firemode_grenade,
   rifle_firemode_burst,
   rifle_firemode_max
};

// EOF
