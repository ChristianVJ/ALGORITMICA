#!/bin/csh -vx

g++ recursivo.cpp -o recursivo -std=c++11

@ i = 50
while ( $i < 1001 )
  ./recursivo mezcla"$i"x1000.txt >> datos_recursivoX1000.dat
  @ i += 50
end

@ i = 50
while ( $i < 1001 )
  ./recursivo mezcla1000x"$i".txt >> datos_recursivo1000X.dat
  @ i += 50
end

