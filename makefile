SUBDIRS = src libraries
ALLDIRS = $(SUBDIRS) 

PLATFORM := $(shell uname)

export PLATFORM:= $(PLATFORM)

export CFLAGS = -std=c++0x -O0 -I$(PWD)/include -v

ifeq ($(PLATFORM),Darwin)
export CFLAGS += -DOS_DARWIN --stdlib=libc++
export LFLAGS=-dynamiclib -single_module -undefined dynamic_lookup
export SHAREDSWITCH    = -install_name # ENDING SPACE
export CPP = xcrun clang++
else
export SHAREDSWITCH    = -shared -Wl,-soname,#NO ENDING SPACE
export CPP = g++
endif
export COMPILESHARED   = $(CPP) $(LFLAGS) $(SHAREDSWITCH)#NO ENDING SPACE

export BASE:= $(CURDIR)
#export MDASSYS:= /opt/midas-64

.PHONY: all subdirs $(ALLDIRS) clean 
all: print subdirs grsisort

print:
	echo $(PLATFORM)

subdirs: $(SUBDIRS)

src: libraries

$(ALLDIRS):
	@$(MAKE) -C $@

grsisort: src
	cp $^/grsisort bin/$@

clean:
	@$(RM) *~
	@for dir in $(ALLDIRS); do \
	$(MAKE) -C $$dir $@; \
	done

