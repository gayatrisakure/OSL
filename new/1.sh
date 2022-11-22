#!/bin/bash

cr()
{
    echo "Enter file name"
    read ab

    res = `ls | grep $ab | wc -w`
    if [ $res -gt 0 ]
    then 
        echo "File already exist"
    else
        touch $ab
        echo "File created successfully"
    fi    
}

dis(){
    echo "Enter file name"
    read ab
    res =  `ls | grep $ab | wc -w`
    if [ $res -gt 0 ]
    then
        echo "$ab"
        cat $ab
    else    
        echo "File not exist"
    fi
}

inn(){
    echo "Enter file name"
    read ab
    res = `ls | grep -w $ab | wc -w`

    if [ $res -gt 0 ]
    then 
        echo "Enter RN : "
        read r1
        tmp = `cat $ab | grep -w $r1 | wc -c`
        if [ $tmp -gt 0 ]
        then
            echo "RN doesnt exist"

        else    
            echo "eter firt name"
            read fn
            echo "Enter last name"
            read ln
            echo "enter dept"
            read dep

            tp = `echo $r1 $fn $ln $dep`
            echo $tp >> $ab
            echo "Inserted successfully"
        fi
    else    
        echo "File not exist"
    fi

}


mod(){
    echo "Enter file name"
    read ab
    res = `ls | grep $ab | wc -w`

    if [ $res -gt 0 ]
    then 
        echo "Enter RN : "
        read r1
        tmp = `cat $ab | grep $r1 | wc -c`

        if [ $tmp -gt 0 ]
        then    
            echo "Enter modified"
            echo "eter firt name"
            read fn
            echo "Enter last name"
            read ln
            echo "enter dept"
            read dep

            new = `echo $r1 $fn $ln $dep`
            old = `cat $ab | grep $r1`
            echo "New : $new"
            echo "Old : $old"

            sed -i s/"$old"/"$new"/g $ab
            echo "modified successfully"

        else 
            echo "RN dont exist"
        fi
    else    
        echo "File not exist"
    fi        
}

del(){
    echo "Enter file name"
    read ab
    res = `ls | grep $ab | wc -w`

    if [ $res -gt 0 ]
    then    
        echo "Enter rn : "
        read r1
        tmp = `cat $ab | grep $r1 | wc -c`

        if [ $tmp -gt 0 ]
        then    
            old = `cat $ab | grep $r1`
            echo "old : $old"
            sed -i s/"$old"//g $ab
            sed -i /^$/d $ab
            echo "Modified successfully"
        else
            echo "Rn dont exist"
        fi

    else    
        echo "File not exist"
    fi
}

while [ true ]
do
    echo "************Address Book***************"
    echo "1. Create 2.insert 3.modify 4.delete 5.display 6. exit"
    echo "Enter choice"
    read ch
    case $ch in 
        1) cr ;;
        2) inn ;;
        3) mod ;;
        4) del ;;
        5) dis ;;
        6) exit ;;
        *) echo " Enter valid no"

    esac

done