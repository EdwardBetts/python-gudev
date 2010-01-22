defsdir = $(datadir)/pygtk/2.0/defs
defs_DATA = gudev.defs

INCLUDES = \
	$(GUDEV_CFLAGS) \
	$(GOBJECT_CFLAGS) \
	$(PYGOBJECT_CFLAGS) \
	$(PYTHON_INCLUDES)

pkgpythondir = $(pyexecdir)/gtk-2.0
pkgpyexecdir = $(pyexecdir)/gtk-2.0

pkgpyexec_LTLIBRARIES = gudev.la
gudev_la_LDFLAGS = -module -avoid-version -export-symbols-regex initgudev
gudev_la_LIBADD = $(GUDEV_LIBS) $(GOBJECT_LIBS) $(PYGOBJECT_LIBS)
gudev_la_SOURCES = gudevmodule.c gudev.c
#nodist_gudev_la_SOURCES = gudev.c

CLEANFILES = gudev.c
EXTRA_DIST = gudev.override $(defs_DATA)

gudev.c: gudev.defs gudev.override
.defs.c:
	(cd $(srcdir)\
	 && $(PYGOBJECT_CODEGEN) \
		--override $*.override \
		--prefix py$* $*.defs) > gen-$*.c \
	&& cp gen-$*.c $*.c \
	&& rm -f gen-$*.c

update-defs:
	$(PYGOBJECT_H2DEF) /usr/include/gudev-1.0/gudev/*.h > gudev-new.defs
	
