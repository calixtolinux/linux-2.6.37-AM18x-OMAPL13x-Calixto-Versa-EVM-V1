cmd_arch/arm/mm/proc-arm926.o := arm-arago-linux-gnueabi-gcc -Wp,-MD,arch/arm/mm/.proc-arm926.o.d  -nostdinc -isystem /home/shyam/calixto/ti-sdk-am335x-evm/linux-devkit/bin/../lib/gcc/arm-arago-linux-gnueabi/4.5.3/include -I/home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-davinci/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=5 -march=armv5te -mtune=arm9tdmi -include asm/unified.h -msoft-float        -c -o arch/arm/mm/proc-arm926.o arch/arm/mm/proc-arm926.S

deps_arch/arm/mm/proc-arm926.o := \
  arch/arm/mm/proc-arm926.S \
    $(wildcard include/config/cpu/arm926/cpu/idle.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/cpu/dcache/writethrough.h) \
    $(wildcard include/config/cpu/cache/round/robin.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/linkage.h \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/smp.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/hwcap.h \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/pgtable-hwdef.h \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/pgtable.h \
    $(wildcard include/config/highpte.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
  include/asm-generic/4level-fixup.h \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/proc-fns.h \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm7tdmi.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/cpu/arm720t.h) \
    $(wildcard include/config/cpu/arm740t.h) \
    $(wildcard include/config/cpu/arm9tdmi.h) \
    $(wildcard include/config/cpu/arm920t.h) \
    $(wildcard include/config/cpu/arm922t.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/cpu/arm925t.h) \
    $(wildcard include/config/cpu/arm926t.h) \
    $(wildcard include/config/cpu/arm940t.h) \
    $(wildcard include/config/cpu/arm946e.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/arm1020.h) \
    $(wildcard include/config/cpu/arm1020e.h) \
    $(wildcard include/config/cpu/arm1022.h) \
    $(wildcard include/config/cpu/arm1026.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/mohawk.h) \
    $(wildcard include/config/cpu/v6.h) \
    $(wildcard include/config/cpu/v7.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/zone/dma.h) \
  include/linux/const.h \
  arch/arm/mach-davinci/include/mach/memory.h \
    $(wildcard include/config/arch/davinci/da8xx.h) \
    $(wildcard include/config/arch/davinci/dmx.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v3.h) \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/sparsemem.h) \
  include/asm-generic/getorder.h \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  arch/arm/mach-davinci/include/mach/vmalloc.h \
  arch/arm/mach-davinci/include/mach/hardware.h \
  arch/arm/mm/proc-macros.S \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/asm-offsets.h \
  include/generated/asm-offsets.h \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /home/shyam/calixto/Git_Controlled_Kernel/linux-2.6.37-calixto-versa-evm-v1/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \

arch/arm/mm/proc-arm926.o: $(deps_arch/arm/mm/proc-arm926.o)

$(deps_arch/arm/mm/proc-arm926.o):
