#!/bin/bash

if [!-f Todolist]; then

	echo "There's no executable file!"
	exit 1;

fi


./clean.sh
./build.sh
echo "Todolist has been succesfully updated!"
