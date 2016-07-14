#!/bin/bash

help_msg()
{
	echo 'Usage: inc pattern file [{+,-}cnt]'
}

if [ $# -eq 0 -o "$1" = "--help" -o "$1" = "-h" ]
then
	help_msg
	exit 0
fi

get_args()
{
	pattern=$1
	file=$2
	if [ -z "$3" ]
	then
		cnt=1
	else
		cnt=$3
	fi
}

get_args $*

# three cases:
# vsys -> oldnum = "vsys"
# vsys 3 -> oldnum = "3"
# (empty) -> oldnum = ""

oldnum=`grep $pattern $file | cut -d ' ' -f2`
if [ -n "$oldnum" ]
# if oldnum is non zero
then
	if [ "$oldnum" -eq "$oldnum" ] 2> /dev/null
	# if oldnum is an integer
	then
		newnum=$((oldnum + $cnt))
		sed -i "s/$pattern $oldnum/$pattern $newnum/" $file
	elif [ $oldnum = $pattern ]
		# if there is no oldnum after pattern
		# and oldnum does not differ from pattern
	then
 		sed -i "s/^$pattern/$pattern $cnt/" $file
	fi
else
	echo $pattern $cnt >> $file
fi
