mkdir Assignment-1
counter=1
while [ $counter -le 10 ]
do
	mkdir Assignment-1/Query-$counter
	touch Assignment-1/Query-$counter/response-$counter.sh
	((counter++))
done