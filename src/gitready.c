#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    printf("Choose System:\n");
    printf("1. Archlinux\n");
    printf("2. Debian\n");

    int system_ver;
    scanf("%d", &system_ver);

    printf("Choose Desktop:\n");
    printf("1. Gnome\n");
    printf("2. Kde\n");
    printf("3. Xfce\n");
    printf("4. LXDE\n");

    int desktop;
    scanf("%d", &desktop);

    printf("Choose Display Server:\n");
    printf("1. x11\n");
    printf("2. wayland\n");

    int display_server;
    scanf("%d", &display_server);

    printf("Choose Display Manager Type:\n");
    printf("1. Console\n");
    printf("2. Graphical\n");

    int display_manager_type;
    scanf("%d", &display_manager_type);

    int returnCode = 0;

    int display_manager_console;
    if (display_manager_type == 1) {
        printf("Choose Console Display Manager:\n");
        printf("1. Option A\n");
        printf("2. Option B\n");
        printf("3. Option C\n");
        printf("4. Option D\n");
        scanf("%d", &display_manager_console);
        // Add your code for console display manager here
    }

    int display_manager_graphical;
    if (display_manager_type == 2) {
        printf("Choose Graphical Display Manager:\n");
        printf("1. GDM\n");
        printf("2. SDDM\n");
        printf("3. LightDM\n");
        printf("4. LXDM\n");
        scanf("%d", &display_manager_graphical);
        // Add your code for graphical display manager here
    }

    char sure[3];
    printf("Do you wish to proceed with the process? (y/n)\n");
    printf("Good luck then!\n");
    printf("You have 10 seconds to regret; use Ctrl + C (^C) to exit.\n");
    sleep(10);
    scanf("%2s", sure);

    if (strcasecmp(sure, "y") == 0) {
        sleep(10);

        if (system_ver == 1) {
            printf("Archlinux install\n");

            if (display_server == 1) {
                returnCode = system("sudo pacman -S xorg-server xorg-xinit");
            } else if (display_server == 2) {
                returnCode = system("sudo pacman -S wayland");
            }

            if (desktop == 1) {
                returnCode = system("sudo pacman -S gnome");
            } else if (desktop == 2) {
                returnCode = system("sudo pacman -S plasma");
            } else if (desktop == 3) {
                returnCode = system("sudo pacman -S xfce4");
            } else if (desktop == 4) {
                returnCode = system("sudo pacman -S lxde");
            }

            if (display_manager_graphical == 1) {
                returnCode = system("sudo pacman -S gdm");
            } else if (display_manager_graphical == 2) {
                returnCode = system("sudo pacman -S sddm");
            } else if (display_manager_graphical == 3) {
                returnCode = system("sudo pacman -S lightdm lightdm-gtk-greeter");
                if (returnCode == 0) {
                    returnCode = system("sudo systemctl enable lightdm");
                    if (returnCode == 0) {
                        returnCode = system("sudo systemctl start lightdm");
                    }
                }
            } else if (display_manager_graphical == 4) {
                returnCode = system("sudo pacman -S lxdm");
            }
        } else if (system_ver == 2) {
            printf("Debian install\n");

            if (display_server == 1) {
                returnCode = system("sudo apt-get install xserver-xorg");
            } else if (display_server == 2) {
                returnCode = system("sudo apt-get install wayland");
            }

            if (desktop == 1) {
                returnCode = system("sudo apt-get install gnome-core");
            } else if (desktop == 2) {
                returnCode = system("sudo apt-get install kde-plasma-desktop");
            } else if (desktop == 3) {
                returnCode = system("sudo apt-get install xfce4");
            } else if (desktop == 4) {
                returnCode = system("sudo apt-get install lxde");
            }

            if (display_manager_graphical == 1) {
                returnCode = system("sudo apt-get install gdm3");
            } else if (display_manager_graphical == 2) {
                returnCode = system("sudo apt-get install sddm");
            } else if (display_manager_graphical == 3) {
                returnCode = system("sudo apt-get install lightdm");
            } else if (display_manager_graphical == 4) {
                returnCode = system("sudo apt-get install lxdm");
            }
        }
    }

    if (returnCode != 0) {
        printf("Installation failed with error code %d\n", returnCode);
    } else {
        printf("Installation completed successfully!\n");
    }

    return returnCode;
}