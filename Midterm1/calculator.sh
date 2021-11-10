#!/bin/bash
# Dileep Reddy, Midterm Fall 2021
# program to make a simple calculator

while [ "$exp" != "close" ]
do
    echo Simple Calculator, enter an expression with two variables to evaluate it
    echo Type 'clear' to clear, 'close' to close

    read -r exp
    #regular expression used here to change the spacing of the 
    case $exp in
        [Cc]lear)
            clear
            ;;
        [Cc]lose)
            echo Goodbye!
            exp='close'
            ;;
        *)
            exp="`echo $exp | sed -E "s/([-+/*%])/ \1 /g"`"
            read a oper b <<< "$exp"
            echo -n "$a" "$oper" "$b"
            case "$oper" in
                "+")
                    awk -v a=$a -v b=$b 'BEGIN{printf " = %.2f\n", a+b}'
                    ;;
                "-")
                    awk -v a=$a -v b=$b 'BEGIN{printf " = %.2f\n", a-b}'
                    ;;
                "/")
                    awk -v a=$a -v b=$b 'BEGIN{printf " = %.2f\n", a/b}'
                    ;;
                "*")
                    awk -v a=$a -v b=$b 'BEGIN{printf " = %.2f\n", a*b}'
                    ;;
                "%")
                    awk -v a=$a -v b=$b 'BEGIN{printf " = %.2f\n", a%b}'
                    ;;
                *)
                    echo Input unrecognized
                    ;;
            esac
            ;;
    esac
done

printf("ASCII value = %d, Character = %c\n", ch , ch );