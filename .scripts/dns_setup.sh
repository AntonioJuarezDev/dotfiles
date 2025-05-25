#!/bin/bash

sudo systemctl enable systemd-resolved

cp /usr/lib/systemd/resolved.conf /etc/systemd/
cat ~/dotfiles/.scripts/.dns_info | sudo tee -a /etc/systemd/resolved.conf > /dev/null

sudo ln -sf /run/systemd/resolve/stub-resolv.conf /etc/resolv.conf
sudo systemctl restart systemd-resolved
sudo systemctl restart NetworkManager
