#!/bin/bash

if [ -f Todolist ]; then

    echo "Cleaning ..."
    rm -f Todolist
    echo "Complete!"

else

    echo "There are no executable files!"
    exit 1

fi

