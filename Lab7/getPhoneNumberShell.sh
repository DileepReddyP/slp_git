#!/bin/bash
#
# Dileep Reddy
# Lab 7
# 10/12/2021
# Program to accept and print out purchase data in specific format 
# 
echo -n "Enter phone number [(999)999-9999]: "
read phno
phno="`echo $phno | sed -E 's/\(([0-9]{3})\)([0-9]{3})\-([0-9]{4})/\1\-\2\-\3/g'`"
echo "You entered $phno"                        