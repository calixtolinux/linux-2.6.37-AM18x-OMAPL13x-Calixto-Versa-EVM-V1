/*
 * Table of the DAVINCI register configurations for the PINMUX combinations
 *
 * Author: Vladimir Barinov, MontaVista Software, Inc. <source@mvista.com>
 *
 * Based on linux/include/asm-arm/arch-omap/mux.h:
 * Copyright (C) 2003 - 2005 Nokia Corporation
 *
 * Written by Tony Lindgren
 *
 * 2007 (c) MontaVista Software, Inc. This file is licensed under
 * the terms of the GNU General Public License version 2. This program
 * is licensed "as is" without any warranty of any kind, whether express
 * or implied.
 *
 * Copyright (C) 2008 Texas Instruments.
 */

#ifndef __INC_MACH_MUX_H
#define __INC_MACH_MUX_H

struct mux_config {
	const char *name;
	const char *mux_reg_name;
	const unsigned char mux_reg;
	const unsigned char mask_offset;
	const unsigned char mask;
	const unsigned char mode;
	bool debug;
};

enum davinci_dm644x_index {
	/* ATA and HDDIR functions */
	DM644X_HDIREN,
	DM644X_ATAEN,
	DM644X_ATAEN_DISABLE,

	/* HPI functions */
	DM644X_HPIEN_DISABLE,

	/* AEAW functions */
	DM644X_AEAW,
	DM644X_AEAW0,
	DM644X_AEAW1,
	DM644X_AEAW2,
	DM644X_AEAW3,
	DM644X_AEAW4,

	/* Memory Stick */
	DM644X_MSTK,

	/* I2C */
	DM644X_I2C,

	/* ASP function */
	DM644X_MCBSP,

	/* UART1 */
	DM644X_UART1,

	/* UART2 */
	DM644X_UART2,

	/* PWM0 */
	DM644X_PWM0,

	/* PWM1 */
	DM644X_PWM1,

	/* PWM2 */
	DM644X_PWM2,

	/* VLYNQ function */
	DM644X_VLYNQEN,
	DM644X_VLSCREN,
	DM644X_VLYNQWD,

	/* EMAC and MDIO function */
	DM644X_EMACEN,

	/* GPIO3V[0:16] pins */
	DM644X_GPIO3V,

	/* GPIO pins */
	DM644X_GPIO0,
	DM644X_GPIO3,
	DM644X_GPIO43_44,
	DM644X_GPIO46_47,

	/* VPBE */
	DM644X_RGB666,

	/* LCD */
	DM644X_LOEEN,
	DM644X_LFLDEN,
};

enum davinci_dm646x_index {
	/* ATA function */
	DM646X_ATAEN,

	/* AUDIO Clock */
	DM646X_AUDCK1,
	DM646X_AUDCK0,

	/* CRGEN Control */
	DM646X_CRGMUX,

	/* VPIF Control */
	DM646X_STSOMUX_DISABLE,
	DM646X_STSIMUX_DISABLE,
	DM646X_PTSOMUX_DISABLE,
	DM646X_PTSIMUX_DISABLE,

	/* TSIF Control */
	DM646X_STSOMUX,
	DM646X_STSIMUX,
	DM646X_PTSOMUX_PARALLEL,
	DM646X_PTSIMUX_PARALLEL,
	DM646X_PTSOMUX_SERIAL,
	DM646X_PTSIMUX_SERIAL,
};

enum davinci_dm355_index {
	/* MMC/SD 0 */
	DM355_MMCSD0,

	/* MMC/SD 1 */
	DM355_SD1_CLK,
	DM355_SD1_CMD,
	DM355_SD1_DATA3,
	DM355_SD1_DATA2,
	DM355_SD1_DATA1,
	DM355_SD1_DATA0,

	/* I2C */
	DM355_I2C_SDA,
	DM355_I2C_SCL,

	/* ASP0 function */
	DM355_MCBSP0_BDX,
	DM355_MCBSP0_X,
	DM355_MCBSP0_BFSX,
	DM355_MCBSP0_BDR,
	DM355_MCBSP0_R,
	DM355_MCBSP0_BFSR,

	/* SPI0 */
	DM355_SPI0_SDI,
	DM355_SPI0_SDENA0,
	DM355_SPI0_SDENA1,

	/* IRQ muxing */
	DM355_INT_EDMA_CC,
	DM355_INT_EDMA_TC0_ERR,
	DM355_INT_EDMA_TC1_ERR,

	/* EDMA event muxing */
	DM355_EVT8_ASP1_TX,
	DM355_EVT9_ASP1_RX,
	DM355_EVT26_MMC0_RX,

	/* Video Out */
	DM355_VOUT_FIELD,
	DM355_VOUT_FIELD_G70,
	DM355_VOUT_HVSYNC,
	DM355_VOUT_COUTL_EN,
	DM355_VOUT_COUTH_EN,

	/* Video In Pin Mux */
	DM355_VIN_PCLK,
	DM355_VIN_CAM_WEN,
	DM355_VIN_CAM_VD,
	DM355_VIN_CAM_HD,
	DM355_VIN_YIN_EN,
	DM355_VIN_CINL_EN,
	DM355_VIN_CINH_EN,
};

enum davinci_dm365_index {
	/* MMC/SD 0 */
	DM365_MMCSD0,

	/* MMC/SD 1 */
	DM365_SD1_CLK,
	DM365_SD1_CMD,
	DM365_SD1_DATA3,
	DM365_SD1_DATA2,
	DM365_SD1_DATA1,
	DM365_SD1_DATA0,

	/* I2C */
	DM365_I2C_SDA,
	DM365_I2C_SCL,

	/* AEMIF */
	DM365_AEMIF_AR_A14,
	DM365_AEMIF_AR_BA0,
	DM365_AEMIF_A3,
	DM365_AEMIF_A7,
	DM365_AEMIF_D15_8,
	DM365_AEMIF_CE0,
	DM365_AEMIF_CE1,
	DM365_AEMIF_WE_OE,

	/* ASP0 function */
	DM365_MCBSP0_BDX,
	DM365_MCBSP0_X,
	DM365_MCBSP0_BFSX,
	DM365_MCBSP0_BDR,
	DM365_MCBSP0_R,
	DM365_MCBSP0_BFSR,

	/* SPI0 */
	DM365_SPI0_SCLK,
	DM365_SPI0_SDI,
	DM365_SPI0_SDO,
	DM365_SPI0_SDENA0,
	DM365_SPI0_SDENA1,

	/* UART */
	DM365_UART0_RXD,
	DM365_UART0_TXD,
	DM365_UART1_RXD,
	DM365_UART1_TXD,
	DM365_UART1_RTS,
	DM365_UART1_CTS,

	/* EMAC */
	DM365_EMAC_TX_EN,
	DM365_EMAC_TX_CLK,
	DM365_EMAC_COL,
	DM365_EMAC_TXD3,
	DM365_EMAC_TXD2,
	DM365_EMAC_TXD1,
	DM365_EMAC_TXD0,
	DM365_EMAC_RXD3,
	DM365_EMAC_RXD2,
	DM365_EMAC_RXD1,
	DM365_EMAC_RXD0,
	DM365_EMAC_RX_CLK,
	DM365_EMAC_RX_DV,
	DM365_EMAC_RX_ER,
	DM365_EMAC_CRS,
	DM365_EMAC_MDIO,
	DM365_EMAC_MDCLK,

	/* Key Scan */
	DM365_KEYSCAN,

	/* PWM */
	DM365_PWM0,
	DM365_PWM0_G23,
	DM365_PWM1,
	DM365_PWM1_G25,
	DM365_PWM2_G87,
	DM365_PWM2_G88,
	DM365_PWM2_G89,
	DM365_PWM2_G90,
	DM365_PWM3_G80,
	DM365_PWM3_G81,
	DM365_PWM3_G85,
	DM365_PWM3_G86,

	/* SPI1 */
	DM365_SPI1_SCLK,
	DM365_SPI1_SDO,
	DM365_SPI1_SDI,
	DM365_SPI1_SDENA0,
	DM365_SPI1_SDENA1,

	/* SPI2 */
	DM365_SPI2_SCLK,
	DM365_SPI2_SDO,
	DM365_SPI2_SDI,
	DM365_SPI2_SDENA0,
	DM365_SPI2_SDENA1,

	/* SPI3 */
	DM365_SPI3_SCLK,
	DM365_SPI3_SDO,
	DM365_SPI3_SDI,
	DM365_SPI3_SDENA0,
	DM365_SPI3_SDENA1,

	/* SPI4 */
	DM365_SPI4_SCLK,
	DM365_SPI4_SDO,
	DM365_SPI4_SDI,
	DM365_SPI4_SDENA0,
	DM365_SPI4_SDENA1,

	/* Clock */
	DM365_CLKOUT0,
	DM365_CLKOUT1,
	DM365_CLKOUT2,

	/* GPIO */
	DM365_GPIO20,
	DM365_GPIO30,
	DM365_GPIO31,
	DM365_GPIO32,
	DM365_GPIO33,
	DM365_GPIO40,
	DM365_GPIO64_57,
	DM365_GPIO80,
	DM365_GPIO82,
	DM365_VCLK,

	/* Video */
	DM365_VOUT_FIELD,
	DM365_VOUT_FIELD_G81,
	DM365_VOUT_HVSYNC,
	DM365_VOUT_COUTL_EN,
	DM365_VOUT_COUTH_EN,
	DM365_VIN_CAM_WEN,
	DM365_VIN_CAM_VD,
	DM365_VIN_CAM_HD,
	DM365_VIN_YIN4_7_EN,
	DM365_VIN_YIN0_3_EN,

	/* IRQ muxing */
	DM365_INT_EDMA_CC,
	DM365_INT_EDMA_TC0_ERR,
	DM365_INT_EDMA_TC1_ERR,
	DM365_INT_EDMA_TC2_ERR,
	DM365_INT_EDMA_TC3_ERR,
	DM365_INT_PRTCSS,
	DM365_INT_EMAC_RXTHRESH,
	DM365_INT_EMAC_RXPULSE,
	DM365_INT_EMAC_TXPULSE,
	DM365_INT_EMAC_MISCPULSE,
	DM365_INT_IMX0_ENABLE,
	DM365_INT_IMX0_DISABLE,
	DM365_INT_HDVICP_ENABLE,
	DM365_INT_HDVICP_DISABLE,
	DM365_INT_IMX1_ENABLE,
	DM365_INT_IMX1_DISABLE,
	DM365_INT_NSF_ENABLE,
	DM365_INT_NSF_DISABLE,

	/* EDMA event muxing */
	DM365_EVT2_ASP_TX,
	DM365_EVT3_ASP_RX,
	DM365_EVT2_VC_TX,
	DM365_EVT3_VC_RX,
	DM365_EVT26_MMC0_RX,
};

enum da830_index {
	DA830_GPIO7_14,
	DA830_RTCK,
	DA830_GPIO7_15,
	DA830_EMU_0,
	DA830_EMB_SDCKE,
	DA830_EMB_CLK_GLUE,
	DA830_EMB_CLK,
	DA830_NEMB_CS_0,
	DA830_NEMB_CAS,
	DA830_NEMB_RAS,
	DA830_NEMB_WE,
	DA830_EMB_BA_1,
	DA830_EMB_BA_0,
	DA830_EMB_A_0,
	DA830_EMB_A_1,
	DA830_EMB_A_2,
	DA830_EMB_A_3,
	DA830_EMB_A_4,
	DA830_EMB_A_5,
	DA830_GPIO7_0,
	DA830_GPIO7_1,
	DA830_GPIO7_2,
	DA830_GPIO7_3,
	DA830_GPIO7_4,
	DA830_GPIO7_5,
	DA830_GPIO7_6,
	DA830_GPIO7_7,
	DA830_EMB_A_6,
	DA830_EMB_A_7,
	DA830_EMB_A_8,
	DA830_EMB_A_9,
	DA830_EMB_A_10,
	DA830_EMB_A_11,
	DA830_EMB_A_12,
	DA830_EMB_D_31,
	DA830_GPIO7_8,
	DA830_GPIO7_9,
	DA830_GPIO7_10,
	DA830_GPIO7_11,
	DA830_GPIO7_12,
	DA830_GPIO7_13,
	DA830_GPIO3_13,
	DA830_EMB_D_30,
	DA830_EMB_D_29,
	DA830_EMB_D_28,
	DA830_EMB_D_27,
	DA830_EMB_D_26,
	DA830_EMB_D_25,
	DA830_EMB_D_24,
	DA830_EMB_D_23,
	DA830_EMB_D_22,
	DA830_EMB_D_21,
	DA830_EMB_D_20,
	DA830_EMB_D_19,
	DA830_EMB_D_18,
	DA830_EMB_D_17,
	DA830_EMB_D_16,
	DA830_NEMB_WE_DQM_3,
	DA830_NEMB_WE_DQM_2,
	DA830_EMB_D_0,
	DA830_EMB_D_1,
	DA830_EMB_D_2,
	DA830_EMB_D_3,
	DA830_EMB_D_4,
	DA830_EMB_D_5,
	DA830_EMB_D_6,
	DA830_GPIO6_0,
	DA830_GPIO6_1,
	DA830_GPIO6_2,
	DA830_GPIO6_3,
	DA830_GPIO6_4,
	DA830_GPIO6_5,
	DA830_GPIO6_6,
	DA830_EMB_D_7,
	DA830_EMB_D_8,
	DA830_EMB_D_9,
	DA830_EMB_D_10,
	DA830_EMB_D_11,
	DA830_EMB_D_12,
	DA830_EMB_D_13,
	DA830_EMB_D_14,
	DA830_GPIO6_7,
	DA830_GPIO6_8,
	DA830_GPIO6_9,
	DA830_GPIO6_10,
	DA830_GPIO6_11,
	DA830_GPIO6_12,
	DA830_GPIO6_13,
	DA830_GPIO6_14,
	DA830_EMB_D_15,
	DA830_NEMB_WE_DQM_1,
	DA830_NEMB_WE_DQM_0,
	DA830_SPI0_SOMI_0,
	DA830_SPI0_SIMO_0,
	DA830_SPI0_CLK,
	DA830_NSPI0_ENA,
	DA830_NSPI0_SCS_0,
	DA830_EQEP0I,
	DA830_EQEP0S,
	DA830_EQEP1I,
	DA830_NUART0_CTS,
	DA830_NUART0_RTS,
	DA830_EQEP0A,
	DA830_EQEP0B,
	DA830_GPIO6_15,
	DA830_GPIO5_14,
	DA830_GPIO5_15,
	DA830_GPIO5_0,
	DA830_GPIO5_1,
	DA830_GPIO5_2,
	DA830_GPIO5_3,
	DA830_GPIO5_4,
	DA830_SPI1_SOMI_0,
	DA830_SPI1_SIMO_0,
	DA830_SPI1_CLK,
	DA830_UART0_RXD,
	DA830_UART0_TXD,
	DA830_AXR1_10,
	DA830_AXR1_11,
	DA830_NSPI1_ENA,
	DA830_I2C1_SCL,
	DA830_I2C1_SDA,
	DA830_EQEP1S,
	DA830_I2C0_SDA,
	DA830_I2C0_SCL,
	DA830_UART2_RXD,
	DA830_TM64P0_IN12,
	DA830_TM64P0_OUT12,
	DA830_GPIO5_5,
	DA830_GPIO5_6,
	DA830_GPIO5_7,
	DA830_GPIO5_8,
	DA830_GPIO5_9,
	DA830_GPIO5_10,
	DA830_GPIO5_11,
	DA830_GPIO5_12,
	DA830_NSPI1_SCS_0,
	DA830_USB0_DRVVBUS,
	DA830_AHCLKX0,
	DA830_ACLKX0,
	DA830_AFSX0,
	DA830_AHCLKR0,
	DA830_ACLKR0,
	DA830_AFSR0,
	DA830_UART2_TXD,
	DA830_AHCLKX2,
	DA830_ECAP0_APWM0,
	DA830_RMII_MHZ_50_CLK,
	DA830_ECAP1_APWM1,
	DA830_USB_REFCLKIN,
	DA830_GPIO5_13,
	DA830_GPIO4_15,
	DA830_GPIO2_11,
	DA830_GPIO2_12,
	DA830_GPIO2_13,
	DA830_GPIO2_14,
	DA830_GPIO2_15,
	DA830_GPIO3_12,
	DA830_AMUTE0,
	DA830_AXR0_0,
	DA830_AXR0_1,
	DA830_AXR0_2,
	DA830_AXR0_3,
	DA830_AXR0_4,
	DA830_AXR0_5,
	DA830_AXR0_6,
	DA830_RMII_TXD_0,
	DA830_RMII_TXD_1,
	DA830_RMII_TXEN,
	DA830_RMII_CRS_DV,
	DA830_RMII_RXD_0,
	DA830_RMII_RXD_1,
	DA830_RMII_RXER,
	DA830_AFSR2,
	DA830_ACLKX2,
	DA830_AXR2_3,
	DA830_AXR2_2,
	DA830_AXR2_1,
	DA830_AFSX2,
	DA830_ACLKR2,
	DA830_NRESETOUT,
	DA830_GPIO3_0,
	DA830_GPIO3_1,
	DA830_GPIO3_2,
	DA830_GPIO3_3,
	DA830_GPIO3_4,
	DA830_GPIO3_5,
	DA830_GPIO3_6,
	DA830_AXR0_7,
	DA830_AXR0_8,
	DA830_UART1_RXD,
	DA830_UART1_TXD,
	DA830_AXR0_11,
	DA830_AHCLKX1,
	DA830_ACLKX1,
	DA830_AFSX1,
	DA830_MDIO_CLK,
	DA830_MDIO_D,
	DA830_AXR0_9,
	DA830_AXR0_10,
	DA830_EPWM0B,
	DA830_EPWM0A,
	DA830_EPWMSYNCI,
	DA830_AXR2_0,
	DA830_EPWMSYNC0,
	DA830_GPIO3_7,
	DA830_GPIO3_8,
	DA830_GPIO3_9,
	DA830_GPIO3_10,
	DA830_GPIO3_11,
	DA830_GPIO3_14,
	DA830_GPIO3_15,
	DA830_GPIO4_10,
	DA830_AHCLKR1,
	DA830_ACLKR1,
	DA830_AFSR1,
	DA830_AMUTE1,
	DA830_AXR1_0,
	DA830_AXR1_1,
	DA830_AXR1_2,
	DA830_AXR1_3,
	DA830_ECAP2_APWM2,
	DA830_EHRPWMGLUETZ,
	DA830_EQEP1A,
	DA830_GPIO4_11,
	DA830_GPIO4_12,
	DA830_GPIO4_13,
	DA830_GPIO4_14,
	DA830_GPIO4_0,
	DA830_GPIO4_1,
	DA830_GPIO4_2,
	DA830_GPIO4_3,
	DA830_AXR1_4,
	DA830_AXR1_5,
	DA830_AXR1_6,
	DA830_AXR1_7,
	DA830_AXR1_8,
	DA830_AXR1_9,
	DA830_EMA_D_0,
	DA830_EMA_D_1,
	DA830_EQEP1B,
	DA830_EPWM2B,
	DA830_EPWM2A,
	DA830_EPWM1B,
	DA830_EPWM1A,
	DA830_MMCSD_DAT_0,
	DA830_MMCSD_DAT_1,
	DA830_UHPI_HD_0,
	DA830_UHPI_HD_1,
	DA830_GPIO4_4,
	DA830_GPIO4_5,
	DA830_GPIO4_6,
	DA830_GPIO4_7,
	DA830_GPIO4_8,
	DA830_GPIO4_9,
	DA830_GPIO0_0,
	DA830_GPIO0_1,
	DA830_EMA_D_2,
	DA830_EMA_D_3,
	DA830_EMA_D_4,
	DA830_EMA_D_5,
	DA830_EMA_D_6,
	DA830_EMA_D_7,
	DA830_EMA_D_8,
	DA830_EMA_D_9,
	DA830_MMCSD_DAT_2,
	DA830_MMCSD_DAT_3,
	DA830_MMCSD_DAT_4,
	DA830_MMCSD_DAT_5,
	DA830_MMCSD_DAT_6,
	DA830_MMCSD_DAT_7,
	DA830_UHPI_HD_8,
	DA830_UHPI_HD_9,
	DA830_UHPI_HD_2,
	DA830_UHPI_HD_3,
	DA830_UHPI_HD_4,
	DA830_UHPI_HD_5,
	DA830_UHPI_HD_6,
	DA830_UHPI_HD_7,
	DA830_LCD_D_8,
	DA830_LCD_D_9,
	DA830_GPIO0_2,
	DA830_GPIO0_3,
	DA830_GPIO0_4,
	DA830_GPIO0_5,
	DA830_GPIO0_6,
	DA830_GPIO0_7,
	DA830_GPIO0_8,
	DA830_GPIO0_9,
	DA830_EMA_D_10,
	DA830_EMA_D_11,
	DA830_EMA_D_12,
	DA830_EMA_D_13,
	DA830_EMA_D_14,
	DA830_EMA_D_15,
	DA830_EMA_A_0,
	DA830_EMA_A_1,
	DA830_UHPI_HD_10,
	DA830_UHPI_HD_11,
	DA830_UHPI_HD_12,
	DA830_UHPI_HD_13,
	DA830_UHPI_HD_14,
	DA830_UHPI_HD_15,
	DA830_LCD_D_7,
	DA830_MMCSD_CLK,
	DA830_LCD_D_10,
	DA830_LCD_D_11,
	DA830_LCD_D_12,
	DA830_LCD_D_13,
	DA830_LCD_D_14,
	DA830_LCD_D_15,
	DA830_UHPI_HCNTL0,
	DA830_GPIO0_10,
	DA830_GPIO0_11,
	DA830_GPIO0_12,
	DA830_GPIO0_13,
	DA830_GPIO0_14,
	DA830_GPIO0_15,
	DA830_GPIO1_0,
	DA830_GPIO1_1,
	DA830_EMA_A_2,
	DA830_EMA_A_3,
	DA830_EMA_A_4,
	DA830_EMA_A_5,
	DA830_EMA_A_6,
	DA830_EMA_A_7,
	DA830_EMA_A_8,
	DA830_EMA_A_9,
	DA830_MMCSD_CMD,
	DA830_LCD_D_6,
	DA830_LCD_D_3,
	DA830_LCD_D_2,
	DA830_LCD_D_1,
	DA830_LCD_D_0,
	DA830_LCD_PCLK,
	DA830_LCD_HSYNC,
	DA830_UHPI_HCNTL1,
	DA830_GPIO1_2,
	DA830_GPIO1_3,
	DA830_GPIO1_4,
	DA830_GPIO1_5,
	DA830_GPIO1_6,
	DA830_GPIO1_7,
	DA830_GPIO1_8,
	DA830_GPIO1_9,
	DA830_EMA_A_10,
	DA830_EMA_A_11,
	DA830_EMA_A_12,
	DA830_EMA_BA_1,
	DA830_EMA_BA_0,
	DA830_EMA_CLK,
	DA830_EMA_SDCKE,
	DA830_NEMA_CAS,
	DA830_LCD_VSYNC,
	DA830_NLCD_AC_ENB_CS,
	DA830_LCD_MCLK,
	DA830_LCD_D_5,
	DA830_LCD_D_4,
	DA830_OBSCLK,
	DA830_NEMA_CS_4,
	DA830_UHPI_HHWIL,
	DA830_AHCLKR2,
	DA830_GPIO1_10,
	DA830_GPIO1_11,
	DA830_GPIO1_12,
	DA830_GPIO1_13,
	DA830_GPIO1_14,
	DA830_GPIO1_15,
	DA830_GPIO2_0,
	DA830_GPIO2_1,
	DA830_NEMA_RAS,
	DA830_NEMA_WE,
	DA830_NEMA_CS_0,
	DA830_NEMA_CS_2,
	DA830_NEMA_CS_3,
	DA830_NEMA_OE,
	DA830_NEMA_WE_DQM_1,
	DA830_NEMA_WE_DQM_0,
	DA830_NEMA_CS_5,
	DA830_UHPI_HRNW,
	DA830_NUHPI_HAS,
	DA830_NUHPI_HCS,
	DA830_NUHPI_HDS1,
	DA830_NUHPI_HDS2,
	DA830_NUHPI_HINT,
	DA830_AXR0_12,
	DA830_AMUTE2,
	DA830_AXR0_13,
	DA830_AXR0_14,
	DA830_AXR0_15,
	DA830_GPIO2_2,
	DA830_GPIO2_3,
	DA830_GPIO2_4,
	DA830_GPIO2_5,
	DA830_GPIO2_6,
	DA830_GPIO2_7,
	DA830_GPIO2_8,
	DA830_GPIO2_9,
	DA830_EMA_WAIT_0,
	DA830_NUHPI_HRDY,
	DA830_GPIO2_10,
};

enum davinci_da850_index {
	/* UART0 function */
	DA850_NUART0_CTS,
	DA850_NUART0_RTS,
	DA850_UART0_RXD,
	DA850_UART0_TXD,
        DA850_UART0_RTS,
        DA850_UART0_CTS,

	/* UART1 function */
	DA850_NUART1_CTS,
	DA850_NUART1_RTS,
	DA850_UART1_RXD,
	DA850_UART1_TXD,

	/* UART2 function */
	DA850_NUART2_CTS,
	DA850_NUART2_RTS,
	DA850_UART2_RXD,
	DA850_UART2_TXD,

	/* I2C1 function */
	DA850_I2C1_SCL,
	DA850_I2C1_SDA,

	/* I2C0 function */
	DA850_I2C0_SDA,
	DA850_I2C0_SCL,
       
        /* SPI0 function */
  
        DA850_SPI0_CLK,
        DA850_SPI0_SOMI,
        DA850_SPI0_SIMO,
        DA850_SPI0_ENA,
       
       /* EMAC function */
	DA850_MII_TXEN,
	DA850_MII_TXCLK,
	DA850_MII_COL,
	DA850_MII_TXD_3,
	DA850_MII_TXD_2,
	DA850_MII_TXD_1,
	DA850_MII_TXD_0,
	DA850_MII_RXER,
	DA850_MII_CRS,
	DA850_MII_RXCLK,
	DA850_MII_RXDV,
	DA850_MII_RXD_3,
	DA850_MII_RXD_2,
	DA850_MII_RXD_1,
	DA850_MII_RXD_0,
	DA850_MDIO_CLK,
	DA850_MDIO_D,
	DA850_RMII_TXD_0,
	DA850_RMII_TXD_1,
	DA850_RMII_TXEN,
	DA850_RMII_CRS_DV,
	DA850_RMII_RXD_0,
	DA850_RMII_RXD_1,
	DA850_RMII_RXER,
	DA850_RMII_MHZ_50_CLK,

	/* McASP function */
	DA850_ACLKR,
	DA850_ACLKX,
	DA850_AFSR,
	DA850_AFSX,
	DA850_AHCLKX,
	DA850_AMUTE,
	DA850_AXR_15,
	DA850_AXR_14,
	DA850_AXR_13,
	DA850_AXR_12,
	DA850_AXR_11,
	DA850_AXR_10,
	DA850_AXR_9,
	DA850_AXR_8,
	DA850_AXR_7,
	DA850_AXR_6,
	DA850_AXR_5,
	DA850_AXR_4,
	DA850_AXR_3,
	DA850_AXR_2,
	DA850_AXR_1,
	DA850_AXR_0,

	/* LCD function */
	DA850_LCD_D_7,
	DA850_LCD_D_6,
	DA850_LCD_D_5,
	DA850_LCD_D_4,
	DA850_LCD_D_3,
	DA850_LCD_D_2,
	DA850_LCD_D_1,
	DA850_LCD_D_0,
	DA850_LCD_D_15,
	DA850_LCD_D_14,
	DA850_LCD_D_13,
	DA850_LCD_D_12,
	DA850_LCD_D_11,
	DA850_LCD_D_10,
	DA850_LCD_D_9,
	DA850_LCD_D_8,
	DA850_LCD_PCLK,
	DA850_LCD_MCLK,
	DA850_LCD_HSYNC,
	DA850_LCD_VSYNC,
	DA850_NLCD_AC_ENB_CS,

	/* MMC/SD0 function */
	DA850_MMCSD0_DAT_0,
	DA850_MMCSD0_DAT_1,
	DA850_MMCSD0_DAT_2,
	DA850_MMCSD0_DAT_3,
	DA850_MMCSD0_CLK,
	DA850_MMCSD0_CMD,
        DA850_MMCSD0_CD,
	/* MMC/SD1 function */
	DA850_MMCSD1_DAT_0,
	DA850_MMCSD1_DAT_1,
	DA850_MMCSD1_DAT_2,
	DA850_MMCSD1_DAT_3,
	DA850_MMCSD1_CLK,
	DA850_MMCSD1_CMD,

	/* EMIF2.5/EMIFA function */
	DA850_EMA_D_7,
	DA850_EMA_D_6,
	DA850_EMA_D_5,
	DA850_EMA_D_4,
	DA850_EMA_D_3,
	DA850_EMA_D_2,
	DA850_EMA_D_1,
	DA850_EMA_D_0,
	DA850_EMA_A_1,
	DA850_EMA_A_2,
	DA850_NEMA_CS_3,
	DA850_NEMA_CS_4,
	DA850_NEMA_WE,
	DA850_NEMA_OE,
	DA850_EMA_D_15,
	DA850_EMA_D_14,
	DA850_EMA_D_13,
	DA850_EMA_D_12,
	DA850_EMA_D_11,
	DA850_EMA_D_10,
	DA850_EMA_D_9,
	DA850_EMA_D_8,
	DA850_EMA_A_0,
	DA850_EMA_A_3,
	DA850_EMA_A_4,
	DA850_EMA_A_5,
	DA850_EMA_A_6,
	DA850_EMA_A_7,
	DA850_EMA_A_8,
	DA850_EMA_A_9,
	DA850_EMA_A_10,
	DA850_EMA_A_11,
	DA850_EMA_A_12,
	DA850_EMA_A_13,
	DA850_EMA_A_14,
	DA850_EMA_A_15,
	DA850_EMA_A_16,
	DA850_EMA_A_17,
	DA850_EMA_A_18,
	DA850_EMA_A_19,
	DA850_EMA_A_20,
	DA850_EMA_A_21,
	DA850_EMA_A_22,
	DA850_EMA_A_23,
	DA850_EMA_BA_1,
	DA850_EMA_CLK,
	DA850_EMA_WAIT_1,
        DA850_EMA_WAIT_0,
	DA850_NEMA_CS_2,

	/* GPIO function */
	DA850_GPIO2_4,
	DA850_GPIO2_6,
	DA850_GPIO2_8,
	DA850_GPIO2_15,
	DA850_GPIO4_0,
	DA850_GPIO4_1,
	DA850_GPIO1_4,
	DA850_GPIO1_5,
	DA850_GPIO0_11,
	DA850_GPIO6_13,
	DA850_RTC_ALARM,
	DA850_GPIO7_4,
	DA850_GPIO0_15,
	DA850_GPIO6_9,
	DA850_GPIO6_10,

	/* McBSP0 function */
	DA850_MCBSP0_CLKR,
	DA850_MCBSP0_CLKX,
	DA850_MCBSP0_FSR,
	DA850_MCBSP0_FSX,
	DA850_MCBSP0_DR,
	DA850_MCBSP0_DX,
	DA850_MCBSP0_CLKS,

	/* McBSP1 fucntion */
	DA850_MCBSP1_CLKR,
	DA850_MCBSP1_CLKX,
	DA850_MCBSP1_FSR,
	DA850_MCBSP1_FSX,
	DA850_MCBSP1_DR,
	DA850_MCBSP1_DX,
	DA850_MCBSP1_CLKS,

	/* VPIF Capture */
	DA850_VPIF_DIN0,
	DA850_VPIF_DIN1,
	DA850_VPIF_DIN2,
	DA850_VPIF_DIN3,
	DA850_VPIF_DIN4,
	DA850_VPIF_DIN5,
	DA850_VPIF_DIN6,
	DA850_VPIF_DIN7,
	DA850_VPIF_DIN8,
	DA850_VPIF_DIN9,
	DA850_VPIF_DIN10,
	DA850_VPIF_DIN11,
	DA850_VPIF_DIN12,
	DA850_VPIF_DIN13,
	DA850_VPIF_DIN14,
	DA850_VPIF_DIN15,
	DA850_VPIF_CLKIN0,
	DA850_VPIF_CLKIN1,
	DA850_VPIF_CLKIN2,
	DA850_VPIF_CLKIN3,

	/* VPIF Display */
	DA850_VPIF_DOUT0,
	DA850_VPIF_DOUT1,
	DA850_VPIF_DOUT2,
	DA850_VPIF_DOUT3,
	DA850_VPIF_DOUT4,
	DA850_VPIF_DOUT5,
	DA850_VPIF_DOUT6,
	DA850_VPIF_DOUT7,
	DA850_VPIF_DOUT8,
	DA850_VPIF_DOUT9,
	DA850_VPIF_DOUT10,
	DA850_VPIF_DOUT11,
	DA850_VPIF_DOUT12,
	DA850_VPIF_DOUT13,
	DA850_VPIF_DOUT14,
	DA850_VPIF_DOUT15,
	DA850_VPIF_CLKO2,
	DA850_VPIF_CLKO3,

	/* eHRPWM0 function */
	DA850_EHRPWM0_A,
	DA850_EHRPWM0_B,
	DA850_EHRPWM0_TZ,

	/* eHRPWM1 function */
	DA850_EHRPWM1_A,
	DA850_EHRPWM1_B,
	DA850_EHRPWM1_TZ,

	/* eCAP functions */
	DA850_ECAP0_APWM0,
	DA850_ECAP1_APWM1,
	DA850_ECAP2_APWM2,
};

enum davinci_tnetv107x_index {
	TNETV107X_ASR_A00,
	TNETV107X_GPIO32,
	TNETV107X_ASR_A01,
	TNETV107X_GPIO33,
	TNETV107X_ASR_A02,
	TNETV107X_GPIO34,
	TNETV107X_ASR_A03,
	TNETV107X_GPIO35,
	TNETV107X_ASR_A04,
	TNETV107X_GPIO36,
	TNETV107X_ASR_A05,
	TNETV107X_GPIO37,
	TNETV107X_ASR_A06,
	TNETV107X_GPIO38,
	TNETV107X_ASR_A07,
	TNETV107X_GPIO39,
	TNETV107X_ASR_A08,
	TNETV107X_GPIO40,
	TNETV107X_ASR_A09,
	TNETV107X_GPIO41,
	TNETV107X_ASR_A10,
	TNETV107X_GPIO42,
	TNETV107X_ASR_A11,
	TNETV107X_BOOT_STRP_0,
	TNETV107X_ASR_A12,
	TNETV107X_BOOT_STRP_1,
	TNETV107X_ASR_A13,
	TNETV107X_GPIO43,
	TNETV107X_ASR_A14,
	TNETV107X_GPIO44,
	TNETV107X_ASR_A15,
	TNETV107X_GPIO45,
	TNETV107X_ASR_A16,
	TNETV107X_GPIO46,
	TNETV107X_ASR_A17,
	TNETV107X_GPIO47,
	TNETV107X_ASR_A18,
	TNETV107X_GPIO48,
	TNETV107X_SDIO1_DATA3_0,
	TNETV107X_ASR_A19,
	TNETV107X_GPIO49,
	TNETV107X_SDIO1_DATA2_0,
	TNETV107X_ASR_A20,
	TNETV107X_GPIO50,
	TNETV107X_SDIO1_DATA1_0,
	TNETV107X_ASR_A21,
	TNETV107X_GPIO51,
	TNETV107X_SDIO1_DATA0_0,
	TNETV107X_ASR_A22,
	TNETV107X_GPIO52,
	TNETV107X_SDIO1_CMD_0,
	TNETV107X_ASR_A23,
	TNETV107X_GPIO53,
	TNETV107X_SDIO1_CLK_0,
	TNETV107X_ASR_BA_1,
	TNETV107X_GPIO54,
	TNETV107X_SYS_PLL_CLK,
	TNETV107X_ASR_CS0,
	TNETV107X_ASR_CS1,
	TNETV107X_ASR_CS2,
	TNETV107X_TDM_PLL_CLK,
	TNETV107X_ASR_CS3,
	TNETV107X_ETH_PHY_CLK,
	TNETV107X_ASR_D00,
	TNETV107X_GPIO55,
	TNETV107X_ASR_D01,
	TNETV107X_GPIO56,
	TNETV107X_ASR_D02,
	TNETV107X_GPIO57,
	TNETV107X_ASR_D03,
	TNETV107X_GPIO58,
	TNETV107X_ASR_D04,
	TNETV107X_GPIO59_0,
	TNETV107X_ASR_D05,
	TNETV107X_GPIO60_0,
	TNETV107X_ASR_D06,
	TNETV107X_GPIO61_0,
	TNETV107X_ASR_D07,
	TNETV107X_GPIO62_0,
	TNETV107X_ASR_D08,
	TNETV107X_GPIO63_0,
	TNETV107X_ASR_D09,
	TNETV107X_GPIO64_0,
	TNETV107X_ASR_D10,
	TNETV107X_SDIO1_DATA3_1,
	TNETV107X_ASR_D11,
	TNETV107X_SDIO1_DATA2_1,
	TNETV107X_ASR_D12,
	TNETV107X_SDIO1_DATA1_1,
	TNETV107X_ASR_D13,
	TNETV107X_SDIO1_DATA0_1,
	TNETV107X_ASR_D14,
	TNETV107X_SDIO1_CMD_1,
	TNETV107X_ASR_D15,
	TNETV107X_SDIO1_CLK_1,
	TNETV107X_ASR_OE,
	TNETV107X_BOOT_STRP_2,
	TNETV107X_ASR_RNW,
	TNETV107X_GPIO29_0,
	TNETV107X_ASR_WAIT,
	TNETV107X_GPIO30_0,
	TNETV107X_ASR_WE,
	TNETV107X_BOOT_STRP_3,
	TNETV107X_ASR_WE_DQM0,
	TNETV107X_GPIO31,
	TNETV107X_LCD_PD17_0,
	TNETV107X_ASR_WE_DQM1,
	TNETV107X_ASR_BA0_0,
	TNETV107X_VLYNQ_CLK,
	TNETV107X_GPIO14,
	TNETV107X_LCD_PD19_0,
	TNETV107X_VLYNQ_RXD0,
	TNETV107X_GPIO15,
	TNETV107X_LCD_PD20_0,
	TNETV107X_VLYNQ_RXD1,
	TNETV107X_GPIO16,
	TNETV107X_LCD_PD21_0,
	TNETV107X_VLYNQ_TXD0,
	TNETV107X_GPIO17,
	TNETV107X_LCD_PD22_0,
	TNETV107X_VLYNQ_TXD1,
	TNETV107X_GPIO18,
	TNETV107X_LCD_PD23_0,
	TNETV107X_SDIO0_CLK,
	TNETV107X_GPIO19,
	TNETV107X_SDIO0_CMD,
	TNETV107X_GPIO20,
	TNETV107X_SDIO0_DATA0,
	TNETV107X_GPIO21,
	TNETV107X_SDIO0_DATA1,
	TNETV107X_GPIO22,
	TNETV107X_SDIO0_DATA2,
	TNETV107X_GPIO23,
	TNETV107X_SDIO0_DATA3,
	TNETV107X_GPIO24,
	TNETV107X_EMU0,
	TNETV107X_EMU1,
	TNETV107X_RTCK,
	TNETV107X_TRST_N,
	TNETV107X_TCK,
	TNETV107X_TDI,
	TNETV107X_TDO,
	TNETV107X_TMS,
	TNETV107X_TDM1_CLK,
	TNETV107X_TDM1_RX,
	TNETV107X_TDM1_TX,
	TNETV107X_TDM1_FS,
	TNETV107X_KEYPAD_R0,
	TNETV107X_KEYPAD_R1,
	TNETV107X_KEYPAD_R2,
	TNETV107X_KEYPAD_R3,
	TNETV107X_KEYPAD_R4,
	TNETV107X_KEYPAD_R5,
	TNETV107X_KEYPAD_R6,
	TNETV107X_GPIO12,
	TNETV107X_KEYPAD_R7,
	TNETV107X_GPIO10,
	TNETV107X_KEYPAD_C0,
	TNETV107X_KEYPAD_C1,
	TNETV107X_KEYPAD_C2,
	TNETV107X_KEYPAD_C3,
	TNETV107X_KEYPAD_C4,
	TNETV107X_KEYPAD_C5,
	TNETV107X_KEYPAD_C6,
	TNETV107X_GPIO13,
	TNETV107X_TEST_CLK_IN,
	TNETV107X_KEYPAD_C7,
	TNETV107X_GPIO11,
	TNETV107X_SSP0_0,
	TNETV107X_SCC_DCLK,
	TNETV107X_LCD_PD20_1,
	TNETV107X_SSP0_1,
	TNETV107X_SCC_CS_N,
	TNETV107X_LCD_PD21_1,
	TNETV107X_SSP0_2,
	TNETV107X_SCC_D,
	TNETV107X_LCD_PD22_1,
	TNETV107X_SSP0_3,
	TNETV107X_SCC_RESETN,
	TNETV107X_LCD_PD23_1,
	TNETV107X_SSP1_0,
	TNETV107X_GPIO25,
	TNETV107X_UART2_CTS,
	TNETV107X_SSP1_1,
	TNETV107X_GPIO26,
	TNETV107X_UART2_RD,
	TNETV107X_SSP1_2,
	TNETV107X_GPIO27,
	TNETV107X_UART2_RTS,
	TNETV107X_SSP1_3,
	TNETV107X_GPIO28,
	TNETV107X_UART2_TD,
	TNETV107X_UART0_CTS,
	TNETV107X_UART0_RD,
	TNETV107X_UART0_RTS,
	TNETV107X_UART0_TD,
	TNETV107X_UART1_RD,
	TNETV107X_UART1_TD,
	TNETV107X_LCD_AC_NCS,
	TNETV107X_LCD_HSYNC_RNW,
	TNETV107X_LCD_VSYNC_A0,
	TNETV107X_LCD_MCLK,
	TNETV107X_LCD_PD16_0,
	TNETV107X_LCD_PCLK_E,
	TNETV107X_LCD_PD00,
	TNETV107X_LCD_PD01,
	TNETV107X_LCD_PD02,
	TNETV107X_LCD_PD03,
	TNETV107X_LCD_PD04,
	TNETV107X_LCD_PD05,
	TNETV107X_LCD_PD06,
	TNETV107X_LCD_PD07,
	TNETV107X_LCD_PD08,
	TNETV107X_GPIO59_1,
	TNETV107X_LCD_PD09,
	TNETV107X_GPIO60_1,
	TNETV107X_LCD_PD10,
	TNETV107X_ASR_BA0_1,
	TNETV107X_GPIO61_1,
	TNETV107X_LCD_PD11,
	TNETV107X_GPIO62_1,
	TNETV107X_LCD_PD12,
	TNETV107X_GPIO63_1,
	TNETV107X_LCD_PD13,
	TNETV107X_GPIO64_1,
	TNETV107X_LCD_PD14,
	TNETV107X_GPIO29_1,
	TNETV107X_LCD_PD15,
	TNETV107X_GPIO30_1,
	TNETV107X_EINT0,
	TNETV107X_GPIO08,
	TNETV107X_EINT1,
	TNETV107X_GPIO09,
	TNETV107X_GPIO00,
	TNETV107X_LCD_PD20_2,
	TNETV107X_TDM_CLK_IN_2,
	TNETV107X_GPIO01,
	TNETV107X_LCD_PD21_2,
	TNETV107X_24M_CLK_OUT_1,
	TNETV107X_GPIO02,
	TNETV107X_LCD_PD22_2,
	TNETV107X_GPIO03,
	TNETV107X_LCD_PD23_2,
	TNETV107X_GPIO04,
	TNETV107X_LCD_PD16_1,
	TNETV107X_USB0_RXERR,
	TNETV107X_GPIO05,
	TNETV107X_LCD_PD17_1,
	TNETV107X_TDM_CLK_IN_1,
	TNETV107X_GPIO06,
	TNETV107X_LCD_PD18,
	TNETV107X_24M_CLK_OUT_2,
	TNETV107X_GPIO07,
	TNETV107X_LCD_PD19_1,
	TNETV107X_USB1_RXERR,
	TNETV107X_ETH_PLL_CLK,
	TNETV107X_MDIO,
	TNETV107X_MDC,
	TNETV107X_AIC_MUTE_STAT_N,
	TNETV107X_TDM0_CLK,
	TNETV107X_AIC_HNS_EN_N,
	TNETV107X_TDM0_FS,
	TNETV107X_AIC_HDS_EN_STAT_N,
	TNETV107X_TDM0_TX,
	TNETV107X_AIC_HNF_EN_STAT_N,
	TNETV107X_TDM0_RX,
};

#define PINMUX(x)		(4 * (x))

#ifdef CONFIG_DAVINCI_MUX
/* setup pin muxing */
extern int davinci_cfg_reg(unsigned long reg_cfg);
extern int davinci_cfg_reg_list(const short pins[]);
#else
/* boot loader does it all (no warnings from CONFIG_DAVINCI_MUX_WARNINGS) */
static inline int davinci_cfg_reg(unsigned long reg_cfg) { return 0; }
static inline int davinci_cfg_reg_list(const short pins[])
{
	return 0;
}
#endif

#endif /* __INC_MACH_MUX_H */
