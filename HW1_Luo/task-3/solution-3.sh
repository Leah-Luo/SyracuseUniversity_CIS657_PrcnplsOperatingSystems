#total number of processors
cat /proc/cpuinfo| grep "processor"| wc -l > cpuinfo.txt 
#core id of processors 
cat /proc/cpuinfo | grep 'core id' | grep -o '[0-9]\+' >> cpuinfo.txt
#cache size available to processors
cat /proc/cpuinfo | grep 'cache size' | grep -o '[0-9]\+' >> cpuinfo.txt