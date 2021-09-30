# Write a shell script to print all armstrong numbers between two numbers.

#! /bin/bash

function noOfDigits(){
no=$1
count=0
while [ $no -gt 0 ] 
do	
	count=$((count+1))
	no=$((no/10))
done

}


function checkArmstrong(){
number=$1
a=$number
noOfDigits $number
sum=0
while [ $number -gt 0 ] 
do 
       
	remainder=$((number%10))
	temp=`echo "$remainder^$count" | bc`
	sum=`echo "$sum+$temp" | bc`
	number=$((number/10))
done

if [ $sum -eq $a ]
then 
	printf "$a "
fi
}



echo "Enter the two numbers"
read num1 num2
echo "The Armstrong numbers are"
for ((i=$num1;i<=$num2;i++))
do
	checkArmstrong $i
done
echo
