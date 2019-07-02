## Process this file with automake to produce Makefile.in

## Created by Anjuta

uidir = $(datadir)/about_tajdid/ui
ui_DATA = about_tajdid.ui

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(ABOUT_TAJDID_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = about_tajdid

about_tajdid_SOURCES = \
	callbacks.c \
	callbacks.h \
	main.c \
	tampil.c \
	tampil.h

about_tajdid_LDFLAGS = \
	-Wl,--export-dynamic

about_tajdid_LDADD = $(ABOUT_TAJDID_LIBS)

EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/about_tajdid
