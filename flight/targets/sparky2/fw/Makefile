# @file       Makefile
# @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2015
# @author     dRonin, http://dronin.org Copyright (C) 2015-2016
# @addtogroup
# @{
# @addtogroup
# @{
# @brief Makefile to build firmware for the Sparky2 board.
###############################################################################
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, see <http://www.gnu.org/licenses/>
#
# Additional note on redistribution: The copyright and license notices above
# must be maintained in each individual source file that is a derivative work
# of this source file; otherwise redistribution is prohibited.

include $(MAKE_INC_DIR)/firmware-defs.mk

# Set developer code and compile options
# Set to YES for debugging
DEBUG ?= NO

# List of modules to include
MODULES = Attitude
MODULES += ManualControl
MODULES += Stabilization
MODULES += Actuator
MODULES += FirmwareIAP
MODULES += Telemetry

OPTMODULES += GPS
OPTMODULES += PathPlanner
OPTMODULES += VtolPathFollower
OPTMODULES += FixedWingPathFollower
OPTMODULES += CameraStab
OPTMODULES += Autotune
OPTMODULES += TxPID
OPTMODULES += Battery
OPTMODULES += ComUsbBridge
OPTMODULES += VibrationAnalysis
OPTMODULES += UAVOMavlinkBridge
OPTMODULES += UAVOMSPBridge
OPTMODULES += UAVOLighttelemetryBridge
OPTMODULES += UAVORelay
OPTMODULES += Airspeed
OPTMODULES += UAVOHoTTBridge
OPTMODULES += UAVOFrSKYSensorHubBridge
OPTMODULES += UAVOFrSKYSPortBridge
OPTMODULES += Logging
OPTMODULES += FlightStats
OPTMODULES += Storm32Bgc
OPTMODULES += UAVOCrossfireTelemetry
OPTMODULES += Loadable

# Paths
OPUAVOBJINC = $(OPUAVOBJ)/inc
PIOSINC = $(PIOS)/inc
FLIGHTLIBINC = $(FLIGHTLIB)/inc
MATHLIB = $(FLIGHTLIB)/math
MATHLIBINC = $(FLIGHTLIB)/math
PIOSSTM32F4XX = $(PIOS)/STM32F4xx
PIOSCOMMON = $(PIOS)/Common
PIOSCOMMONLIB = $(PIOSCOMMON)/Libraries
APPLIBDIR = $(PIOSSTM32F4XX)/Libraries
STMLIBDIR = $(APPLIBDIR)
STMSPDDIR = $(STMLIBDIR)/STM32F4xx_StdPeriph_Driver
STMSPDSRCDIR = $(STMSPDDIR)/src
STMSPDINCDIR = $(STMSPDDIR)/inc
DEBUG_CM3_DIR = $(PIOSCOMMONLIB)/Debug
DEBUG_CM3_DIR_INC = $(DEBUG_CM3_DIR)/inc
OPUAVOBJINC = $(OPUAVOBJ)/inc
MAVLINKINC = $(FLIGHTLIB)/mavlink/v1.0/common

SRC =
# optional component libraries
include $(APPLIBDIR)/ChibiOS/library.mk

# List C source files here. (C dependencies are automatically generated.)
# use file-extension c for "c-only"-files

## OPENPILOT CORE:
SRC += ${OPMODULEDIR}/System/systemmod.c
SRC += ${OPMODULEDIR}/System/rgbleds.c
SRC += chibi_main.c
SRC += pios_board.c
SRC += pios_usb_board_data.c
SRC += $(OPUAVOBJ)/uavobjectmanager.c
SRC += printf-stdarg.c

ifeq ($(DEBUG),YES)
SRC += $(DEBUG_CM3_DIR)/dcc_stdio.c
SRC += $(DEBUG_CM3_DIR)/cm3_fault_handlers.c
endif

SRC += taskmonitor.c

## PIOS Hardware (STM32F4xx)
include $(PIOS)/STM32F4xx/library_chibios.mk

## PIOS Hardware (Common)
include $(PIOS)/pios_flight_library.mk
SRC += pios_mpu.c
SRC += pios_etasv3.c
SRC += pios_mpxv5004.c
SRC += pios_mpxv7002.c
SRC += pios_hmc5883.c
SRC += pios_hmc5983_i2c.c
SRC += pios_ms5611.c
SRC += pios_openlrs.c
SRC += pios_openlrs_rcvr.c

# List C source files here which must be compiled in ARM-Mode (no -mthumb).
# use file-extension c for "c-only"-files
## just for testing, timer.c could be compiled in thumb-mode too
SRCARM =

# List C++ source files here.
# use file-extension .cpp for C++-files (not .C)
CPPSRC =

# List C++ source files here which must be compiled in ARM-Mode.
# use file-extension .cpp for C++-files (not .C)
#CPPSRCARM = $(TARGET).cpp
CPPSRCARM =

# List Assembler source files here.
# Make them always end in a capital .S. Files ending in a lowercase .s
# will not be considered source files but generated files (assembler
# output from the compiler), and will be deleted upon "make clean"!
# Even though the DOS/Win* filesystem matches both .s and .S the same,
# it will preserve the spelling of the filenames, and gcc itself does
# care about how the name is spelled on its command-line.


# List Assembler source files here which must be assembled in ARM-Mode..
ASRCARM =

EXTRAINCDIRS += ${foreach MOD, ${MODULES} ${OPTMODULES}, $(OPMODULEDIR)/${MOD}/inc} ${OPMODULEDIR}/System/inc

# List any extra directories to look for include files here.
#    Each directory must be seperated by a space.
EXTRAINCDIRS  += $(SHAREDAPIDIR)
EXTRAINCDIRS  += $(PIOS)
EXTRAINCDIRS  += $(PIOSINC)
EXTRAINCDIRS  += $(OPUAVOBJ)
EXTRAINCDIRS  += $(OPUAVOBJINC)
EXTRAINCDIRS  += $(UAVOBJSYNTHDIR)
EXTRAINCDIRS  += $(FLIGHTLIBINC)
EXTRAINCDIRS  += $(MATHLIBINC)
EXTRAINCDIRS  += $(PIOSSTM32F4XX)
EXTRAINCDIRS  += $(PIOSCOMMON)
EXTRAINCDIRS  += $(STMSPDINCDIR)
EXTRAINCDIRS  += $(CMSISDIR)
EXTRAINCDIRS  += $(OPUAVSYNTHDIR)
EXTRAINCDIRS  += $(BOOTINC)
EXTRAINCDIRS  += $(DEBUG_CM3_DIR_INC)
EXTRAINCDIRS  += $(MAVLINKINC)

# List any extra directories to look for library files here.
# Also add directories where the linker should search for
# includes from linker-script to the list
#     Each directory must be seperated by a space.
EXTRA_LIBDIRS =

# Extra Libraries
#    Each library-name must be seperated by a space.
#    i.e. to link with libxyz.a, libabc.a and libefsl.a:
#    EXTRA_LIBS = xyz abc efsl
# for newlib-lpc (file: libnewlibc-lpc.a):
#    EXTRA_LIBS = newlib-lpc
EXTRA_LIBS =

# Path to Linker-Scripts
LINKERSCRIPTPATH = $(PIOSSTM32F4XX)

# debug (un)optimization, see gcc docs
ifeq ($(DEBUG),YES)
CFLAGS += -Og
CFLAGS += -ffixed-r10
# finstrument-functions adds __cyg_profile_func_enter/exit to every function
# we currently don't have that symbol implemented anywhere
#CFLAGS += -finstrument-functions
else
CFLAGS += -Os -fconserve-stack
endif

# common architecture-specific flags from the device-specific library makefile
CFLAGS += $(ARCHFLAGS)

CFLAGS += -DDIAGNOSTICS
CFLAGS += -DDIAG_TASKS

# configure CMSIS DSP Library
CDEFS += -DARM_MATH_CM4
CDEFS += -DARM_MATH_MATRIX_CHECK
CDEFS += -DARM_MATH_ROUNDING
CDEFS += -D__FPU_PRESENT=1
CDEFS += -DUNALIGNED_SUPPORT_DISABLE

# This is not the best place for these.  Really should abstract out
# to the board file or something
CFLAGS += -D$(STM32_TYPE)
CFLAGS += -DMEM_SIZE=1024000000

# Output format. (can be ihex or binary or both)
#  binary to create a load-image in raw-binary format i.e. for SAM-BA,
#  ihex to create a load-image in Intel hex format
#LOADFORMAT = ihex
#LOADFORMAT = binary
LOADFORMAT = both

# Debugging format.
DEBUGF = dwarf-2

# Place project-specific -D (define) and/or
# -U options for C here.
CDEFS += -DHSE_VALUE=$(OSCILLATOR_FREQ)
CDEFS += -DSYSCLK_FREQ=$(SYSCLK_FREQ)
CDEFS += -DUSE_STDPERIPH_DRIVER
CDEFS += -DUSE_$(BOARD)
ifeq ($(ENABLE_DEBUG_CONSOLE), YES)
CDEFS += -DPIOS_INCLUDE_DEBUG_CONSOLE
endif
CDEFS += '-DCORTEX_VTOR_INIT=($(FW_BANK_BASE)-$(EF_BANK_BASE))'

ifeq ($(ENABLE_DEBUG_CONSOLE), YES)
CDEFS += -DPIOS_INCLUDE_DEBUG_CONSOLE
endif

# Declare all non-optional modules as built-in to force inclusion
get_mod_name = $(shell echo $(1) | sed "s/\/[^\/]*$///")
BUILTIN_DEFS := ${foreach MOD, ${MODULES}, -DMODULE_$(call get_mod_name, $(MOD))_BUILTIN }
CDEFS += ${BUILTIN_DEFS}

# Place project-specific -D and/or -U options for
# Assembler with preprocessor here.
#ADEFS = -DUSE_IRQ_ASM_WRAPPER
ADEFS = -D__ASSEMBLY__

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CSTANDARD = -std=gnu99

#-----

# Compiler flags.

#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#
# Flags for C and C++ (arm-elf-gcc/arm-elf-g++)

CFLAGS += -g$(DEBUGF)

CFLAGS += -mcpu=$(MCU)
CFLAGS += $(CDEFS)
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS)) -I.

CFLAGS += -mapcs-frame
CFLAGS += -fomit-frame-pointer
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wdouble-promotion

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wa,-adhlns=$(addprefix $(OUTDIR)/, $(notdir $(addsuffix .lst, $(basename $<))))
# Compiler flags to generate dependency files:
CFLAGS += -MD -MP -MF $(OUTDIR)/dep/$(@F).d

# flags only for C
#CONLYFLAGS += -Wnested-externs
CONLYFLAGS += $(CSTANDARD)

# Assembler flags.
#  -Wa,...:    tell GCC to pass this to the assembler.
#  -ahlns:     create listing
ASFLAGS  = $(ARCHFLAGS) -mthumb -I. -x assembler-with-cpp
ASFLAGS += $(ADEFS)
ASFLAGS += -Wa,-adhlns=$(addprefix $(OUTDIR)/, $(notdir $(addsuffix .lst, $(basename $<))))
ASFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))

MATH_LIB = -lm

LIBS += $(UAVOBJLIB)
LIBS += $(FLIGHTLIBFILE)

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
LDFLAGS = -nostartfiles -Wl,-Map=$(OUTDIR)/$(TARGET).map,--cref,--gc-sections
LDFLAGS += $(patsubst %,-L%,$(EXTRA_LIBDIRS))
LDFLAGS += -lc_nano
LDFLAGS += $(patsubst %,-l%,$(EXTRA_LIBS))
LDFLAGS += $(MATH_LIB)
LDFLAGS += -lgcc
LDFLAGS += -Wl,--warn-common
LDFLAGS += -Wl,--fatal-warnings

#Linker scripts
LDFLAGS += -T memory.ld $(addprefix -T,$(LINKER_SCRIPTS_APP))

include $(MAKE_INC_DIR)/firmware-common.mk
