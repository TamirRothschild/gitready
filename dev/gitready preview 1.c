#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
 printf("Choose System :\n");
    printf("1. Archlinux\n");
    printf("2. Debian\n");
    printf("3. Option C\n");
    printf("4. Option D\n");

    int system_ver;
    scanf("%d", &system_ver);

 printf("Choose Desktop :\n");
    printf("1. Gnome\n");
    printf("2. Kde\n");
    printf("3. Xfce\n");
    printf("4. LXDE\n");

    int desktop;
    scanf("%d", &desktop);

 printf("Choose Display Server :\n");
    printf("1. x11\n");
    printf("2. wayland\n");

    int display_server;
    scanf("%d", &display_server);

 printf("Choose Display Manager :\n");
    printf("1. Console\n");
    printf("2. Graphical\n");

    int display_manager_type;
    scanf("%d", &display_manager_type);

   int returnCode;

    int display_manager_console;
    if(display_manager_type == 1) {
     printf("Choose Display Manager :\n");
     printf("1. Archlinux\n");
     printf("2. Debian\n");
     printf("3. Option C\n");
     printf("4. Option D\n");
            scanf("%d", &display_manager_console);}

    int display_manager_graphical;
    if(display_manager_type == 2) {
     printf("Choose Display Manager :\n");
     printf("1. GDM\n");
     printf("2. SDDM\n");
     printf("3. LightDM\n");
     printf("4. LXDM\n");
            scanf("%d", &display_manager_graphical);}


char sure[2];
printf("Do you wish to proceed with the process ? y/n\n");
printf("good luck then\n");
printf("you have 10 sec to regret use control + c (^c)\n");
sleep(10);
scanf("%2s", &sure);
if (strcasecmp(sure, "y") == 0) {
sleep(10);

//from here its the real install process

//[archlinux]
if (system_ver == 1){
   printf("archlinux install");
//display server 
  if (display_server == 1){   int returnCode = system("sudo pacman -S xorg-server xorg-xinit");}
  if (display_server == 2){   int returnCode = system("sudo pacman -S wayland");}
//desktop
  if (desktop == 1){   int returnCode = system("sudo pacman -S gnome");}
  if (desktop == 2){   int returnCode = system("sudo pacman -S plasma");}
  if (desktop == 3){   int returnCode = system("sudo pacman -S xfce4");}
  if (desktop == 4){   int returnCode = system("sudo pacman -S lxde");}
//display manager graphical
  if (display_manager_graphical == 1){   int returnCode = system("sudo pacman -S gdm");}
  if (display_manager_graphical == 2){   int returnCode = system("sudo pacman -S sddm");}
  if (display_manager_graphical == 3){   int returnCode = system("sudo pacman -S lightdm");}
  if (display_manager_graphical == 4){   int returnCode = system("sudo pacman -S lxdm");}
 }
//[Debian]
if (system_ver == 2){
 // Display server
    if (display_server == 1) {
        returnCode = system("sudo apt-get install xserver-xorg");
    }
    if (display_server == 2) {
        returnCode = system("sudo apt-get install wayland");
    }

    // Desktop environments
    if (desktop == 1) {
        returnCode = system("sudo apt-get install gnome");
    }
    if (desktop == 2) {
        returnCode = system("sudo apt-get install kde-plasma-desktop");
    }
    if (desktop == 3) {
        returnCode = system("sudo apt-get install xfce4");
    }
    if (desktop == 4) {
        returnCode = system("sudo apt-get install lxde");
    }

    // Display manager (graphical)
    if (display_manager_graphical == 1) {
        returnCode = system("sudo apt-get install gdm3");
    }
    if (display_manager_graphical == 2) {
        returnCode = system("sudo apt-get install sddm");
    }
    if (display_manager_graphical == 3) {
        returnCode = system("sudo apt-get install lightdm");
    }
    if (display_manager_graphical == 4) {
        returnCode = system("sudo apt-get install lxdm");
 }
        }
    }

    return 0;
}




