# -*- coding: utf-8 -*-
#
#  windowhelper.py - commander
#
#  Copyright (C) 2010 - Jesse van den Kieboom
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor,
#  Boston, MA 02110-1301, USA.

from gi.repository import GLib, GObject, Gio, Gtk, Gedit
from entry import Entry
from info import Info
from gpdefs import *

try:
    gettext.bindtextdomain(GETTEXT_PACKAGE, GP_LOCALEDIR)
    _ = lambda s: gettext.dgettext(GETTEXT_PACKAGE, s);
except:
    _ = lambda s: s

class CommanderWindowActivatable(GObject.Object, Gedit.WindowActivatable):

    window = GObject.property(type=Gedit.Window)

    def __init__(self):
        GObject.Object.__init__(self)

    def do_activate(self):
        self._entry = None
        self._view = None

        action = Gio.SimpleAction.new_stateful("commander", None, GLib.Variant.new_boolean(False))
        action.connect('activate', self.activate_toggle)
        action.connect('change-state', self.commander_mode)
        self.window.add_action(action)

    def do_deactivate(self):
        self.window.remove_action("commander")

    def do_update_state(self):
        pass

    def activate_toggle(self, action, parameter):
        state = action.get_state()

        if state.get_boolean() and not self._entry is None:
            self._entry.grab_focus()
            return

        action.change_state(GLib.Variant.new_boolean(not state.get_boolean()))

    def commander_mode(self, action, state):
        view = self.window.get_active_view()

        if not view:
            return False

        active = state.get_boolean()

        if active:
            if not self._entry or view != self._view:
                self._entry = Entry(view)
                self._entry.connect('destroy', self.on_entry_destroy)

            self._entry.grab_focus()
            self._view = view
        elif self._entry:
            self._entry.remove()
            self._view = None

        action.set_state(GLib.Variant.new_boolean(active))

        return True

    def on_entry_destroy(self, widget, user_data=None):
        self._entry = None
        self.window.lookup_action("commander").change_state(GLib.Variant.new_boolean(False))

# vi:ex:ts=4:et
