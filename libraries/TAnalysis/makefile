SUBDIRS = TS3 TSiLi TRf TSharc TTigress
ALLDIRS = $(SUBDIRS) 
#LASTDIR = $(notdir $(CURDIR))

inclibs=  libTigress.so

inclibs+= libS3.so
inclibs+= libSiLi.so
inclibs+= libRfFitter.so


export CFLAGS += -fPIC

.PHONY: subdirs $(ALLDIRS) clean copy 
subdirs: $(SUBDIRS) 

$(ALLDIRS):
	@$(MAKE) -C $@
	#$(COMPILESHARED)$@ $(CFLAGS) -olibTAnalysis.so $(OBJECTS)

clean:
	@$(RM) *a *so *~
	@for dir in $(ALLDIRS); do \
	$(MAKE) -C $$dir $@; \
	done
