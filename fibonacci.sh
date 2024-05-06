echo "enter the limit"
read limit
f1=0
f2=1
echo -n $f1 " "
echo -n $f2 " "
f3=0
while [ $f3 -lt $limit ];
    do
        f3=$(($f1 + $f2))
        f1=$f2
        f2=$f3
        echo -n $f3 " "
    done    