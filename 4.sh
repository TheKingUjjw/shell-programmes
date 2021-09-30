# Write a shell script to find smallest of 3 numbers that are read from
# keyboard.

#! /bin/bash

echo "Enter the three numbers"
read -a arr
min=${arr[0]}
for ((i=0;i<3;i++))
do
	if [ $min -ge  ${arr[$i]} ]
	then
		min=${arr[$i]}
        fi        		
done
echo "The smallest number is $min"
