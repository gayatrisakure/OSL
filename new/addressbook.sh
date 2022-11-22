#!/bin/bash
cr()
{
	echo "Enter Name of File"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt 0 ]
	then
		echo "File Already Existing"
	else
		touch $ab
		echo "File Created Successfully"
	fi
}

dis()
{
	echo "Enter Name of File"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt 0 ]
	then
		echo "$ab"
		cat $ab
	else
		echo "File Not Exists"
	fi
}


inn()
{
	echo "Enter Name of File"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt 0 ]
	then
		echo "Enter Roll No."
		read rl
		tmp=`cat $ab | grep -w $rl | wc -c`
		if [ $tmp -gt 0 ]
		then
			echo "Roll No. Doesn't Exist"
			
		else
			echo "Enter First Name"
			read fn
			echo "Enter Last Name"
			read ln
			echo "Enter Department"
			read dep
			tp=`echo $rl $fn $ln $dep`
			echo $tp >> $ab
			echo "Inserted Successfully"
		fi
	else
		echo "File Not Exists"
	fi
}

mod()
{
	echo "Enter Name of File"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt 0 ]
	then
		echo "Enter Roll No."
		read rl
		tmp=`cat $ab | grep $rl | wc -c`
		if [ $tmp -gt 0 ]
		then
			echo "Enter Modified"
			echo "Enter First Name"
			read fn
			echo "Enter Last Name"
			read ln
			echo "Enter Department"
			read dep
			new=`echo $rl $fn $ln $dep`
			old=`cat $ab | grep $rl`
			echo "New:$new"
			echo "Old:$old"
			sed -i s/"$old"/"$new"/g $ab
			echo "Modified Successfully"	
			
		else
			echo "Roll No. Doesn't Exist"
			
		fi
	else
		echo "File Not Exists"
	fi
}

del()
{
	echo "Enter Name of File"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt 0 ]
	then
		echo "Enter Roll No."
		read rl
		tmp=`cat $ab | grep $rl | wc -c`
		if [ $tmp -gt 0 ]
		then
			old=`cat $ab | grep $rl`
			echo "old:$old"
			sed -i s/"$old"//g $ab
			sed -i /^$/d $ab
			echo "Modified Successfully"	
			
		else
			echo "Roll No. Doesn't Exist"
			
		fi
	else
		echo "File Not Exists"
	fi
}

while [ true ]
do
	echo "Address_Book"
	echo "1.Create Address Book"
	echo "2.Insert into Address Book"
	echo "3.Modify the Address Book"
	echo "4.Delete from Address Book"
	echo "5.Display the Address Book"
	echo "6.exit"
	echo "Enter Your Choice"
	read ch
	case $ch in
		1)cr ;;
		2)inn ;;
		3)mod ;;
		4)del ;;
		5)dis ;;
		6)exit ;;
		*)echo "Enter Valid Choice"
	esac
done

