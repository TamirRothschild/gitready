#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
 printf("Choose System :\n");
    printf("1. Archlinux\n");
    printf("2. Debian\n");
    printf("3. Option C\n");
    printf("4. Option D\n");

    int system;
    scanf("%d", &system);

 printf("Choose Desktop :\n");
    printf("1. Gnome\n");
    printf("2. Kde\n");
    printf("3. Xfce\n");
    printf("4. LXDE\n");

    int desktop;]
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


    if(display_manager_type == 1) {
     printf("Choose Display Manager :\n");
     printf("1. Archlinux\n");
     printf("2. Debian\n");
     printf("3. Option C\n");
     printf("4. Option D\n");
            scanf("%d", &display_manager_console);}

    if(display_manager_type == 2) {
     printf("Choose Display Manager :\n");
     printf("1. GDM\n");
     printf("2. SDDM\n");
     printf("3. LightDM\n");
     printf("4. LXDM\n");
            scanf("%d", &display_manager_graphical);}


char sure[2];
printf("Do you wish to proceed with the process ? y/n");
scanf("%is", &sure);
if (strcasecmp(userChoice, "y") == 0) {
printf("good luck then");
printf("you have 10 sec to regret use control + c (^c)");
sleep(10);

//from here its the real install process

//[archlinux]
if (system == 1){
   printf("archlinux install");
//display server 
  if (display_server == 1){   int returnCode = system("sudo pacman -S xorg-server");}
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

//[Debian] -- need to update this, as it was dane by chatGPT 3.5 and it 6am rn
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







