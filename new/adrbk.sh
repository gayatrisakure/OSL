#!/bin/bash


cr()
{
	echo "Enter name of Book"
	read ab
	res=`ls | grep $ab | wc -c`
	if [ $res -gt 0 ] 
	then
		echo "Already Exist File"
	else
		touch $ab
		echo "File Has Been Created Successfully"
	fi
}


dis()
{
	echo "Enter name of Book"
	read ab
	res=`ls | grep $ab | wc -c`
	if [ $res -gt 0 ] 
	then
		cat $ab
	else
		echo "File is not Available"
		echo "Enter 1 if You want to Create New file"
		read tmp
		if [ $tmp -eq 1 ]
		then
			touch $ab
			echo "File had been Created Successfully"
		else
			echo "Ok Bye :)"
		fi
	fi
}

inn()
{
	echo "Enter name of Book"
	read ab
	res=`ls | grep $ab | wc -c`
	if [ $res -gt 0 ] 
	then
		echo "Enter Roll No."
		read rl
		tm=`cat $ab | grep $rl | wc -c`
		if [ $tm -gt 1 ]
		then 
			echo "Can't Have Same Roll Numbers Assigned"
		else
			echo "Enter First Name"
			read fn
			echo "Enter Last Name"
			read ln
			echo "Enter Department"
			read dep
			rr=`echo $rl $fn $ln $dep`
			echo $rr >> $ab
			echo "Record Inserted Successfully"
		fi 
	else
		echo "File is not Available"
	fi
}

mod()
{
	echo "Enter name of Book"
	read ab
	res=`ls | grep $ab | wc -c`
	if [ $res -gt 0 ] 
	then
		echo "Enter Roll No."
		read rl
		tm=`cat $ab | grep $rl | wc -c`
		if [ $tm -gt 1 ]
		then 
			echo "Enter new Modified Data"
			echo "Enter First Name"
			read fn
			echo "Enter Last Name"
			read ln
			echo "Enter Department"
			read dep
		new=`echo $rl $fn $ln $dep`
		old=`cat $ab | grep $rl`
		echo "Old : $old"
		echo "New : $new"
		sed -i s/"$old"/"$new"/g $ab
		echo "Record Modified Successfully"
		else
			echo "Roll No. Not Found"
		fi 
	else
		echo "File is not Available"
	fi
}


de()
{
	echo "Enter 1 to Delete file"
	read op
	if [ $op -eq 1 ]
	then 
		echo "Enter File Name which you want delete"
		read tp 
		rm $tp
	else
	echo "Enter name of Book"
	read ab
	res=`ls | grep $ab | wc -c`
	if [ $res -gt 0 ] 
	then
		echo "Enter Roll No."
		read rl
		tm=`cat $ab | grep $rl | wc -c`
		if [ $tm -gt 1 ]
		then 
		old=`cat $ab | grep $rl`
		echo "Record which is being Deleted : $old"
		sed -i s/"$old"//g $ab
		sed -i /^$/d $ab
		echo "Record Deleted Successfully"
		else
			echo "Roll No. Not Found"
		fi 
	else
		echo "File is not Available"
	fi
	fi
}


while [ true ]
do
	echo "Address Book"
	echo "1.Create Book"
	echo "2.Insert Into Book"
	echo "3.Modify Into Book"
	echo "4.Delete From Book"
	echo "5.Display Book"
	echo "6.Exit"
	echo "Enter Your Choice"
	read c
	case $c in
	1)cr ;;
	2)inn ;;
	3)mod ;;
	4)de ;;
	5)dis ;;
	6) exit ;;
	*) echo "Entered Wrong Choice" ;;
	esac
done
