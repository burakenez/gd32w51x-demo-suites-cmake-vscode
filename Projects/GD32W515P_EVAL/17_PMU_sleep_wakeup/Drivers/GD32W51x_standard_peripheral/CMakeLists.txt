project(GD32W51x_standard_peripheral LANGUAGES C CXX ASM)

# Comment-out unused source files.
add_library(GD32W51x_standard_peripheral OBJECT
	${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_adc.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_cau.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_cau_aes.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_cau_des.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_cau_tdes.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_crc.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_dbg.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_dci.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_dma.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_efuse.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_exti.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_fmc.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_fwdgt.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_gpio.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_hau.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_hau_sha_md5.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_hpdf.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_i2c.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_icache.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_misc.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_pkcau.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_pmu.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_qspi.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_rcu.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_rtc.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_sdio.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_spi.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_sqpi.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_syscfg.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_timer.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_trng.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_tsi.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_tzpcu.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_usart.c
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Source/gd32w51x_wwdgt.c
    )

target_include_directories(GD32W51x_standard_peripheral PUBLIC
    ${DRIVERS_DIR}/GD32W51x_standard_peripheral/Include
    )

# CMSIS header only library is linked.
target_link_libraries(GD32W51x_standard_peripheral PUBLIC CMSIS)
