#! /bin/bash

# Write a shell script that computes the gross salary of an employee ac-
# cording to the following rules (i) if basic salary is < 1500 then HRA =10%
# of the basic and DA =90% of the basic. (ii) If basic salary is >=1500 then
# HRA =Rs.500 and DA=98% of the basic

echo "Enter the salary of the employee"
read salary

if [ $salary -lt 1500 ]
then 

	HRA=`echo "0.1*$salary" | bc`
	DA=`echo "0.9*$salary" | bc`
else

	HRA=500
	DA=`echo "0.98*$salary" | bc`
fi
gSalary=`echo $HRA+$DA+$salary | bc`	

echo "The gross salary is $gSalary"
	
	
	

