#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Usage: `basename $0` script"
	exit 1
fi

	vim $(which $1)
