
#!/bin/bash

cr(){
    if [ -e addressbk.txt ]
    then 
        echo "it already exists"
    else
        touch addressbk.txt
        echo "file succ created !!"
    fi
}

inn (){
    echo -e "Enter First Name : "
    read fname
    echo -e "Enter Last Name : "
    read lname
    echo -e "Enter dept : "
    read dept
    
    echo "$fname      $lname     $dept" >> addressbk.txt 
    echo -e "RECORD INSERTED SUCCESSFULLY !"

}

dis(){
    if [  !-s addressbk.txt ] 
    then 
        echo -e "THE ADDRESSBOOK IS EMPTY !"
    else
        sed -n 'p' addressbk.txt  
    fi

}

mod(){

    echo "Enter Name of you want"
    read pattern
    if grep -r -w $pattern addressbk.txt
    then
        echo "Enter modified"
            echo "eter firt name"
            read fn
            echo "Enter last name"
            read lna
            echo "enter dept"
            read dep
	
	    new = `echo $fn $lna $dep`
            old = `cat addressbk.txt | grep $pattern`
            echo "New : $new"
            echo "Old : $old"

            sed -i s/"$old"/"$new"/g addressbk.txt
            echo "modified successfully"

	
    else
        echo "name Not Found !"
    fi
}

del(){

    echo "Enter Name of you want"
    read pattern
    if grep -r -w $pattern addressbk.txt
    then
        sed -i "/$pattern/d" addressbk.txt
        echo "Deletion Successful"
    else
        echo "Record Not Found !"
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