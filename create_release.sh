#! /bin/bash

GAME_NAME="TextGame"
GAME_VERSION="v0.01Dev"
CPU_TYPE=$(uname -m)
EXTENTION=".tgz"
OS_TYPE=$(uname -s)
FILENAME="${GAME_NAME}_${GAME_VERSION}_${OS_TYPE}_${CPU_TYPE}${EXTENTION}"

mkdir -p release
mkdir -p release/TextGame

cp -r bin release/TextGame
cp run_game.sh release/TextGame/
cd release
if [ -d "TextGame/bin/saves" ]; then
  rm -rf TextGame/bin/saves
fi

tar -cvf"$FILENAME" TextGame

rm -rf TextGame


