#!/bin/bash

# setup dns

sh ~/dotfiles/scripts/dns_setup.sh

# homebrew install

sh ~/dotfiles/scripts/install_brew.sh

# fedora installs

sh ~/dotfiles/scripts/fedora_installs.sh

# install flatpaks

sh ~/dotfiles/scripts/flatpaks.sh

# install brew recommended

brew install gcc

# install fonts

brew install --cask font-fira-code
brew install --cask font-fira-code-nerd-font

# install tools

brew install stow
brew install tmux

# append config to .bash_profile

cat ~/dotfiles/config_files/.profile >> ~/.bash_profile

# stow: Create a Symlink of my config files to the home folder

stow -d ~/dotfiles/stow_files -t ~/

source ~/.bash_profile
