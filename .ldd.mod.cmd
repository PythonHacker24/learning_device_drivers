savedcmd_/home/ubuntu/learning_device_drivers/ldd.mod := printf '%s\n'   ldd.o | awk '!x[$$0]++ { print("/home/ubuntu/learning_device_drivers/"$$0) }' > /home/ubuntu/learning_device_drivers/ldd.mod
