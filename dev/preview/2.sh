#!/bin/bash

echo "Choose System:"
echo "1. Archlinux"
echo "2. Debian"

read system_ver

echo "Choose Desktop:"
echo "1. Gnome"
echo "2. Kde"
echo "3. Xfce"
echo "4. LXDE"

read desktop

echo "Choose Display Server:"
echo "1. x11"
echo "2. wayland"

read display_server

echo "Choose Display Manager Type:"
echo "1. Console"
echo "2. Graphical"

read display_manager_type

returnCode=0

if [ $display_manager_type -eq 1 ]; then
    echo "Choose Console Display Manager:"
    echo "1. Option A"
    echo "2. Option B"
    echo "3. Option C"
    echo "4. Option D"

    read display_manager_console
    # Add your code for console display manager here
fi

if [ $display_manager_type -eq 2 ]; then
    echo "Choose Graphical Display Manager:"
    echo "1. GDM"
    echo "2. SDDM"
    echo "3. LightDM"
    echo "4. LXDM"

    read display_manager_graphical
    # Add your code for graphical display manager here
fi

echo "Do you wish to proceed with the process? (y/n)"
echo "Good luck then!"
echo "You have 10 seconds to regret; use Ctrl + C (^C) to exit."

read -t 10 -n 1 sure

if [ "$sure" == "y" ] || [ "$sure" == "Y" ]; then
    sleep 10

    if [ $system_ver -eq 1 ]; then
        echo "Archlinux install"

        if [ $display_server -eq 1 ]; then
            returnCode=$(sudo pacman -S xorg-server xorg-xinit)
        elif [ $display_server -eq 2 ]; then
            returnCode=$(sudo pacman -S wayland)
        fi

        if [ $desktop -eq 1 ]; then
            returnCode=$(sudo pacman -S gnome)
        elif [ $desktop -eq 2 ]; then
            returnCode=$(sudo pacman -S plasma)
        elif [ $desktop -eq 3 ]; then
            returnCode=$(sudo pacman -S xfce4)
        elif [ $desktop -eq 4 ]; then
            returnCode=$(sudo pacman -S lxde)
        fi

        if [ $display_manager_graphical -eq 1 ]; then
            returnCode=$(sudo pacman -S gdm)
        elif [ $display_manager_graphical -eq 2 ]; then
            returnCode=$(sudo pacman -S sddm)
        elif [ $display_manager_graphical -eq 3 ]; then
            returnCode=$(sudo pacman -S lightdm lightdm-gtk-greeter)
            if [ $returnCode -eq 0 ]; then
                returnCode=$(sudo systemctl enable lightdm)
                if [ $returnCode -eq 0 ]; then
                    returnCode=$(sudo systemctl start lightdm)
                fi
            fi
        elif [ $display_manager_graphical -eq 4 ]; then
            returnCode=$(sudo pacman -S lxdm)
        fi
    elif [ $system_ver -eq 2 ]; then
        echo "Debian install"

        if [ $display_server -eq 1 ]; then
            returnCode=$(sudo apt-get install xserver-xorg)
        elif [ $display_server -eq 2 ]; then
            returnCode=$(sudo apt-get install wayland)
        fi

        if [ $desktop -eq 1 ]; then
            returnCode=$(sudo apt-get install gnome)
        elif [ $desktop -eq 2 ]; then
            returnCode=$(sudo apt-get install kde-plasma-desktop)
        elif [ $desktop -eq 3 ]; then
            returnCode=$(sudo apt-get install xfce4)
        elif [ $desktop -eq 4 ]; then
            returnCode=$(sudo apt-get install lxde)
        fi

        if [ $display_manager_graphical -eq 1 ]; then
            returnCode=$(sudo apt-get install gdm3)
        elif [ $display_manager_graphical -eq 2 ]; then
            returnCode=$(sudo apt-get install sddm)
        elif [ $display_manager_graphical -eq 3 ]; then
            returnCode=$(sudo apt-get install lightdm)
        elif [ $display_manager_graphical -eq 4 ]; then
            returnCode=$(sudo apt-get install lxdm)
        fi
    fi
fi

if [ $returnCode -ne 0 ]; then
    echo "Installation failed with error code $returnCode"
else
    echo "Installation completed successfully!"
fi

exit $returnCode
