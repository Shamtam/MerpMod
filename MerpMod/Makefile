SHELL=/bin/bash

export TCDIR=/usr/share/gnush_v13.01_elf-1
export PROJDIR=/data/MerpMod/MerpMod
export PROJNAME=MerpMod

# most targets require TARGETROM
ifdef TARGETROM

CC=sh-elf-gcc
AS=sh-elf-as
LD=sh-elf-ld

LIBS=$(BUILDDIR)/lib$(PROJNAME).a

MAIN_INC=$(wildcard $(PROJDIR)/include/*.h)
TARGET_INC=$(wildcard $(PROJDIR)/Targets/$(TARGETROM)/$(TARGETROM).h)
LINK_INC=$(wildcard $(PROJDIR)/Targets/$(TARGETROM)/$(TARGETROM).txt)

C_SRC=$(shell find $(PROJDIR) -name "*.c" ! -path "$(PROJDIR)/build/*")
C_OBJS=$(C_SRC:%.c=$(BUILDDIR)/%.o)

A_SRC=$(shell find $(PROJDIR) -name "*.s" ! -path "$(PROJDIR)/build/*")
A_OBJS=$(A_SRC:%.s=$(BUILDDIR)/%.o)

OBJS=$(C_OBJS) $(A_OBJS) $(LIBS)

OUT_FILE=$(OUTDIR)/$(PROJNAME).mot

set-env:
    export PATH:=$(TCDIR)/bin:$(PATH)
    export INCLUDE:=$(TCDIR)/include
    export BUILDDIR:=$(PROJDIR)/build/$(TARGETROM)/work
    export OUTDIR:=$(PROJDIR)/build/$(TARGETROM)

build-dir: set-env
	mkdir -p $(BUILDDIR)

$(LIBS): LGFLAGS=$\
    --compiler-options=-m2e,$\
    -mrenesas,$\
    -mieee,$\
    -Os,$\
    -fdata-sections,$\
    -ffunction-sections,$\
    -falign-jumps,$\
    -fno-function-cse,$\
    -funit-at-a-time
$(LIBS): | build-dir
	@echo
	@echo "Library Generation..."
	sh-elf-libgen $(LGFLAGS) --output="$(BUILDDIR)/lib$(PROJNAME).a" --select-lib=optlib --header-files=math

libgen: $(LIBS)

# compile
$(C_OBJS):\
    CFLAGS=\
        -Wall\
        -c\
        -x c\
        -m2e\
        -mrenesas\
        -mieee\
        -I "$(TCDIR)/sh-elf/sh-elf/optlibinc"\
        -I "$(TCDIR)/sh-elf/lib/gcc/sh-elf/4.7-GNUSH_v13.01/optlibinc"\
        -I "$(PROJDIR)/include"\
        -I "$(PROJDIR)/Targets/$(TARGETROM)"\
        -D _TARGET_HEADER_=$(TARGETROM).h\
        -nostdinc\
        -g\
        -g2
$(BUILDDIR)/%.o: %.c | build-dir
	@echo
	@echo "Compiling $<..."
	@if test -f $(<:c=asmflags); then \
		$(CC) `eval "echo \"$$(< $(<:c=asmflags))\""` -o $(BUILDDIR)/$(notdir $*).s $<; \
	elif test -f $(<:c=objflags); then \
		$(CC) `eval "echo \"$$(< $(<:c=objflags))\""` -o $(BUILDDIR)/$(notdir $*).o $<; \
	else \
		$(CC) $(CFLAGS) -o $(BUILDDIR)/$(notdir $@) $<; \
	fi

compile: $(C_OBJS)

# assemble
$(A_OBJS):
    ASFLAGS=\
        -renesas\
        -I "$(BUILDDIR)"\
        --gdwarf2
$(BUILDDIR)/%.o: %.s | compile build-dir
	@echo
	@echo "Assembling $<..."
	@if test -f $(<:s=flags); then \
		$(AS) `eval "echo \"$$(< $(<:s=flags))\""` -o $(BUILDDIR)/$(notdir $*).o $<; \
	else \
		$(AS) $(ASFLAGS) -o $(BUILDDIR)/$(notdir $@) $<; \
	fi

assemble: $(A_OBJS)

$(OUT_FILE):\
    LDFLAGS=\
        -L "$(TCDIR)/lib/gcc/sh-elf/4.7-GNUSH_v13.01"\
        -L "$(TCDIR)/lib/gcc/sh-elf/4.7-GNUSH_v13.01/mrenesas/m2e"\
        -L "$(BUILDDIR)"\
        -renesas\
        --start-group\
        -l "$(PROJNAME)"\
        -l "gcc-Os-4-200"\
        -l "gcc"\
        --end-group\
        -e _ResetHandler\
		-T "$(PROJDIR)/include/LinkerScript.txt"\
        -T "$(PROJDIR)/Targets/$(TARGETROM)/$(TARGETROM).txt"
$(OUT_FILE): $(OBJS) $(LINK_INC) | build-dir
	@echo
	@echo "Linking..."
	@sh-elf-ld $(BUILDDIR)/*.o $(LDFLAGS) --oformat srec -o $(OUT_FILE)

link: $(OUT_FILE)

all: link

.PHONY: clean
clean: set-env
	rm -rf $(OUTDIR)/

endif

# no TARGETROM  specified
ifndef TARGETROM
$(info TARGETROM unspecified, only available target is `clean-all`)

default:

.PHONY: clean-all
clean-all:
	rm -rf $(PROJDIR)/build/

endif