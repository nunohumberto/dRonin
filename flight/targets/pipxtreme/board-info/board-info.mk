BOARD_TYPE          := 0x03
BOARD_REVISION      := 0x02
BOOTLOADER_VERSION  := 0x87
HW_TYPE             := 0x01

CHIP                := STM32F103CBT
BOARD               := STM32103CB_PIPXTREME
MODEL               := MD
MODEL_SUFFIX        := _PX

include $(MAKE_INC_DIR)/firmware-arches.mk

# Note: These must match the values in link_$(BOARD)_memory.ld
BL_BANK_BASE        := 0x08000000  # Start of bootloader flash
BL_BANK_SIZE        := 0x00003000  # Should include BD_INFO region
FW_BANK_BASE        := 0x08003000  # Start of firmware flash
FW_BANK_SIZE        := 0x00019000  # Should include FW_DESC_SIZE (100kb)
EE_BANK_BASE        := 0x0801C000  # EEPROM storage area
EE_BANK_SIZE        := 0x00004000  # Size of EEPROM storage area

FW_DESC_SIZE        := 0x00000064

EF_BANK_BASE        := 0x08000000  # Start of entire flash image (usually start of bootloader as well)
EF_BANK_SIZE        := 0x00020000  # Size of the entire flash image (from bootloader until end of firmware)

OSCILLATOR_FREQ     :=   8000000
SYSCLK_FREQ         :=  72000000

