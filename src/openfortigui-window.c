/* openfortigui-window.c
 *
 * Copyright 2025 vboxuser
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"
#include <glib.h>
#include "openfortigui-window.h"

struct _OpenfortiguiWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
	AdwHeaderBar        *header_bar;
	GtkLabel            *label;
        GtkButton *my_button; // <-- Add this line
};

G_DEFINE_FINAL_TYPE (OpenfortiguiWindow, openfortigui_window, ADW_TYPE_APPLICATION_WINDOW)



static void
openfortigui_window_init (OpenfortiguiWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
}

static void
on_connect_button_clicked(GtkButton *button, gpointer user_data)
{
  GError *error = NULL;
  g_print("Connect Button clicked!\n");

    if (!g_spawn_command_line_async("/usr/bin/gnome-calculator", &error)) {
        g_warning("Failed to launch command: %s", error->message);
        g_clear_error(&error);
    }

}
static void
on_disconnect_button_clicked(GtkButton *button, gpointer user_data)
{
  g_print("Disconnect Button clicked!\n");
}



static void
openfortigui_window_class_init (OpenfortiguiWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/OpenFortiGui/openfortigui-window.ui");
	gtk_widget_class_bind_template_child (widget_class, OpenfortiguiWindow, header_bar);
	gtk_widget_class_bind_template_child (widget_class, OpenfortiguiWindow, label);
        gtk_widget_class_bind_template_child(widget_class, OpenfortiguiWindow, my_button);
        gtk_widget_class_bind_template_callback(widget_class, on_connect_button_clicked);
        gtk_widget_class_bind_template_callback(widget_class, on_disconnect_button_clicked);

}
