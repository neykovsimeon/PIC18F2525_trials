#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../common/sources/plib/XLCD/busyxlcd.c ../../common/sources/plib/XLCD/openxlcd.c ../../common/sources/plib/XLCD/putrxlcd.c ../../common/sources/plib/XLCD/putsxlcd.c ../../common/sources/plib/XLCD/readaddr.c ../../common/sources/plib/XLCD/readdata.c ../../common/sources/plib/XLCD/setcgram.c ../../common/sources/plib/XLCD/setddram.c ../../common/sources/plib/XLCD/wcmdxlcd.c ../../common/sources/plib/XLCD/writdata.c lcd_menu.c lcd_trials_4bits.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 ${OBJECTDIR}/_ext/1853830924/readaddr.p1 ${OBJECTDIR}/_ext/1853830924/readdata.p1 ${OBJECTDIR}/_ext/1853830924/setcgram.p1 ${OBJECTDIR}/_ext/1853830924/setddram.p1 ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 ${OBJECTDIR}/_ext/1853830924/writdata.p1 ${OBJECTDIR}/lcd_menu.p1 ${OBJECTDIR}/lcd_trials_4bits.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1853830924/busyxlcd.p1.d ${OBJECTDIR}/_ext/1853830924/openxlcd.p1.d ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1.d ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1.d ${OBJECTDIR}/_ext/1853830924/readaddr.p1.d ${OBJECTDIR}/_ext/1853830924/readdata.p1.d ${OBJECTDIR}/_ext/1853830924/setcgram.p1.d ${OBJECTDIR}/_ext/1853830924/setddram.p1.d ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1.d ${OBJECTDIR}/_ext/1853830924/writdata.p1.d ${OBJECTDIR}/lcd_menu.p1.d ${OBJECTDIR}/lcd_trials_4bits.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 ${OBJECTDIR}/_ext/1853830924/readaddr.p1 ${OBJECTDIR}/_ext/1853830924/readdata.p1 ${OBJECTDIR}/_ext/1853830924/setcgram.p1 ${OBJECTDIR}/_ext/1853830924/setddram.p1 ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 ${OBJECTDIR}/_ext/1853830924/writdata.p1 ${OBJECTDIR}/lcd_menu.p1 ${OBJECTDIR}/lcd_trials_4bits.p1

# Source Files
SOURCEFILES=../../common/sources/plib/XLCD/busyxlcd.c ../../common/sources/plib/XLCD/openxlcd.c ../../common/sources/plib/XLCD/putrxlcd.c ../../common/sources/plib/XLCD/putsxlcd.c ../../common/sources/plib/XLCD/readaddr.c ../../common/sources/plib/XLCD/readdata.c ../../common/sources/plib/XLCD/setcgram.c ../../common/sources/plib/XLCD/setddram.c ../../common/sources/plib/XLCD/wcmdxlcd.c ../../common/sources/plib/XLCD/writdata.c lcd_menu.c lcd_trials_4bits.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2525
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1853830924/busyxlcd.p1: ../../common/sources/plib/XLCD/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 ../../common/sources/plib/XLCD/busyxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/openxlcd.p1: ../../common/sources/plib/XLCD/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 ../../common/sources/plib/XLCD/openxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/putrxlcd.p1: ../../common/sources/plib/XLCD/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 ../../common/sources/plib/XLCD/putrxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/putsxlcd.p1: ../../common/sources/plib/XLCD/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 ../../common/sources/plib/XLCD/putsxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/readaddr.p1: ../../common/sources/plib/XLCD/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readaddr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readaddr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/readaddr.p1 ../../common/sources/plib/XLCD/readaddr.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/readaddr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/readdata.p1: ../../common/sources/plib/XLCD/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readdata.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readdata.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/readdata.p1 ../../common/sources/plib/XLCD/readdata.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/readdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/setcgram.p1: ../../common/sources/plib/XLCD/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setcgram.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setcgram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/setcgram.p1 ../../common/sources/plib/XLCD/setcgram.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/setcgram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/setddram.p1: ../../common/sources/plib/XLCD/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setddram.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setddram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/setddram.p1 ../../common/sources/plib/XLCD/setddram.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/setddram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1: ../../common/sources/plib/XLCD/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 ../../common/sources/plib/XLCD/wcmdxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/writdata.p1: ../../common/sources/plib/XLCD/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/writdata.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/writdata.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/writdata.p1 ../../common/sources/plib/XLCD/writdata.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/writdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd_menu.p1: lcd_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_menu.p1.d 
	@${RM} ${OBJECTDIR}/lcd_menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/lcd_menu.p1 lcd_menu.c 
	@${FIXDEPS} ${OBJECTDIR}/lcd_menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd_trials_4bits.p1: lcd_trials_4bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_trials_4bits.p1.d 
	@${RM} ${OBJECTDIR}/lcd_trials_4bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/lcd_trials_4bits.p1 lcd_trials_4bits.c 
	@${FIXDEPS} ${OBJECTDIR}/lcd_trials_4bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1853830924/busyxlcd.p1: ../../common/sources/plib/XLCD/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1 ../../common/sources/plib/XLCD/busyxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/busyxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/openxlcd.p1: ../../common/sources/plib/XLCD/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/openxlcd.p1 ../../common/sources/plib/XLCD/openxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/openxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/putrxlcd.p1: ../../common/sources/plib/XLCD/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1 ../../common/sources/plib/XLCD/putrxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/putrxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/putsxlcd.p1: ../../common/sources/plib/XLCD/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1 ../../common/sources/plib/XLCD/putsxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/putsxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/readaddr.p1: ../../common/sources/plib/XLCD/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readaddr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readaddr.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/readaddr.p1 ../../common/sources/plib/XLCD/readaddr.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/readaddr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/readdata.p1: ../../common/sources/plib/XLCD/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readdata.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/readdata.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/readdata.p1 ../../common/sources/plib/XLCD/readdata.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/readdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/setcgram.p1: ../../common/sources/plib/XLCD/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setcgram.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setcgram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/setcgram.p1 ../../common/sources/plib/XLCD/setcgram.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/setcgram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/setddram.p1: ../../common/sources/plib/XLCD/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setddram.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/setddram.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/setddram.p1 ../../common/sources/plib/XLCD/setddram.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/setddram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1: ../../common/sources/plib/XLCD/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1 ../../common/sources/plib/XLCD/wcmdxlcd.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/wcmdxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1853830924/writdata.p1: ../../common/sources/plib/XLCD/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1853830924" 
	@${RM} ${OBJECTDIR}/_ext/1853830924/writdata.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1853830924/writdata.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1853830924/writdata.p1 ../../common/sources/plib/XLCD/writdata.c 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1853830924/writdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd_menu.p1: lcd_menu.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_menu.p1.d 
	@${RM} ${OBJECTDIR}/lcd_menu.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/lcd_menu.p1 lcd_menu.c 
	@${FIXDEPS} ${OBJECTDIR}/lcd_menu.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/lcd_trials_4bits.p1: lcd_trials_4bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_trials_4bits.p1.d 
	@${RM} ${OBJECTDIR}/lcd_trials_4bits.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/lcd_trials_4bits.p1 lcd_trials_4bits.c 
	@${FIXDEPS} ${OBJECTDIR}/lcd_trials_4bits.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../common/include/plib" -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/lcd_menu_centered.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
