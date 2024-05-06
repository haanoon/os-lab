echo "Enter the number"
read num
sum=0
while [ $num -gt 0 ];
	do
		a=$(($num % 10))
		sum=$(($sum + $a))
		num=$(($num / 10))
	done
echo "sum is : "$sum