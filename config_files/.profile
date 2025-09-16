# Custom .bash_profile lines

if [ -f ~/prompt_min_v2.sh ]; then
  . ~/prompt_min_v2.sh
fi

PATH="$HOME/Documents/firefox_driver:$HOME/AppImages:$PATH"
export PATH

# alias

# utils
alias activate='source venv/bin/activate'
alias ll='ls -la'
alias curl='curl -OJ'

# manhwa
alias manhwa-util='python /home/antonio/Documents/py_scripts/manhwa_scrapper/main.py'

alias tapas-set-cookie='python /home/antonio/Documents/py_scripts/manhwa_scrapper/main.py tapasSetCookie'
alias tappy-set-bearer='python /home/antonio/Documents/py_scripts/manhwa_scrapper/main.py tappySetBearer'

alias webcomics-api='fastapi run main.py --host 0.0.0.0 --port 54515'

# video download
alias vid-dl='python /home/antonio/Documents/obsidian_vaults/Youtube_tracker/py_scripts/download_yt.py'
alias vidfile-dl='python /home/antonio/Documents/obsidian_vaults/Youtube_tracker/py_scripts/download_file.py'
alias sort-vid='python /home/antonio/Documents/obsidian_vaults/Youtube_tracker/py_scripts/sort_folders.py'

# archive download
alias archive_dl='python /home/antonio/Documents/py_scripts/dl_archive/main.py'

# disk usage
alias disk-usage='df -h /dev/sda3 --output=source,fstype,size,used,avail,pcent'
