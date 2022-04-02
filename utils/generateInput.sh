#!/bin/bash


row=(10 20 40 80 100)
colunm=(10 20 40 80 100)
color=(4 8 12 16 20)


for (( i=0; i<${#row[@]}; i++ ));
do
    num=${row[$i]}
    n_colors=$(( num/4 ))

    # ./geramapa ${row[$i]} ${colunm[$i]} ${color[$i]} > "../input/${row[$i]}X${colunm[$i]}.txt"
    ./geramapa ${row[$i]} ${colunm[$i]} ${n_colors} > "../input/${row[$i]}X${colunm[$i]}.txt"
   
    echo "${row[$i]}X${colunm[$i]}.txt GENERATED"
done