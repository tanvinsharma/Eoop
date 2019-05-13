set terminal canvas
set title "Fan Demographs"
set ylabel "Number of people"
set logscale y
set style fill solid border
set autoscale y
set xtics ("Fans" 1, "Male" 2, "Female" 3)
set style data histogram
set style histogram clustered
plot for [COL=2:4] "data.dat" using COL:xticlabels(1)  title columnheader
