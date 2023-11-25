#!/bin/bash

echo "Choose System :"
echo "1. Archlinux"
echo "2. Debian"
# echo "3. Option C"
# echo "4. Option D"

read -p "Enter your choice: " system_ver

echo "Choose Desktop :"
echo "1. Gnome"
echo "2. Kde"
echo "3. Xfce"
echo "4. LXDE"

read -p "Enter your choice: " desktop

echo "Choose Display Server :"
echo "1. x11"
echo "2. wayland"

read -p "Enter your choice: " display_server

echo "Choose Display Manager :"
echo "1. Console"
echo "2. Graphical"

read -p "Enter your choice: " display_manager_type

display_manager_console=""
display_manager_graphical=""

if [ $display_manager_type -eq 1 ]; then
    echo "Choose Display Manager :"
    echo "1. Archlinux"
    echo "2. Debian"
    echo "3. Option C"
    echo "4. Option D"
    
    read -p "Enter your choice: " display_manager_console
fi

if [ $display_manager_type -eq 2 ]; then
    echo "Choose Display Manager :"
    echo "1. GDM"
    echo "2. SDDM"
    echo "3. LightDM"
    echo "4. LXDM"
    
    read -p "Enter your choice: " display_manager_graphical
fi

read -p "Do you wish to proceed with the process? (y/n): " sure

if [ "$sure" = "y" ]; then
    echo "Good luck then"
    echo "You have 10 seconds to regret. Use Ctrl+C (^C) to abort."
    sleep 10

    # Archlinux
    if [ $system_ver -eq 1 ]; then
        echo "Archlinux install"
        
        # Display server
        if [ $display_server -eq 1 ]; then
            sudo pacman -S xorg-server xorg-xinit
        fi
        if [ $display_server -eq 2 ]; then
            sudo pacman -S wayland
        fi

        # Desktop
        if [ $desktop -eq 1 ]; then
            sudo pacman -S gnome
        fi
        if [ $desktop -eq 2 ]; then
            sudo pacman -S plasma
        fi
        if [ $desktop -eq 3 ]; then
            sudo pacman -S xfce4
        fi
        if [ $desktop -eq 4 ]; then
            sudo pacman -S lxde
        fi

        # Display manager graphical
        if [ $display_manager_graphical -eq 1 ]; then
            sudo pacman -S gdm
        fi
        if [ $display_manager_graphical -eq 2 ]; then
            sudo pacman -S sddm
        fi
        if [ $display_manager_graphical -eq 3 ]; then
            sudo pacman -S lightdm lightdm-gtk-greeter
            sudo systemctl enable lightdm
            sudo systemctl start lightdm
        fi
        if [ $display_manager_graphical -eq 4 ]; then
            sudo pacman -S lxdm
        fi
    fi

    # Debian
    if [ $system_ver -eq 2 ]; then
        # Display server
        if [ $display_server -eq 1 ]; then
            sudo apt-get install xserver-xorg
        fi
        if [ $display_server -eq 2 ]; then
            sudo apt-get install wayland
        fi

        # Desktop environments
        if [ $desktop -eq 1 ]; then
            sudo apt-get install gnome
        fi
        if [ $desktop -eq 2 ]; then
            sudo apt-get install kde-plasma-desktop
        fi
        if [ $desktop -eq 3 ]; then
            sudo apt-get install xfce4
        fi
        if [ $desktop -eq 4 ]; then
            sudo apt-get install lxde
        fi

        # Display manager graphical
        if [ $display_manager_graphical -eq 1 ]; then
            sudo apt-get install gdm3
        fi
        if [ $display_manager_graphical -eq 2 ]; then
            sudo apt-get install sddm
        fi
        if [ $display_manager_graphical -eq 3 ]; then
            sudo apt-get install lightdm
        fi
        if [ $display_manager_graphical -eq 4 ]; then
            sudo apt-get install lxdm
        fi
    fi
fi
