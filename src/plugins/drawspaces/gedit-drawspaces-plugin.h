/* 
 * Copyright (C) 2008 Ignacio Casal Quinteiro <nacho.resa@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * $Id: gedit-drawspaces-plugin.h 137 2006-04-23 15:13:27Z sfre $
 */

#ifndef __GEDIT_DRAWSPACES_PLUGIN_H__
#define __GEDIT_DRAWSPACES_PLUGIN_H__

#include <glib.h>
#include <glib-object.h>
#include <gedit/gedit-plugin.h>

G_BEGIN_DECLS

/*
 * Type checking and casting macros
 */
#define GEDIT_TYPE_DRAWSPACES_PLUGIN		(gedit_drawspaces_plugin_get_type ())
#define GEDIT_DRAWSPACES_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), GEDIT_TYPE_DRAWSPACES_PLUGIN, GeditDrawspacesPlugin))
#define GEDIT_DRAWSPACES_PLUGIN_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), GEDIT_TYPE_DRAWSPACES_PLUGIN, GeditDrawspacesPluginClass))
#define GEDIT_IS_DRAWSPACES_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), GEDIT_TYPE_DRAWSPACES_PLUGIN))
#define GEDIT_IS_DRAWSPACES_PLUGIN_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), GEDIT_TYPE_DRAWSPACES_PLUGIN))
#define GEDIT_DRAWSPACES_PLUGIN_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), GEDIT_TYPE_DRAWSPACES_PLUGIN, GeditDrawspacesPluginClass))

/* Private structure type */
typedef struct _GeditDrawspacesPluginPrivate	GeditDrawspacesPluginPrivate;

/*
 * Main object structure
 */
typedef struct _GeditDrawspacesPlugin		GeditDrawspacesPlugin;

struct _GeditDrawspacesPlugin
{
	GeditPlugin parent_instance;
	
	/* private */
	GeditDrawspacesPluginPrivate *priv;
};

/*
 * Class definition
 */
typedef struct _GeditDrawspacesPluginClass	GeditDrawspacesPluginClass;

struct _GeditDrawspacesPluginClass
{
	GeditPluginClass parent_class;
};

/*
 * Public methods
 */
GType	gedit_drawspaces_plugin_get_type	(void) G_GNUC_CONST;

/* All the plugins must implement this function */
G_MODULE_EXPORT GType register_gedit_plugin (GTypeModule *module);

G_END_DECLS

#endif /* __GEDIT_DRAWSPACES_PLUGIN_H__ */
