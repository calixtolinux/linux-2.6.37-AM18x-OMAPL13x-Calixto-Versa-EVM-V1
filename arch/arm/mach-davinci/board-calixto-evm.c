/*
 * CALIXTO DA850/OMAP-L138 EVM board
 *
 * Copyright (C) 2012 Calixto Systems Pvt Ltd - http://www.calixto.co.in/
 *
 * Derived from: arch/arm/mach-davinci/board-da850-evm.c
 * Modified by Jithin Shyam
 *
 * Original Copyrights follow:
 *
 * 2007, 2009 (c) MontaVista Software, Inc. This file is licensed under
 * the terms of the GNU General Public License version 2. This program
 * is licensed "as is" without any warranty of any kind, whether express
 * or implied.
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/console.h>
#include <linux/i2c.h>
#include <linux/i2c/at24.h>
#include <linux/i2c/pca953x.h>
#include <linux/input.h>
#include <linux/mfd/tps6507x.h>
#include <linux/gpio.h>
#include <linux/gpio_keys.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/partitions.h>
#include <linux/regulator/machine.h>
#include <linux/regulator/tps6507x.h>
#include <linux/input/tps6507x-ts.h>
#include <linux/spi/spi.h>
#include <linux/spi/flash.h>
#include <linux/delay.h>
#include <linux/i2c-gpio.h>
#include <linux/pwm_backlight.h>
#include <linux/wl12xx.h>

#include <asm/mach-types.h>
#include <asm/mach/arch.h>

#include <mach/cp_intc.h>
#include <mach/da8xx.h>
#include <mach/nand.h>
#include <mach/mux.h>
#include <mach/aemif.h>
#include <mach/spi.h>
#include <mach/flash.h>
#include <mach/usb.h>
#include <mach/vpif.h>
#include <media/davinci/videohd.h>

#include <media/tvp514x.h>

#define DA850_EVM_PHY_ID                "0:00"

#define DA850_MMCSD_CD_PIN              GPIO_TO_PIN(0, 13)

#define DA850_WLAN_EN                   GPIO_TO_PIN(6, 9)
#define DA850_WLAN_IRQ                  GPIO_TO_PIN(6, 10)

/* Enabling GPIO for WL1271's Bluetooth */
#define WL1271_BT_EN_GPIO GPIO_TO_PIN(0, 15)

/* Enabling GPIOs for WL1271's BT, FM, GPS respectively (-1 if not used) */
/*static int gpios[] = { WL1271_BT_EN_GPIO, -1, -1};*/

/*static struct platform_device wl1271_device = {
       .name           = "kim",
       .id             = -1,
       .dev.platform_data = &gpios,
};*/

static struct davinci_spi_platform_data da850evm_spi1_pdata = {
	.version	= SPI_VERSION_2,
	.num_chipselect = 1,
	.intr_line      = 1,
};

static struct mtd_partition da850evm_spiflash_part[] = {
	[0] = {
		.name = "UBL",
		.offset = 0,
		.size = SZ_64K,
		.mask_flags = MTD_WRITEABLE,
	},
	[1] = {
		.name = "U-Boot",
		.offset = MTDPART_OFS_APPEND,
		.size = SZ_512K,
		.mask_flags = MTD_WRITEABLE,
	},
	[2] = {
		.name = "U-Boot-Env",
		.offset = MTDPART_OFS_APPEND,
		.size = SZ_64K,
		.mask_flags = MTD_WRITEABLE,
	},
	[3] = {
		.name = "MAC-Address",
		.offset = SZ_2M - SZ_64K,
		.size = SZ_64K,
		.mask_flags = MTD_WRITEABLE,
	},
};

static struct flash_platform_data da850evm_spiflash_data = {
	.name		= "m25p80",
	.parts		= da850evm_spiflash_part,
	.nr_parts	= ARRAY_SIZE(da850evm_spiflash_part),
};

static struct davinci_spi_config da850evm_spiflash_cfg = {
	.io_type	= SPI_IO_TYPE_DMA,
	.c2tdelay	= 8,
	.t2cdelay	= 8,
};

static struct spi_board_info da850evm_spi_info[] = {
	{
		.modalias		= "m25p80",
		.platform_data		= &da850evm_spiflash_data,
		.controller_data	= &da850evm_spiflash_cfg,
		.mode			= SPI_MODE_0,
		.max_speed_hz		= 30000000,
		.bus_num		= 1,
		.chip_select		= 0,
	},
};

static void m25p80_notify_add(struct mtd_info *mtd)
{
	char *mac_addr = davinci_soc_info.emac_pdata->mac_addr;
	size_t retlen;

	if (!strcmp(mtd->name, "MAC-Address")) {
		mtd->read(mtd, 0, ETH_ALEN, &retlen, mac_addr);
		if (retlen == ETH_ALEN)
			pr_info("Read MAC addr from SPI Flash: %pM\n",
					mac_addr);
	}
}

static struct mtd_notifier spi_notifier = {
	.add    = m25p80_notify_add,
};

static void __init da850evm_init_spi1(struct spi_board_info *info, unsigned len)
{
	int ret;

	ret = spi_register_board_info(info, len);
	if (ret)
		pr_warning("failed to register board info : %d\n", ret);

	ret = da8xx_register_spi(1, &da850evm_spi1_pdata);
	if (ret)
		pr_warning("failed to register spi 1 device : %d\n", ret);

		register_mtd_user(&spi_notifier);
}

#define TVP5147_CH0		"tvp514x-0"
#define TVP5147_CH1		"tvp514x-1"

#define VPIF_STATUS	(0x002C)
#define VPIF_STATUS_CLR	(0x0030)


static struct davinci_pm_config da850_pm_pdata = {
	.sleepcount = 128,
};

static struct platform_device da850_pm_device = {
	.name           = "pm-davinci",
	.dev = {
		.platform_data	= &da850_pm_pdata,
	},
	.id             = -1,
};

/* DA850/OMAP-L138 EVM includes a 512 MByte large-page NAND flash
 * (128K blocks). It may be used instead of the (default) SPI flash
 * to boot, using TI's tools to install the secondary boot loader
 * (UBL) and U-Boot.
 */
static struct mtd_partition da850_evm_nandflash_partition[] = {
	{
		.name		= "kernel",
		.offset		= 0x20000,
		.size		= SZ_8M,
		.mask_flags	= 0,
	},
	{
		.name		= "filesystem",
		.offset		= MTDPART_OFS_APPEND,
		.size		= MTDPART_SIZ_FULL,
		.mask_flags	= 0,
	},
};

static struct davinci_aemif_timing da850_evm_nandflash_timing = {
	.wsetup		= 24,
	.wstrobe	= 21,
	.whold		= 14,
	.rsetup		= 19,
	.rstrobe	= 50,
	.rhold		= 0,
	.ta		= 20,
};

static struct davinci_nand_pdata da850_evm_nandflash_data = {
	.parts		= da850_evm_nandflash_partition,
	.nr_parts	= ARRAY_SIZE(da850_evm_nandflash_partition),
	.ecc_mode	= NAND_ECC_HW,
	.ecc_bits	= 4,
	.options	= NAND_USE_FLASH_BBT,
	.timing		= &da850_evm_nandflash_timing,
};

static struct resource da850_evm_nandflash_resource[] = {
 {
                .start  = DA8XX_AEMIF_CS3_BASE,
                .end    = DA8XX_AEMIF_CS3_BASE + SZ_512K + 2 * SZ_1K - 1,
                .flags  = IORESOURCE_MEM,
        },
        {
                .start  = DA8XX_AEMIF_CTL_BASE,
                .end    = DA8XX_AEMIF_CTL_BASE + SZ_32K - 1,
                .flags  = IORESOURCE_MEM,
        },

};

static struct platform_device da850_evm_nandflash_device = {
	.name		= "davinci_nand",
	.id		= 1,
	.dev		= {
	.platform_data	= &da850_evm_nandflash_data,
	},
	.num_resources	= ARRAY_SIZE(da850_evm_nandflash_resource),
	.resource	= da850_evm_nandflash_resource,
};

static struct platform_device *da850_evm_devices[] __initdata = {
	&da850_evm_nandflash_device,
};

static const short da850_evm_nand_pins[] = {
	DA850_EMA_D_0, DA850_EMA_D_1, DA850_EMA_D_2, DA850_EMA_D_3,
	DA850_EMA_D_4, DA850_EMA_D_5, DA850_EMA_D_6, DA850_EMA_D_7,
	DA850_EMA_A_1, DA850_EMA_A_2, DA850_NEMA_CS_3,
	DA850_NEMA_WE, DA850_NEMA_OE, DA850_EMA_WAIT_0, 
	-1
};

#if defined(CONFIG_MMC_DAVINCI) || \
    defined(CONFIG_MMC_DAVINCI_MODULE)
#define HAS_MMC 1
#else
#define HAS_MMC 0
#endif

/* have_imager() - Check if we have support for imager interface */
static inline int have_imager(void)
{
#if defined(CONFIG_DA850_UI_CAMERA)
	return 1;
#else
	return 0;
#endif
}

/* NAND configuration  */
static inline void da850_evm_setup_nand(void)
{
    int ret = 0;

        ret = davinci_cfg_reg_list(da850_evm_nand_pins);
            if (ret)
               pr_warning("da850_evm_init: nand mux setup failed: "
                         "%d\n", ret);

        platform_add_devices(da850_evm_devices,
                                        ARRAY_SIZE(da850_evm_devices));
}

#ifdef CONFIG_DA850_UI_RMII
static inline void da850_evm_setup_emac_rmii(int rmii_sel)
{
	struct davinci_soc_info *soc_info = &davinci_soc_info;
       
        soc_info->emac_pdata->rmii_en = 1;

        }
#else

static inline void da850_evm_setup_emac_rmii(int rmii_sel) { }
#endif

/*
 * USB1 VBUS is controlled by GPIO2[4], over-current is reported on GPIO6[13].
 */
#define ON_BD_USB_DRV	GPIO_TO_PIN(2, 4)
#define ON_BD_USB_OVC	GPIO_TO_PIN(6, 13)

static const short da850_evm_usb11_pins[] = {
	DA850_GPIO2_4, DA850_GPIO6_13,
	-1
};

static da8xx_ocic_handler_t da850_evm_usb_ocic_handler;

static int da850_evm_usb_set_power(unsigned port, int on)
{
	gpio_set_value(ON_BD_USB_DRV, on);
	return 0;
}

static int da850_evm_usb_get_power(unsigned port)
{
	return gpio_get_value(ON_BD_USB_DRV);
}

static int da850_evm_usb_get_oci(unsigned port)
{
	return !gpio_get_value(ON_BD_USB_OVC);
}

static irqreturn_t da850_evm_usb_ocic_irq(int, void *);

static int da850_evm_usb_ocic_notify(da8xx_ocic_handler_t handler)
{
	int irq		= gpio_to_irq(ON_BD_USB_OVC);
	int error	= 0;

	if (handler != NULL) {
		da850_evm_usb_ocic_handler = handler;

		error = request_irq(irq, da850_evm_usb_ocic_irq, IRQF_DISABLED |
				    IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
				    "OHCI over-current indicator", NULL);
		if (error)
			printk(KERN_ERR "%s: could not request IRQ to watch "
			       "over-current indicator changes\n", __func__);
	} else
		free_irq(irq, NULL);

	return error;
}

static struct da8xx_ohci_root_hub da850_evm_usb11_pdata = {
	.set_power	= da850_evm_usb_set_power,
	.get_power	= da850_evm_usb_get_power,
	.get_oci	= da850_evm_usb_get_oci,
	.ocic_notify	= da850_evm_usb_ocic_notify,

	/* TPS2065 switch @ 5V */
	.potpgt		= (3 + 1) / 2,	/* 3 ms max */
};

static irqreturn_t da850_evm_usb_ocic_irq(int irq, void *dev_id)
{
	da850_evm_usb_ocic_handler(&da850_evm_usb11_pdata, 1);
	return IRQ_HANDLED;
}

static __init void da850_evm_usb_init(void)
{
	u32 cfgchip2;
	int ret;

	/*
	 * Set up USB clock/mode in the CFGCHIP2 register.
	 * FYI:  CFGCHIP2 is 0x0000ef00 initially.
	 */
	cfgchip2 = __raw_readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));

	/* USB2.0 PHY reference clock is 24 MHz */
	cfgchip2 &= ~CFGCHIP2_REFFREQ;
	cfgchip2 |=  CFGCHIP2_REFFREQ_24MHZ;

	/*
	 * Select internal reference clock for USB 2.0 PHY
	 * and use it as a clock source for USB 1.1 PHY
	 * (this is the default setting anyway).
	 */
	cfgchip2 &= ~CFGCHIP2_USB1PHYCLKMUX;
	cfgchip2 |=  CFGCHIP2_USB2PHYCLKMUX;

	/*
	 * We have to override VBUS/ID signals when MUSB is configured into the
	 * host-only mode -- ID pin will float if no cable is connected, so the
	 * controller won't be able to drive VBUS thinking that it's a B-device.
	 * Otherwise, we want to use the OTG mode and enable VBUS comparators.
	 */
	cfgchip2 &= ~CFGCHIP2_OTGMODE;
#ifdef	CONFIG_USB_MUSB_HOST
	cfgchip2 |=  CFGCHIP2_FORCE_HOST;
#else
	cfgchip2 |=  CFGCHIP2_SESENDEN | CFGCHIP2_VBDTCTEN;
#endif

	__raw_writel(cfgchip2, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));

	/*
	 * TPS2065 switch @ 5V supplies 1 A (sustains 1.5 A),
	 * with the power on to power good time of 3 ms.
	 */

             
	ret = da8xx_register_usb20(1000, 3);
	if (ret)
		pr_warning("%s: USB 2.0 registration failed: %d\n",
			   __func__, ret);

	ret = davinci_cfg_reg_list(da850_evm_usb11_pins);
	if (ret) {
		pr_warning("%s: USB 1.1 PinMux setup failed: %d\n",
			   __func__, ret);
		return;
	}

	ret = gpio_request(ON_BD_USB_DRV, "ON_BD_USB_DRV");
	if (ret) {
		printk(KERN_ERR "%s: failed to request GPIO for USB 1.1 port "
		       "power control: %d\n", __func__, ret);
		return;
	}
	gpio_direction_output(ON_BD_USB_DRV, 0);

	ret = gpio_request(ON_BD_USB_OVC, "ON_BD_USB_OVC");
	if (ret) {
		printk(KERN_ERR "%s: failed to request GPIO for USB 1.1 port "
		       "over-current indicator: %d\n", __func__, ret);
		return;
	}
	gpio_direction_input(ON_BD_USB_OVC);

	ret = da8xx_register_usb11(&da850_evm_usb11_pdata);
	if (ret)
		pr_warning("%s: USB 1.1 registration failed: %d\n",
			   __func__, ret);
}

static struct davinci_uart_config da850_evm_uart_config __initdata = {
	.enabled_uarts = 0x7,
};

/* davinci da850 evm audio machine driver */
static u8 da850_iis_serializer_direction[] = {
      INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE,
      INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE,
      INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE, INACTIVE_MODE,
      INACTIVE_MODE, TX_MODE,       RX_MODE,       INACTIVE_MODE,
};

static struct snd_platform_data da850_evm_snd_data = {
	.tx_dma_offset	= 0x2000,
	.rx_dma_offset	= 0x2000,
	.op_mode	= DAVINCI_MCASP_IIS_MODE,
	.num_serializer	= ARRAY_SIZE(da850_iis_serializer_direction),
	.tdm_slots	= 2,
	.serial_dir	= da850_iis_serializer_direction,
	.asp_chan_q	= EVENTQ_1,
	.version	= MCASP_VERSION_2,
	.txnumevt	= 1,
	.rxnumevt	= 1,
};

static int da850_evm_mmc_get_cd(int index)
{
	return !gpio_get_value(DA850_MMCSD_CD_PIN);
}

static int wl12xx_set_power(int slot, int power_on)
{
	static int power_state;

	pr_debug("Powering %s wifi", (power_on ? "on" : "off"));

	if (power_on == power_state)
		return 0;
	power_state = power_on;

	if (power_on) {
		gpio_set_value(DA850_WLAN_EN, 1);
		mdelay(15);
		gpio_set_value(DA850_WLAN_EN, 0);
		mdelay(1);
		gpio_set_value(DA850_WLAN_EN, 1);
		mdelay(70);
	} else {
		gpio_set_value(DA850_WLAN_EN, 0);
	}

	return 0;
}

static struct davinci_mmc_config da850_mmc_config[] = {
	{
		.get_ro		= NULL,
		.get_cd		= da850_evm_mmc_get_cd,
		.wires		= 4,
		.max_freq	= 50000000,
		.caps		= MMC_CAP_MMC_HIGHSPEED | MMC_CAP_SD_HIGHSPEED,
		.version	= MMC_CTLR_VERSION_2,
	},
	{
		.get_ro		= NULL,
		.get_cd		= NULL,
		.set_power	= wl12xx_set_power,
		.wires		= 4,
		.max_freq	= 25000000,
		.caps		= MMC_CAP_4_BIT_DATA | MMC_CAP_NONREMOVABLE |
				  MMC_CAP_POWER_OFF_CARD,
		.version	= MMC_CTLR_VERSION_2,
	},
	{}	/* Terminator */
};

static int da850_lcd_hw_init(void)
{
	void __iomem *cfg_mstpri2_base;
	u32 val;

	/*
	 * Reconfigure the LCDC priority to the highest to ensure that
	 * the throughput/latency requirements for the LCDC are met.
	 */
	cfg_mstpri2_base = DA8XX_SYSCFG0_VIRT(DA8XX_MSTPRI2_REG);

	val = __raw_readl(cfg_mstpri2_base);
	val &= 0x0fffffff;
	__raw_writel(val, cfg_mstpri2_base);

	return 0;
}

static struct i2c_board_info __initdata da850_evm_i2c_devices[] = {
        {
                I2C_BOARD_INFO("tlv320aic3x", 0x18),
        },
};

static const short da850_evm_mii_pins[] = {
	DA850_MII_TXEN, DA850_MII_TXCLK, DA850_MII_COL, DA850_MII_TXD_3,
	DA850_MII_TXD_2, DA850_MII_TXD_1, DA850_MII_TXD_0, DA850_MII_RXER,
	DA850_MII_CRS, DA850_MII_RXCLK, DA850_MII_RXDV, DA850_MII_RXD_3,
	DA850_MII_RXD_2, DA850_MII_RXD_1, DA850_MII_RXD_0, DA850_MDIO_CLK,
	DA850_MDIO_D,
	-1
};

static const short da850_evm_rmii_pins[] = {
	DA850_RMII_TXD_0, DA850_RMII_TXD_1, DA850_RMII_TXEN,
	DA850_RMII_CRS_DV, DA850_RMII_RXD_0, DA850_RMII_RXD_1,
	DA850_RMII_RXER, DA850_RMII_MHZ_50_CLK, DA850_MDIO_CLK,
	DA850_MDIO_D,
	-1
};

static int __init da850_evm_config_emac(void)
{
	void __iomem *cfg_chip3_base;
	int ret;
	u32 val;
	struct davinci_soc_info *soc_info = &davinci_soc_info;
	u8 rmii_en = soc_info->emac_pdata->rmii_en;

	if (!machine_is_davinci_da850_evm())
		return 0;

	cfg_chip3_base = DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG);

	val = __raw_readl(cfg_chip3_base);

	if (rmii_en) {
		val |= BIT(8);
		ret = davinci_cfg_reg_list(da850_evm_rmii_pins);
		pr_info("EMAC: RMII PHY configured, MII PHY will not be"
							" functional\n");
	} else {
		val &= ~BIT(8);
		ret = davinci_cfg_reg_list(da850_evm_mii_pins);
		pr_info("EMAC: MII PHY configured, RMII PHY will not be"
							" functional\n");
	}

	if (ret)
		pr_warning("da850_evm_init: cpgmac/rmii mux setup failed: %d\n",
				ret);

	/* configure the CFGCHIP3 register for RMII or MII */
	__raw_writel(val, cfg_chip3_base);

	/* Enable/Disable MII MDIO clock */
        soc_info->emac_pdata->phy_id = DA850_EVM_PHY_ID;

        ret = da8xx_register_emac();
        if (ret)
                pr_warning("da850_evm_init: emac registration failed: %d\n",
                                ret);

        return 0;

}
device_initcall(da850_evm_config_emac);

static const struct vpif_input da850_ch2_inputs[] = {
		{
		.input = {
			.index = 0,
			.name = "Camera",
			.type = V4L2_INPUT_TYPE_CAMERA,
			.std = V4L2_STD_BAYER_ALL
		},
		.subdev_name = "mt9t031",
	},
};

/*
 * The following EDMA channels/slots are not being used by drivers (for
 * example: Timer, GPIO, UART events etc) on da850/omap-l138 EVM, hence
 * they are being reserved for codecs on the DSP side.
 */
static const s16 da850_dma0_rsv_chans[][2] = {
	/* (offset, number) */
	{ 8,  6},
	{24,  4},
	{30,  2},
	{-1, -1}
};

static const s16 da850_dma0_rsv_slots[][2] = {
	/* (offset, number) */
	{ 8,  6},
	{24,  4},
	{30, 50},
	{-1, -1}
};

static const s16 da850_dma1_rsv_chans[][2] = {
	/* (offset, number) */
	{ 0, 28},
	{30,  2},
	{-1, -1}
};

static const s16 da850_dma1_rsv_slots[][2] = {
	/* (offset, number) */
	{ 0, 28},
	{30, 90},
	{-1, -1}
};

static struct edma_rsv_info da850_edma_cc0_rsv = {
	.rsv_chans	= da850_dma0_rsv_chans,
	.rsv_slots	= da850_dma0_rsv_slots,
};

static struct edma_rsv_info da850_edma_cc1_rsv = {
	.rsv_chans	= da850_dma1_rsv_chans,
	.rsv_slots	= da850_dma1_rsv_slots,
};

static struct edma_rsv_info *da850_edma_rsv[2] = {
	&da850_edma_cc0_rsv,
	&da850_edma_cc1_rsv,
};

#ifdef CONFIG_CPU_FREQ
static __init int da850_evm_init_cpufreq(void)
{
#if 0
	switch (system_rev & 0xF) {
	case 3:
		da850_max_speed = 456000;
		break;
	case 2:
		da850_max_speed = 408000;
		break;
	case 1:
		da850_max_speed = 372000;
		break;
	}
#endif
        da850_max_speed = 372000;

	return da850_register_cpufreq("pll0_sysclk3");
}
#else
static __init int da850_evm_init_cpufreq(void) { return 0; }
#endif

static struct i2c_gpio_platform_data da850_gpio_i2c_pdata = {
	.sda_pin	= GPIO_TO_PIN(1, 4),
	.scl_pin	= GPIO_TO_PIN(1, 5),
	.udelay		= 2,			/* 250 KHz */
};

static struct platform_device da850_gpio_i2c = {
	.name		= "i2c-gpio",
	.id		= 1,
	.dev		= {
	.platform_data	= &da850_gpio_i2c_pdata,
	},
};

#if defined(CONFIG_DA850_UI_SD_VIDEO_PORT)
/* VPIF capture configuration */
static struct tvp514x_platform_data tvp5146_pdata = {
	.clk_polarity = 0,
	.hs_polarity = 1,
	.vs_polarity = 1
};
#endif

#if defined(CONFIG_TI_DAVINCI_EMAC) || \
	defined(CONFIG_TI_DAVINCI_EMAC_MODULE)
#define HAS_EMAC 1
#else
#define HAS_EMAC 0
#endif

#if defined(CONFIG_SND_DA850_SOC_EVM) || \
	defined(CONFIG_SND_DA850_SOC_EVM_MODULE)
#define HAS_MCASP 1
#else
#define HAS_MCASP 0
#endif

#if defined(CONFIG_DA850_UI_RMII) && (HAS_EMAC)
#define HAS_RMII 1
#else
#define HAS_RMII 0
#endif

#define DA850EVM_SATA_REFCLKPN_RATE	(25 * 1000 * 1000)

#if defined(CONFIG_SPI_DAVINCI)
#define HAS_SPI 1
#else
#define HAS_SPI 0
#endif

#if defined(CONFIG_FB_DA8XX)
#define HAS_LCD	1
#else
#define HAS_LCD	0
#endif

#ifdef CONFIG_DA850_MISTRAL_WL12XX

static struct wl12xx_platform_data da850_wl12xx_wlan_data __initdata = {
	.irq = -1,
	.board_ref_clock = CONFIG_DA850_MISTRAL_WL12XX_REFCLOCK,
	.platform_quirks = WL12XX_PLATFORM_QUIRK_EDGE_IRQ,
};

static void da850_wl12xx_set_platform_data(void)
{
	da850_wl12xx_wlan_data.irq = gpio_to_irq(DA850_WLAN_IRQ);
	if (wl12xx_set_platform_data(&da850_wl12xx_wlan_data))
		pr_err("Error setting wl12xx data\n");
}

#else

static void da850_wl12xx_set_platform_data(void) { }

#endif

static void da850_wl12xx_init(void)
{
	if (gpio_request(DA850_WLAN_EN, "wl12xx") ||
	    gpio_direction_output(DA850_WLAN_EN, 0))
		pr_err("Error initializing the wl12xx enable gpio\n");

	if (gpio_request(DA850_WLAN_IRQ, "wl12xx_irq") ||
	    gpio_direction_input(DA850_WLAN_IRQ))
		pr_err("Error initializing the wl12xx irq gpio\n");
	if (gpio_request(WL1271_BT_EN_GPIO, "wl1271 BT Enable") ||
	    gpio_direction_output(WL1271_BT_EN_GPIO,0))
		pr_err("Failed to request BT_EN GPIO\n");

	da850_wl12xx_set_platform_data();
}

static __init void da850_evm_init(void)
{
	int ret;
        u8 rmii_en;

	struct davinci_soc_info *soc_info = &davinci_soc_info;
        
          rmii_en = soc_info->emac_pdata->rmii_en;
          soc_info->emac_pdata->rmii_en = 1;	
	
        ret = da850_register_edma(da850_edma_rsv);
	if (ret)
		pr_warning("da850_evm_init: edma registration failed: %d\n",
			ret);

	ret = davinci_cfg_reg_list(da850_i2c0_pins);
	if (ret)
		pr_warning("da850_evm_init: i2c0 mux setup failed: %d\n",
				ret);

	platform_device_register(&da850_gpio_i2c);

	/* Register PRUSS device */
	da8xx_register_pruss();

	ret = da8xx_register_watchdog();
	if (ret)
		pr_warning("da830_evm_init: watchdog registration failed: %d\n",
				ret);

	/* Support for UART 1 */
	ret = davinci_cfg_reg_list(da850_uart1_pins);
	if (ret)
		pr_warning("da850_evm_init: UART 1 mux setup failed:"
						" %d\n", ret);

	/* Support for UART0 */
        ret = davinci_cfg_reg_list(da850_uart0_pins);
        if (ret)
                pr_warning("da850_evm_init: UART0 mux setup failed:"
                                                " %d\n", ret);
        
        /* Support for SATA */        
        ret = da850_register_sata(DA850EVM_SATA_REFCLKPN_RATE);
	if (ret)
		pr_warning("da850_evm_init: sata registration failed: %d\n",
				ret);

	/*Support for MMC */
        if (HAS_MMC) {
		ret = davinci_cfg_reg_list(da850_mmcsd0_pins);
		if (ret)
			pr_warning("da850_evm_init: mmcsd0 mux setup failed:"
					" %d\n", ret);

		ret = gpio_request(DA850_MMCSD_CD_PIN, "MMC CD\n");
		if (ret)
			pr_warning("da850_evm_init: can not open GPIO %d\n",
					DA850_MMCSD_CD_PIN);
		gpio_direction_input(DA850_MMCSD_CD_PIN);

		ret = da8xx_register_mmcsd0(&da850_mmc_config[0]);
		if (ret)
			pr_warning("da850_evm_init: mmcsd0 registration failed:"
					" %d\n", ret);
		//da850_wl12xx_init();
	}

	/*Support for Davinci Serial Ports */
	davinci_serial_init(&da850_evm_uart_config);

	/*Support for i2c interface */
	i2c_register_board_info(1, da850_evm_i2c_devices,
			ARRAY_SIZE(da850_evm_i2c_devices));

	/*
	 * shut down uart 0 and 1; they are not used on the board and
	 * accessing them causes endless "too much work in irq53" messages
	 * with arago fs
	 */
	//__raw_writel(0, IO_ADDRESS(DA8XX_UART0_BASE) + 0x30);

	/* Audio Support for Calixto-EVM */
        ret = davinci_cfg_reg_list(da850_mcasp_pins);
        if (ret)
	      pr_warning("calixto_evm_init: mcasp mux setup failed:"
					"%d\n", ret);
	      
	da8xx_register_mcasp(0, &da850_evm_snd_data);

	ret = davinci_cfg_reg_list(da850_lcdcntl_pins);
	if (ret)
		pr_warning("calixto_evm_init: lcdcntl mux setup failed: %d\n",
				ret);

	ret = da850_lcd_hw_init();
	if (ret)
		pr_warning("calixto_evm_init: lcd initialization failed: %d\n",
				ret);
        
        #ifdef CONFIG_CALIXTO_VGA_SUPPORT
	/* VGA Support */
	ret = da8xx_register_lcdc(&vga_monitor_pdata);
        if (ret)
                pr_warning(KERN_WARNING"calixto_evm_init: VGA registration failed: %d\n", ret);
	#endif
        
	#ifdef CONFIG_CALIXTO_LCD35_SUPPORT
	/* Driver registration for calixto-lcd-evm  */
        ret = da8xx_register_lcdc(&tianma_tm035kdh03_pdata);
        if (ret)
                printk(KERN_WARNING"calixto-evm_da850_evm_init: LCD registration failed: %d\n", ret);
	#endif

	/* Support for RTC */
        ret = da8xx_register_rtc();
	if (ret)
		pr_warning("calixto_evm_init: rtc setup failed: %d\n", ret);

	ret = da850_evm_init_cpufreq();
	if (ret)
		pr_warning("calixto_evm_init: cpufreq registration failed: %d\n",
				ret);

	ret = da8xx_register_cpuidle();
	if (ret)
		pr_warning("calixto_evm_init: cpuidle registration failed: %d\n",
				ret);

	ret = da850_register_pm(&da850_pm_device);
	if (ret)
		pr_warning("calixto_evm_init: suspend registration failed: %d\n",
				ret);
     
	da850evm_init_spi1(da850evm_spi_info, ARRAY_SIZE(da850evm_spi_info));

/* initilaize usb module */ 
	da850_evm_usb_init();

/* Initilaize NAND Flash */
        da850_evm_setup_nand();
 
}

#ifdef CONFIG_SERIAL_8250_CONSOLE
static int __init da850_evm_console_init(void)
{
	if (!machine_is_davinci_da850_evm())
		return 0;

	return add_preferred_console("ttyS", 2, "115200");
}
console_initcall(da850_evm_console_init);
#endif

static void __init da850_evm_map_io(void)
{
	da850_init();
}

MACHINE_START(DAVINCI_DA850_EVM, "DaVinci DA850/OMAP-L138/AM18x EVM")
	.boot_params	= (DA8XX_DDR_BASE + 0x100),
	.map_io		= da850_evm_map_io,
	.init_irq	= cp_intc_init,
	.timer		= &davinci_timer,
	.init_machine	= da850_evm_init,
MACHINE_END
