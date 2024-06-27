print("Starting the communication with device")
with open("/proc/aditya", "w") as driver:
    print("Driver is Open")
    driver.write("hello\n")
    print("Hello is written")

print("file closed")


