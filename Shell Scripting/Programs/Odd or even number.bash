echo "Enter a number: "
read num
if [ `expr $num % 2` == 0 ]
then
    echo "Even number"
else
    echo "Odd number"
fi