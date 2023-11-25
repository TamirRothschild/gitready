#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

// Function to install packages using the appropriate package manager
int installPackage(const char *packageManager, const char *packageName) {
    char command[100];
    sprintf(command, "sudo %s install %s", packageManager, packageName);
    return system(command);
}

// Callback function for the "Install" button
void on_install_button_clicked(GtkWidget *widget, gpointer data) {
    int system_ver = gtk_combo_box_get_active(GTK_COMBO_BOX(data));
    int desktop = gtk_combo_box_get_active(GTK_COMBO_BOX(data + 1));
    int display_server = gtk_combo_box_get_active(GTK_COMBO_BOX(data + 2));

    int returnCode = 0;

    if (system_ver == 0) {
        printf("Archlinux install\n");
        const char *packageManager = "pacman";

        // Install display server
        if (display_server == 0) {
            returnCode = installPackage(packageManager, "xorg-server xorg-xinit");
        } else if (display_server == 1) {
            returnCode = installPackage(packageManager, "wayland");
        }

        // Install desktop environment
        if (desktop == 0) {
            returnCode = installPackage(packageManager, "gnome");
        } else if (desktop == 1) {
            returnCode = installPackage(packageManager, "plasma");
        } else if (desktop == 2) {
            returnCode = installPackage(packageManager, "xfce4");
        } else if (desktop == 3) {
            returnCode = installPackage(packageManager, "lxde");
        }
    } else if (system_ver == 1) {
        printf("Debian install\n");
        const char *packageManager = "apt-get";

        // Install display server
        if (display_server == 0) {
            returnCode = installPackage(packageManager, "xserver-xorg");
        } else if (display_server == 1) {
            returnCode = installPackage(packageManager, "wayland");
        }

        // Install desktop environment
        if (desktop == 0) {
            returnCode = installPackage(packageManager, "gnome");
        } else if (desktop == 1) {
            returnCode = installPackage(packageManager, "kde-plasma-desktop");
        } else if (desktop == 2) {
            returnCode = installPackage(packageManager, "xfce4");
        } else if (desktop == 3) {
            returnCode = installPackage(packageManager, "lxde");
        }
    }

    if (returnCode != 0) {
        printf("Installation failed with error code %d\n", returnCode);
    } else {
        printf("Installation completed successfully!\n");
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Linux Package Installer");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box to hold the widgets
    GtkWidget *vbox = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // System selection
    GtkWidget *system_label = gtk_label_new("Choose System:");
    gtk_box_pack_start(GTK_BOX(vbox), system_label, FALSE, FALSE, 0);

    const gchar *system_options[] = {"Archlinux", "Debian", NULL};
    GtkWidget *system_combo = gtk_combo_box_text_new_with_entry();
    for (int i = 0; system_options[i]; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(system_combo), system_options[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(system_combo), 0);
    gtk_box_pack_start(GTK_BOX(vbox), system_combo, FALSE, FALSE, 0);

    // Desktop selection
    GtkWidget *desktop_label = gtk_label_new("Choose Desktop:");
    gtk_box_pack_start(GTK_BOX(vbox), desktop_label, FALSE, FALSE, 0);

    const gchar *desktop_options[] = {"Gnome", "Kde", "Xfce", "LXDE", NULL};
    GtkWidget *desktop_combo = gtk_combo_box_text_new_with_entry();
    for (int i = 0; desktop_options[i]; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(desktop_combo), desktop_options[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(desktop_combo), 0);
    gtk_box_pack_start(GTK_BOX(vbox), desktop_combo, FALSE, FALSE, 0);

    // Display server selection
    GtkWidget *display_server_label = gtk_label_new("Choose Display Server:");
    gtk_box_pack_start(GTK_BOX(vbox), display_server_label, FALSE, FALSE, 0);

    const gchar *display_server_options[] = {"x11", "wayland", NULL};
    GtkWidget *display_server_combo = gtk_combo_box_text_new_with_entry();
    for (int i = 0; display_server_options[i]; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(display_server_combo), display_server_options[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(display_server_combo), 0);
    gtk_box_pack_start(GTK_BOX(vbox), display_server_combo, FALSE, FALSE, 0);

    // Install button
    GtkWidget *install_button = gtk_button_new_with_label("Install");
    g_signal_connect(install_button, "clicked", G_CALLBACK(on_install_button_clicked), system_combo);
    gtk_box_pack_start(GTK_BOX(vbox), install_button, FALSE, FALSE, 0);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

