echo "Enter a number: "
read num
i=1
sum=0

while [ $i -le $num ]
do 
    sum=$((sum + i)) #sum+=num
    i=$((i + 1))
done
echo "Sum of $num natural numbers is: $sum"