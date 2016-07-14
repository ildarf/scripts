#!/bin/bash

SAVEIFS=$IFS
IFS=`echo -en "\n\b"`

for i in `find -mindepth 3 -maxdepth 3 -type f -name upload_\*`
do
  j=`echo $i | sed 's/upload_//'`
  mv $i $j
done

#for i in `find -mindepth 2 -maxdepth 2 -type d -name Aufgabe\*`
#do
#  j=`echo $i | perl -pe 's/(Aufgabe\ \d)\ /$1/'`
#  mv $i $j
#done

for i in `find -mindepth 1 -maxdepth 1 -type d`
do
  j=`echo $i | sed 's/├д/a/' | sed 's/├╝/u/' | sed 's/├╢/o/' | sed 's/├Ц/O/'`
  if [ $i != $j ]
  then
    mv $i $j
  fi
done

for i in `find -mindepth 2 -maxdepth 2 -type d`
do
  cd $i
  for j in `find -mindepth 1 -maxdepth 1 -name \*.zip`
  do
    unzip $j
    rm -r __MACOSX 2>/dev/null
  done
  for j in `find -mindepth 1 -maxdepth 1 -type d`
  do
    mv $j/* .
    rmdir $j
  done
  #jar xf ~/stdlib.jar StdIn.class StdOut.class StdDraw.class
  #cp ~/Turtle.java .
  for j in `find -name \*.java`
  do
    iconv -f ISO-8859-15 -t UTF-8 -o $j $j
    #javac $j 2> ERROR
    #if [ $? == 0 ]
    #then
    #  rm ERROR
    #fi
  done
  cd ../..
done

IFS=$SAVEIFS
