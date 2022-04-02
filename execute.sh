#!/bin/bash

INPUT=./input/
ITEMS=$(find $INPUT -maxdepth 1 -type f | xargs ls -1t | tac)

PROG=./floodit
VERIFICA=./utils/verifica
make
for entry in ${ITEMS[@]}
do
    name=$(echo $entry | awk -F"/" '{print $3}')
    echo "TESTING $name ..."

    $PROG < $entry > temp.tmp
    cat $entry temp.tmp | $VERIFICA

    if [ "$?" -eq 0 ]
      then
        echo "OK"
      else
        echo "FAIL"
    fi
    echo ""
    echo "Executing make purge"
    make purge

done