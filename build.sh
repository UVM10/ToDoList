#!/bin/bash

if [ ! -f Todolist.c ]; then

	echo "No source file found!"
else

	gcc Todolist.c -o Todolist

fi

if [$? -eq 0]; then

	echo "Complete!"

else

	echo "Error!"
	exit 1

fi
