
from CapraVision.server.filters.dataextract import DataExtractor

class ServerTest(DataExtractor):
    """Send a example line"""
    
    def __init__(self):
        DataExtractor.__init__(self)
    
    def execute(self, image):
        self.notify_output_observers("LineOrientation: x1=0 y1=0 x2=100 y2=100 \n")
        self.notify_output_observers("LineOrientation: \n")
        return image