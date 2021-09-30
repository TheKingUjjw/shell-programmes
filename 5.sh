# Write a shell script to print a number in reverse order

#! /bin/bash

echo "Enter the number to be reversed"
read number
while [ $number -gt 0 ] 
do
	remainder=$(( number%10 ))
	printf $remainder
	number=$(( number/10 ))
done
echo
