from pushbullet import Pushbullet

#token patrick
pb = Pushbullet("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
#set device samsung patrick
dev = pb.get_device("Samsung SM-A528B")
#send push notif
push = dev.push_note("Intruder alert!!!")