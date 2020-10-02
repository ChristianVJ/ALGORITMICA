#!/bin/csh -vx

g++ genera-mezclavectores.cpp -o mezcla -std=c++11

@ i = 50
while ( $i < 1000 )
  ./mezcla 1000 $i
  @ i += 50
end

@ i = 50
while ( $i < 1000 )
  ./mezcla $i 1000
  @ i += 50
end

