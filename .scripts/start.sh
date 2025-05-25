#!/bin/bash

# install fonts

brew install --cask font-fira-code
brew install --cask font-fira-code-nerd-font

# install tools

brew install stow
brew install tmux

# append config to .bash_profile

cat .profile >> ~/.bash_profile

# stow: Create a Symlink of my config files to the home folder

stow -d ~/dotfiles -t ~/

source ~/.bash_profile
