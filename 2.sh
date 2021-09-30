# Write a shell script which accepts any number of arguments and prints
# them in the reverse order


#! /bin/bash

length=$#
arr=("$@")

echo "No of arguments are $length"
printf "Arguments in reverse order "
n=$((length-1))
for ((i=$n;i>=0;i--))
do
	printf "${arr[$i]} "	
done
echo 
