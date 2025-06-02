#!/bin/bash
# Custom PS1

HOSTN_FG=36
HOSTN_BRKT_FG=90
GIT_FG=35
DIR_FG=33
PROMPT_FG=35

git_branch() {
  git -C . rev-parse 2>/dev/null
  if [[ "$?" -eq 0 ]]; then
    echo " $(git symbolic-ref --short HEAD)  "
  fi
}

CHECK="\$([[ \$? == 0 ]] && echo -e \[\033[32m\]❙ || echo -e \[\033[31m\]❙) "
HOSTN="\[\033[1;${HOSTN_BRKT_FG}m\]〔\[\033[1;${HOSTN_FG}m\]\$(hostname)\[\033[1;${HOSTN_BRKT_FG}m\]〕 "
GIT_BRANCH="\[\033[1;${GIT_FG}m\]\$(git_branch)"
CURRENT_DIR="\[\033[1;${DIR_FG}m\]\w\n"
#P_PROMPT="\[\033[0;${P_PROMPT_FG}m\]➤\[\033[0;39;49m\] "
PROMPT="\[\033[${PROMPT_FG}m\]ᐳ\[\033[0;39;49m\] "

PS1="${CHECK}${HOSTN}${GIT_BRANCH}${CURRENT_DIR}${PROMPT}"
export PS1

# END
