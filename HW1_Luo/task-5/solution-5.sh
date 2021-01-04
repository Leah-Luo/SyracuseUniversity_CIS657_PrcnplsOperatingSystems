#Download and extracts the tar file
#wget http://127.0.0.1:55005/sample_data.tar -O - | tar -xf - 

wget -c $1 
tar -xf sample_data.tar 

FILE="sample_data/*"
#Search through the content of the files for string “smart”
for f in $FILE
do
	filename="$(ls $f)" 
	count="$(grep -c "smart" $f)"
	printf "%s smart %d\n" $filename $count
done > result.txt #Store the result in file result.txt
#Search through the content of the files for string “operating system”
for f in $FILE 
do
	filename="$(ls $f)" 
	count="$(grep -c "operating system" $f)"
	printf "%s operating system %d\n" $filename $count
done >> result.txt
#Create two directories named smart and OS 
mkdir smart
mkdir OS
#Copy all the files that contain the string “smart”
for f in $FILE 
do
	if grep -q "smart" "$f" 
	then
		cp $f smart/
#Copy all the files that contain the string “operating system”
	elif grep -q "operating system" "$f" 
	then
		cp $f OS/
	fi
done