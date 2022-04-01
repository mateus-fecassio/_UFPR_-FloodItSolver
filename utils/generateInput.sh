#!/bin/bash


row=(5 10 20 40 80 100)
colunm=(5 10 20 40 80 100)
color=(2 4 8 12 16 20)


for (( i=0; i<${#row[@]}; i++ ));
do
    ./geramapa ${row[$i]} ${colunm[$i]} ${color[$i]} > "../input/${row[$i]}X${colunm[$i]}.txt"
    echo "${row[$i]}X${colunm[$i]}.txt GENERATED"
done