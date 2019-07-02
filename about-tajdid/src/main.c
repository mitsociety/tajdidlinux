/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) adi sucipto 2011 <acepby@tajdidlinux.org>
 * 
 * about_tajdid is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * about_tajdid is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <config.h>

#include <gtk/gtk.h>



/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif



#include "callbacks.h"
#include "tampil.h"

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/about_tajdid/ui/about_tajdid.ui" */
#define UI_FILE "src/about_tajdid.ui"
	
GtkWidget*
create_window (void)
{
	GtkWidget *aboutdialog1,*label2,*label4;
	GtkBuilder *builder;
	GError* error = NULL;
	gchar *release,*versi;//variabel
	//int pjg;//variabel panjang
#define get_widget(name) ((GtkWidget *) gtk_builder_get_object (builder, name))

	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_warning ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	//perintah tampil release
	release=lsb ("lsb_release -sc");//perintah ke fungsi penampil lsb_release
	//release=scanf(release);
	//pjg=strlen(release);
	release=g_utf8_normalize(release,8,G_NORMALIZE_NFKC);
	//release=g_locale_to_utf8(release,-1,NULL,NULL,NULL);
	release=g_strdup(release);//salin hasil 

	//perintah tampil versi kernel
	versi=lsb ("uname -sr");
	versi=g_strdup_printf("%s",versi);


	/* This is important */
	gtk_builder_connect_signals (builder, NULL);

	//panggil dialog
	aboutdialog1=g_new(GtkWidget,1);
	aboutdialog1 = get_widget("aboutdialog1");

	//inisialisasi label yang akan digunakan
	label2=get_widget("label2");
	gtk_label_set_text(GTK_LABEL(label2),release);
	g_free(release);

	label4=get_widget("label4");
	gtk_label_set_text(GTK_LABEL(label4),versi);
	g_free(versi);
		
	g_object_unref (builder);
	return aboutdialog1;
}


int
main (int argc, char *argv[])
{
 	GtkWidget *aboutdialog1;
 	
//	GtkWidget *label;

#ifdef ENABLE_NLS
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif

	
	gtk_set_locale ();
	gtk_init (&argc, &argv);
	
	aboutdialog1 = create_window();
	gtk_dialog_run(GTK_DIALOG(aboutdialog1)); //fungsi dari GTK_DIALOG
	gtk_widget_destroy(aboutdialog1); //fungsi destroy dari GTK_DIALOG
	//gtk_widget_show_all (aboutdialog1);
	//gtk_main ();
	return 0;
}
