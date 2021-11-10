#!/bin/bash
# Dileep Reddy, Midterm Fall 2021
# program to count the number of statements in a file

myexamfile="myexamfile.txt"

count="`egrep -o '[^\.]+\.' myexamfile.txt | wc -l | sed 's/ //g'`"


#part a
echo "Number of statements in the file is $count"

#part b
tempfile=$(mktemp)
egrep -o '[^\.]+\.' myexamfile.txt > $tempfile
echo
echo "Number of words and characters in each statement is:"
i=1
echo "----------------------------"
echo " Line|   Words|  Characters|"
echo "----------------------------"
while read line
do 
    characters=`echo $line | wc -c| sed 's/ //g'`
    words=`echo $line | wc -w| sed 's/ //g'`
    awk -v i="$i" -v c="$characters" -v w="$words" 'BEGIN{printf "|%4s|%8s|%12s|\n", i, w, c}' 

    i=`expr $i + 1`
done < "$tempfile"

rm "$tempfile"