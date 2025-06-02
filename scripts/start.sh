#!/bin/bash

# setup dns

sh ~/dotfiles/.scripts/dns_setup.sh

# install flatpaks

sh ~/dotfiles/.scripts/flatpaks.sh

# install fonts

brew install --cask font-fira-code
brew install --cask font-fira-code-nerd-font

# install tools

brew install stow
brew install tmux

# append config to .bash_profile

cat ~/dotfiles/.scripts/.profile >> ~/.bash_profile

# stow: Create a Symlink of my config files to the home folder

stow -d ~/dotfiles -t ~/

source ~/.bash_profile
