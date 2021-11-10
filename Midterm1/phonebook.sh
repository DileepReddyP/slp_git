#!/bin/bash
# Dileep Reddy, Midterm Fall 2021
# program to make a simple phonebook utility using sed and awk

phBook="Phonebook.txt"
tempfile=$(mktemp)

#Utility functions to display the phonebook in a reader-friendly format

#Parameters: 1) title of table 2) input to format
Display_Phonebook(){
    awk -F% -v title="$1" '
    BEGIN{
        format = "%-4s: %-20s %-11s %s\n"
        print "___________________________________________________________________________________"
        print title
        print "___________________________________________________________________________________"
        printf format, "No", "Name", "Phone", "Address"
    }
    {
        printf format, NR, $1, $2, $3
    }
    END{
        print "___________________________________________________________________________________"
    }
    ' $2 | more
}

#Parameters: 1) "change" | "delete" 2) file to store response
Find_in_Phonebook(){
    echo -n "Enter any part of name, phone no, or address to find entry to $1: "
    read query
    echo
    grep -in "$query" "$phBook" | sed -E 's/^(.+):/\1\%/' > "$2"
    awk -F% -v text=$1 '
    BEGIN{
        format = "%-4s: %-20s %-11s %s\n"
        printf format, "Line", "Name", "Phone", "Address"
    }
    {
        printf format, $1, $2, $3, $4
    }
    END{
        printf "Line number of entry to %s: ", text
    }' $2
}

echo
echo "Phonebook Utility [Show, Find, Add, Edit, Delete, Close]"

while [ "$option" != "CLOSE" ]
do
    if [ -e "$phBook" ]
    then 
        echo
        echo -n "Enter Option: "
        read option
        option=`echo $option | awk '{print toupper($0)}'`
        case "$option" in
            SHOW)
                Display_Phonebook "PHONE BOOK" $phBook
                ;;
            FIND)
                echo ""
                echo -n "Enter query (part of name, number or address): "
                read query
                grep -i "$query" "$phBook" > "$tempfile"
                if [ $? = 0 ]
                then 
                    Display_Phonebook "FIND RESULTS" $tempfile
                else 
                    echo "No entry containing $query found"
                fi
                ;;
            ADD)
                echo ""
                echo "Adding an entry"
                echo -n "Name: "
                read name
                echo -n "Phone no: "
                read phno
                echo -n "Address (in a single line): "
                read address
                #The awk and sort steps add the new entry in the format to the file and sort the file in alphabetical order
                awk -F% -v name="$name" -v ph="$phno" -v addr="$address" '{
                    print $1"%"$2"%"$3} END{print name"%"ph"%"addr
                }' "$phBook" > "$tempfile"
                sort -t% +0 -2 "$tempfile" > "$phBook"
                if [ $? = 0 ]
                then 
                    echo Successfully added
                    Display_Phonebook "ADDED ENTRY" $phBook
                fi
                ;;                 
            EDIT)
                Find_in_Phonebook "edit" $tempfile
                read lineNo
                name=$(grep "^$lineNo%" $tempfile | awk -F% '{print $2}')
                no=$(grep "^$lineNo%" $tempfile | awk -F% '{print $3}')
                addr=$(grep "^$lineNo%" $tempfile | awk -F% '{print $4}')
                echo "Type the new details for the entry, press enter to skip"
                echo -n "New name: "
                read newname
                echo -n "New number: "
                read newno
                echo -n "New address: "
                read newaddr
                if [ "$newname" != "" ]
                then 
                    name=$newname
                fi
                if [ "$newno" != "" ]
                then 
                    no=$newno
                fi
                if [ "$newaddr" != "" ]
                then 
                    addr=$newaddr
                fi
                echo $name $no $addr
                newentry="${name}%${no}%${addr}"
                cat $phBook > $tempfile
                #indentation here would add whitespace to the changed line
                sed "${lineNo}c\\ 
${newentry}
" $tempfile > $phBook
                if [ $? = 0 ]
                then 
                    echo "$newentry" > $tempfile
                    echo Successfully changed entry
                    Display_Phonebook "CHANGED ENTRY" $tempfile
                fi
                ;; 
            DELETE)
                Find_in_Phonebook "delete" $tempfile
                read lineNo
                cat "$phBook" > "$tempfile"
                sed "${lineNo}d" $tempfile > $phBook
                if [ $? = 0 ]
                then 
                    echo Successfully deleted entry
                fi
                ;;
            CLOSE)
                echo Goodbye!
                ;;
            *)
                echo Invalid option
                echo "Valid options are: show, find, add, edit, delete, close"
                ;;
        esac
    else
        touch "$phBook"
        # permission such that only the user can read or write to the phonebook
        chmod 600 "$phBook"
    fi
done
rm "$tempfile"