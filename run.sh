#!/bin/bash

if [ ! -f Todolist ]; then
    
	echo "Can't find Todolist!"
	exit 1

fi

./Todolist
