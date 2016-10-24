#!/usr/bin/python3
import threading
import time

exitFlag = 0

class myThread (threading.Thread):
    def __init__(self, threadID, name, counter):
        self.threadID = threadID
        self.name = name
        self.counter = counter

    def run(self):
        print "Starting {}".format(self.name)
        print_time(self.name, self.counter, 5)
        print "Exiting {}".format(self.name)

def print_time(threadName, delay, counter):
    while counter:
        if exitFlag:
            threadName.exit()
        time.sleep(delay)
        print "{}: {}".format(threadName, time.ctime(time.time()))

thread1 = mmyThread(1, "Thread-1", 1)
thread2 = mmyThread(2, "Thread-2", 2)

thread1.start()
thread2.start()

print "Exiting main thread"