cmd_arch/arm/boot/uImage := /bin/bash /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/scripts/mkuboot.sh -A arm -O linux -T kernel -C none -a 0xc0008000 -e 0xc0008000 -n 'Linux-2.6.37+' -d arch/arm/boot/zImage arch/arm/boot/uImage
