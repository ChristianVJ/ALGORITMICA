#!/bin/csh -vx

g++ intuitivo.cpp -o intuitivo -std=c++11

@ i = 50
while ( $i < 1000 )
  ./intuitivo mezcla"$i"x1000.txt >> datos_intuitivoX1000.dat
  @ i += 50
end

@ i = 50
while ( $i < 1000 )
  ./intuitivo mezcla1000x"$i".txt >> datos_intuitivo1000X.dat
  @ i += 50
end

