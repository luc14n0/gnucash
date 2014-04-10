/*
 * business-gnome-utils.h -- General GUI Utilities for GNC Business Objects
 *
 * Written By: Derek Atkins <warlord@MIT.EDU>
 * Copyright (C) 2001
 */

#ifndef GNC_BUSINESS_GNOME_UTILS_H_
#define GNC_BUSINESS_GNOME_UTILS_H_

#include "gnc-book.h"
#include "gncOwner.h"
#include "gncBillTerm.h"
#include "gncTaxTable.h"

GtkWidget * gnc_owner_select_create (GtkWidget *label, GtkWidget *hbox,
				     GNCBook *book, GncOwner *owner);

GtkWidget * gnc_owner_edit_create (GtkWidget *label, GtkWidget *hbox,
				   GNCBook *book, GncOwner *owner);

void gnc_owner_get_owner (GtkWidget *widget, GncOwner *owner);
void gnc_owner_set_owner (GtkWidget *widget, GncOwner *owner);


/* Return a list of account-types based on the owner type */
GList * gnc_business_account_types (GncOwner *owner);

/* Fill in a combo box with the appropriate list of accounts */
void gnc_fill_account_select_combo (GtkWidget *combo, GNCBook *book,
				    GList *acct_types);


/* Create an optionmenu of available billing terms and attach it to
 * the menu passed in.  If none_ok is true, then add "none" as a
 * choice (with data set to NULL).  Any time the menu changes,
 * 'choice' will be set to the chosen option.  If *choice is non-NULL,
 * then that will be the default option setting when the menu is
 * created.
 */
void gnc_ui_billterms_optionmenu (GtkWidget *omenu, GNCBook *book,
				  gboolean none_ok, GncBillTerm **choice);

/* Same thing except for the tax tables */
void
gnc_ui_taxtables_optionmenu (GtkWidget *omenu, GNCBook *book,
			     gboolean none_ok, GncTaxTable **choice);

/* Build an option menu for choosing a GncTaxIncluded */
void gnc_ui_taxincluded_optionmenu (GtkWidget *omenu, GncTaxIncluded *choice);


/* Here are some "generic option menu" utilities that can be used with
 * ANY of the above option-menu types.  In particular the following
 * functions are useful for hooking the above option menus into the
 * GNC Option infrastructure.
 */

void gnc_ui_optionmenu_set_changed_callback (GtkWidget *omenu,
					     void (*changed_cb)(GtkWidget*,gpointer),
					     gpointer cb_arg);
gpointer gnc_ui_optionmenu_get_value (GtkWidget *omenu);
void gnc_ui_optionmenu_set_value (GtkWidget *omenu, gpointer data);


#endif /* GNC_BUSINESS_GNOME_UTILS_H_ */
