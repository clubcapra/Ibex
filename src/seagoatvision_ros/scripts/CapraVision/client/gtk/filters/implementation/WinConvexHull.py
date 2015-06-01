#! /usr/bin/env python

#    Copyright (C) 2012  Club Capra - capra.etsmtl.ca
#
#    This file is part of CapraVision.
#    
#    CapraVision is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

import copy

from gi.repository import Gtk

from CapraVision.client.gtk import get_ui
from CapraVision.client.gtk import win_name

class WinConvexHull:
    
    def __init__(self, filtre, cb):
        self.filtre = filtre
        self.filtre_init = copy.copy(filtre)
        self.cb = cb
        
        ui = get_ui(self)
        self.window = ui.get_object(win_name(self))
        self.spnMin = ui.get_object('spnMin')
        self.spnMin.set_adjustment(self.create_adj())
        self.spnMax = ui.get_object('spnMax')
        self.spnMax.set_adjustment(self.create_adj())
        
        self.init_window()
        
    def init_window(self):
        self.spnMin.set_value(self.filtre_init.area_min.get_current_value())
        self.spnMax.set_value(self.filtre_init.area_max.get_current_value())
    
    def create_adj(self):
        return Gtk.Adjustment(1, 1, 65535, 1, 10, 0)

    def on_btnCancel_clicked(self, widget):
        self.filtre.area_min = self.filtre_init.area_min
        self.filtre.area_max = self.filtre_init.area_max
        self.init_window()
    
    def on_btnOK_clicked(self, widget):
        self.cb()
        self.window.destroy()
    
    def on_spnMin_value_changed(self, widget):
        self.filtre.area_min.set_current_value(self.spnMin.get_value())
    
    def on_spnMax_value_changed(self, widget):
        self.filtre.area_max.set_current_value(self.spnMax.get_value())
    