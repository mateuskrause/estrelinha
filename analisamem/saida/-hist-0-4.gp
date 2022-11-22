set term postscript eps color 14
set output "./saida/-hist-0-4.eps"
set style fill solid 1.0
set title "Distancia de Pilha Total 15 - Fase  0 - ID 4"
set xlabel "Distancia"
set ylabel "Endereco"
plot [-1:2] "./saida/-hist-0-4.gpdat" u 3:4 w boxes t ""
