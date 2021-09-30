# Write a shell program to print the following pattern upto n rows, for a
# given n.

#! /bin/bash

echo Enter the number of rows
read n
echo
for((i=1;i<=n;i++))
do
	for((j=1;j<=i;j++))
	do
		printf "$i "	
	done
	echo
done
