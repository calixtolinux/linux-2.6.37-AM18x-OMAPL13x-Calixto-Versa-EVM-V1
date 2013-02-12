########################  CALIXTO-AM18x-OMAPL13x-EVM BASIC CONFIGURATION #######################

After Downloading the Kernel from GIT,

1> Setuping the Compiler Path
  
Eg:
     -> cp compiler.tar.gz /opt
     -> tar -xvf compiler.tar.gz
     -> edit ~/.bashrc Add the Following Line at end
     -> export PATH=/opt/compiler-path/bin:$PATH
     -> export ARCH=arm
     -> export CROSS_COMPILE=arm-arago-linux-gnueabi-
     -> save & Exit
     -> source ~/.bashrc

2> Compiling Kernel at first time

Eg:
     -> Get into linux-2.6.37-AM18x-OMAPL13x-Calixto-Versa-EVM-V1/
     -> make distclean
     -> make calixto_evm_defconfig
     -> make uImage


3> Calixto Pheripheral Configuration
   
    -> make menuconfig
       -> System Type
          -> TI Davinci Implimentation
             -> [*] Calixto-EVM Pheripheral Configuration
                    ->    Calixto-EVM Display Support (Enable Different LCD Size Configuration Eg: 4.7inch, VGA Mode)

-> Any More Quires Email @: support@calixto.co.in
-> More Product Details Log on to :www.calixto.co.in
