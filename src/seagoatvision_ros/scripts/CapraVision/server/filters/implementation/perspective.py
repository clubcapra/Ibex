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

import cv2
import numpy as np
from CapraVision.server.filters.parameter import  Parameter


class Perspective:
    """Wrap perspective"""
    def __init__(self):
        #self.topleftx = Parameter("Top Left X",0,640,0)
        #self.toplefty = Parameter("Top Left TY",0,480,0)
        #self.bottomleftx = Parameter("Bottom Left X",0,640,100)
        #self.bottomlefty = Parameter("Bottom Left Y",0,480,480)
        #self.toprightx = Parameter("Top Right X",0,640,640)
        #self.toprighty = Parameter("Top Right Y",0,480,0)
        #self.bottomrightx = Parameter("Bottom Right X",0,640,540)
        #self.bottomrighty = Parameter("Bottom Right Y",0,480,480)
        
        self.topleftx = Parameter("Top Left X",-1292,1292,-200)
        self.toplefty = Parameter("Top Left TY",-734,734,0)
        self.bottomleftx = Parameter("Bottom Left X",0,1292,202)
        self.bottomlefty = Parameter("Bottom Left Y",0,734,734)
        self.toprightx = Parameter("Top Right X",0,1292,1292)
        self.toprighty = Parameter("Top Right Y",0,734,0)
        self.bottomrightx = Parameter("Bottom Right X",0,1292,1090)
        self.bottomrighty = Parameter("Bottom Right Y",0,734,734)
        
        self.mmat = None
        self.configure()
        
    def configure(self):
        c1 = np.array([[self.topleftx.get_current_value(), self.toplefty.get_current_value()], 
                       [self.bottomleftx.get_current_value(), self.bottomlefty.get_current_value()], 
                       [self.toprightx.get_current_value(), self.toprighty.get_current_value()], 
                       [self.bottomrightx.get_current_value(), self.bottomrighty.get_current_value()]], 
                      np.float32)
        #c2 = np.array([[0, 0], [0, 480], [640, 0], [640, 480]], np.float32)
        c2 = np.array([[0, 0], [0, 734], [1292, 0], [1292, 734]], np.float32)
        self.mmat = cv2.getPerspectiveTransform(c2, c1)
        
    def execute(self, image):
        height, width, channels = image.shape
        return cv2.warpPerspective(image, self.mmat, (width, height))
