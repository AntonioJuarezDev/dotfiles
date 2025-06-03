#!/bin/bash

sudo dnf update -y
sudo dnf -y group install development-tools
sudo dnf -y install alacritty distrobox
