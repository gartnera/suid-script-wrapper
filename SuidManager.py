import os

class SuidManager:
    def __init__(self):
        self.euid = os.geteuid()
        self.uid = os.getuid()

    def dropPerms(self):
        os.seteuid(os.getuid())

    def resumePerms(self):
        os.setuid(self.euid)
