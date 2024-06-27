savedcmd_/home/ubuntu/ldd/ldd.mod := printf '%s\n'   ldd.o | awk '!x[$$0]++ { print("/home/ubuntu/ldd/"$$0) }' > /home/ubuntu/ldd/ldd.mod
