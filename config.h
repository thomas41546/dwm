/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-misc-droid sans mono-medium-r-*-*-10-120-*-*-*-*-*-1";
static const char normbordercolor[] = "#333333";
static const char normbgcolor[]     = "#051121";
static const char normfgcolor[]     = "#FFFFFF";
static const char selbordercolor[]  = "#009999";
static const char selbgcolor[]      = "#1793D1";
static const char selfgcolor[]      = "#FFFFFF";
static unsigned int borderpx        = 1;        /* border pixel of windows */
static unsigned int snap            = 24;       /* snap pixel */
static Bool showbar                 = True;     /* False means no bar */
static Bool topbar                  = True;     /* False means bottom bar */
/* tagging */
static const char *tags[] = { "Browser", "Music", "Email", "Torrent", "Programming", "Misc" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",	NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",	NULL,       NULL,       1 << 0,       False,       -1 },
	{ "Gnome-panel",NULL,	    NULL,       1 << 4 | 1 << 5, True , 	   -1},
	{ "Rhythmbox",	NULL,     NULL,       	1 << 1,       False , 	   -1},
	{ "Evolution",NULL,     NULL,       	1 << 2,       False , 	   -1},
	{ "Transmission",NULL,     NULL,       	1 << 3,       False , 	   -1},
	{ "Pidgin"	,NULL,     NULL,       	1 << 5,       True , 	   -1},
	{ "QEMU"	,NULL,     NULL,       	1 << 5,       False , 	   -1},
	{ "Eclipse"	,NULL,     NULL,       	1 << 4,       False , 	   -1}, //TODO CHANGE TO 5
	{ "Giggle"	,NULL,     NULL,       	1 << 4,       False , 	   -1},
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[B]",      bstack },    /* first entry is default */
	{ "[G]",      gaplessgrid },
	{ "[M]",      monocle },
	{ "[F]",      NULL },    /* no layout function means floating behavior */

};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                         KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "gnome-terminal", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };
static const char *browsercmd[]  = { "pcmanfm", NULL };
static const char *musiccmd[]  = { "rhythmbox", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	//{ MODKEY,                       XK_b,      togglebar,      {0} },

	{ Mod4Mask,           		  XK_x,      spawn,  	    {.v = musiccmd } },
	{ Mod4Mask,           		  XK_v,      spawn,  	    {.v = browsercmd } },
	{ Mod4Mask,           		  XK_c,      spawn,  	    {.v = firefoxcmd } },
	{ Mod4Mask,           		  XK_z, 	   spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_q,      cycleStack,     {0} },
	{ MODKEY,                       XK_Tab,    cycleView,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,    cycleView,      {.i = -1 } },
	{ ControlMask|ShiftMask,        XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

