#! /bin/bash

clear

if [ -e bin/TextGame ]; then
	cd bin
	./TextGame $@
else
	echo "TextGame not found."
	echo "Try running 'make'"
fi


