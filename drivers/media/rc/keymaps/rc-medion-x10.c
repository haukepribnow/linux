/*
 * Medion X10 RF remote keytable
 *
 * Copyright (C) 2011 Anssi Hannula <anssi.hannula@?ki.fi>
 *
 * This file is based on a keytable provided by
 * Jan Losinski <losinski@wh2.tu-dresden.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/module.h>
#include <media/rc-map.h>

static struct rc_map_table medion_x10[] = {
/*	{ code, key },                 button label or icon[, supertitle or subtitle] */
	{ 0x2c, KEY_TV },              /* TV */
	{ 0x2d, KEY_VCR },             /* VCR */
	{ 0x04, KEY_DVD },             /* DVD */
	{ 0x06, KEY_AUDIO },           /* MUSIC */

	{ 0x2e, KEY_RADIO },           /* RADIO */
	{ 0x05, KEY_IMAGES },          /* PHOTO */
	{ 0x2f, KEY_PROGRAM },         /* <icon with a 3x3 grid of small TV screens>, subtitle: TV PREVIEW */
	{ 0x30, KEY_CHANNEL },         /* <icon with several horizontal lines>, subtitle: CHANNEL LIST */

	{ 0x1b, KEY_CONFIG },          /* S, subtitle: SETUP */
	{ 0x31, KEY_VIDEO },           /* <icon with a TV screen displaying lines>, subtitle: VIDEO DESKTOP */

	{ 0x08, KEY_VOLUMEDOWN },      /* VOL - */
	{ 0x09, KEY_VOLUMEUP },        /* VOL + */
	{ 0x0b, KEY_CHANNELUP },       /* CHAN + */
	{ 0x0c, KEY_CHANNELDOWN },     /* CHAN - */
	{ 0x00, KEY_MUTE },            /* <Mute icon> */

	{ 0x32, KEY_RED },             /* <red circle> */
	{ 0x33, KEY_GREEN },           /* <green circle> */
	{ 0x34, KEY_YELLOW },          /* <yellow circle> */
	{ 0x35, KEY_BLUE },            /* <blue circle> */
	{ 0x16, KEY_TEXT },            /* TXT */

	{ 0x0d, KEY_NUMERIC_1 },
	{ 0x0e, KEY_NUMERIC_2 },
	{ 0x0f, KEY_NUMERIC_3 },
	{ 0x10, KEY_NUMERIC_4 },
	{ 0x11, KEY_NUMERIC_5 },
	{ 0x12, KEY_NUMERIC_6 },
	{ 0x13, KEY_NUMERIC_7 },
	{ 0x14, KEY_NUMERIC_8 },
	{ 0x15, KEY_NUMERIC_9 },
	{ 0x17, KEY_NUMERIC_0 },
	{ 0x1c, KEY_SEARCH },          /* TV/RADIO, supertitle: CH. SEARCH */
	{ 0x20, KEY_BACKSPACE },       /* <arrow pointing to the left>, supertitle: DELETE */

	{ 0x36, KEY_EDIT },            /* <empty>, supertitle: RENAME */
	        /* KEY_EDIT seemed to be the closest match for "RENAME" */
	{ 0x18, KEY_SYSRQ },           /* <empty>, supertitle: SNAPSHOT */
	        /* KEY_SYSRQ (being the button to create screenshots) seemed to be the closest
	           match for SNAPSHOT. Also, KEY_SYSRQ is also used by other remotes for a
	           button with such a label, e.g. kworld_pc150u or nvec. */

	{ 0x1a, KEY_UP },              /* <triangle pointing up> */
	{ 0x22, KEY_DOWN },            /* <triangle pointing down> */
	{ 0x1d, KEY_LEFT },            /* <triangle pointing left> */
	{ 0x1f, KEY_RIGHT },           /* <triangle pointing right> */
	{ 0x1e, KEY_OK },              /* OK */

	{ 0x37, KEY_CAMERA },          /* <empty>, supertitle: ACQUIRE IMAGE */
	{ 0x38, KEY_GRAPHICSEDITOR },  /* <empty>, supertitle: EDIT IMAGE */

	{ 0x24, KEY_REWIND },          /* <rewind icon>       (<<) */
	{ 0x25, KEY_PLAY },            /* <play icon>         ( >) */
	{ 0x26, KEY_FASTFORWARD },     /* <fast forward icon> (>>) */
	{ 0x27, KEY_RECORD },          /* <record icon>       ( o) */
	{ 0x28, KEY_STOP },            /* <stop icon>         ([]) */
	{ 0x29, KEY_PAUSE },           /* <pause icon>        (||) */

	{ 0x21, KEY_PREVIOUS },        /* <skip to prev icon> (|<<) */
	{ 0x39, KEY_ZOOM },            /* <icon with an empty TV screen>, subtitle: FULL SCREEN */
	{ 0x23, KEY_NEXT },            /* <skip to next icon> (>>|)  */
	
	{ 0x19, KEY_MENU },            /* <empty>, subtitle: DVD MENU */
	{ 0x3a, KEY_LANGUAGE },        /* <empty>, subtitle: DVD AUDIO */

	{ 0x02, KEY_POWER2 },          /* <power icon> */
	        /* Other remotes use KEY_POWER2 (e.g. kworld_pc150u or nvec) instead of KEY_POWER,
	           so let's do this here as well. */
};

static struct rc_map_list medion_x10_map = {
	.map = {
		.scan    = medion_x10,
		.size    = ARRAY_SIZE(medion_x10),
		.rc_type = RC_TYPE_OTHER,
		.name    = RC_MAP_MEDION_X10,
	}
};

static int __init init_rc_map_medion_x10(void)
{
	return rc_map_register(&medion_x10_map);
}

static void __exit exit_rc_map_medion_x10(void)
{
	rc_map_unregister(&medion_x10_map);
}

module_init(init_rc_map_medion_x10)
module_exit(exit_rc_map_medion_x10)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anssi Hannula <anssi.hannula@iki.fi>");
