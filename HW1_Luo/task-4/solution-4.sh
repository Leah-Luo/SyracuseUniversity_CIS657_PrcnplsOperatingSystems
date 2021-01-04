#for pid in $(ps -u lluojr | grep "infloop" | grep -v grep | awk '{print $1}');
for pid in $(ps -u $USER | grep "infloop" | grep -v grep | awk '{print $1}');
do
kill -9 $pid;
done