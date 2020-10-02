#!/usr/bin/gnuplot

set output "Comparacion_intuitivo_recursivo_1000X.png"
set term png
plot 'datos_intuitivo1000X.dat' using 1:2 title "Intuitivo" with lines, \
'datos_recursivo1000X.dat' using 1:2 title "DyV" with lines
set ylabel "Tiempo (s)"
set xlabel "Tamaño"
replot

set output "Comparacion_intuitivo_recursivo_X1000.png"
set term png
plot 'datos_intuitivoX1000.dat' using 1:2 title "Intuitivo" with lines, \
'datos_recursivoX1000.dat' using 1:2 title "DyV" with lines
set ylabel "Tiempo (s)"
set xlabel "Tamaño"
replot

set output "Comparacion_intuitivo.png"
set term png
plot 'datos_intuitivoX1000.dat' using 1:2 title "tamañox1000" with lines, \
'datos_intuitivo1000X.dat' using 1:2 title "1000xtamaño" with lines
set ylabel "Tiempo (s)"
set xlabel "Tamaño"
replot
