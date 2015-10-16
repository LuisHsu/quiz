#!/bin/bash
./generator $1
correct=0
incorrect=0
count=1
rm miss.txt
for line in `cat "test.txt" | awk {'print $1 ";" $2 ";" $3'}`;do
	echo "Start test ${count} ..."
	data=`echo ${line} | cut -d ';' -f 1`
	char=`echo ${line} | cut -d ';' -f 2`
	check=`echo ${line} | cut -d ';' -f 3`
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh
	res=`perf stat -e cache-misses -o outp2 ./$2 ${data} ${char}` 
	miss=`cat outp2 | grep 'cache-misses' | awk {'print $1'}`
	echo ${miss//,/} >> miss.txt 
	echo "Test ${count} cache-miss : ${miss}"
	count=$(( count + 1 ))
done
rm outp*
rm test.txt
