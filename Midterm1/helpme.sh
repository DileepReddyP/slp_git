#!/bin/bash
# Dileep Reddy, Midterm Fall 2021
# program to make a simple manual for 10 commands

mandatabase="mandatabase.txt"

echo -n "Enter a command: "
read input
# awk -> GAWK replacement because it is called GAWK in the man entry
input=`echo $input |sed 's/awk/GAWK/g'| awk '{print toupper($0)}'`

if [ -n "`grep -i "$input(1)" "$mandatabase"`" ]
then
    sed -n "/^$input(1)/,/$input(1)$/p" "$mandatabase" | more
else
    echo 'sorry, I cannot help you'
fi