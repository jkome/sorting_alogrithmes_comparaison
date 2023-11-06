set term png size 800,600

# Random Arrays Plot
set output "random_arrays_plot.png"
set title "Sorting Algorithms Performance (Random Arrays)"
set xlabel "Array Size"
set ylabel "Execution Time (seconds)"
set yrange [0:]
plot "smoothed_random_data.csv" using 1:2 with lines title "Bubble Sort", \
     "smoothed_random_data.csv" using 1:3 with lines title "Selection Sort", \
     "smoothed_random_data.csv" using 1:4 with lines title "Insertion Sort", \
     "smoothed_random_data.csv" using 1:5 with lines title "Merge Sort", \
     "smoothed_random_data.csv" using 1:6 with lines title "Quick Sort", \
     "smoothed_random_data.csv" using 1:7 with lines title "Heap Sort"

# Best Case Plot
set output "best_case_plot.png"
set title "Sorting Algorithms Performance (Best Case)"
set xlabel "Array Size"
set ylabel "Execution Time (seconds)"
set yrange [0:]
plot "smoothed_best_case_data.csv" using 1:2 with lines title "Bubble Sort", \
     "smoothed_best_case_data.csv" using 1:3 with lines title "Selection Sort", \
     "smoothed_best_case_data.csv" using 1:4 with lines title "Insertion Sort", \
     "smoothed_best_case_data.csv" using 1:5 with lines title "Merge Sort", \
     "smoothed_best_case_data.csv" using 1:6 with lines title "Quick Sort", \
     "smoothed_best_case_data.csv" using 1:7 with lines title "Heap Sort"

# Worst Case Plot
set output "worst_case_plot.png"
set title "Sorting Algorithms Performance (Worst Case)"
set xlabel "Array Size"
set ylabel "Execution Time (seconds)"
set yrange [0:]
plot "smoothed_worst_case_data.csv" using 1:2 with lines title "Bubble Sort", \
     "smoothed_worst_case_data.csv" using 1:3 with lines title "Selection Sort", \
     "smoothed_worst_case_data.csv" using 1:4 with lines title "Insertion Sort", \
     "smoothed_worst_case_data.csv" using 1:5 with lines title "Merge Sort", \
     "smoothed_worst_case_data.csv" using 1:6 with lines title "Quick Sort", \
     "smoothed_worst_case_data.csv" using 1:7 with lines title "Heap Sort"

# Mixed Case Plot
set output "mixed_case_plot.png"
set title "Sorting Algorithms Performance (Mixed Case)"
set xlabel "Array Size"
set ylabel "Execution Time (seconds)"
set yrange [0:]
plot "smoothed_mixed_case_data.csv" using 1:2 with lines title "Bubble Sort", \
     "smoothed_mixed_case_data.csv" using 1:3 with lines title "Selection Sort", \
     "smoothed_mixed_case_data.csv" using 1:4 with lines title "Insertion Sort", \
     "smoothed_mixed_case_data.csv" using 1:5 with lines title "Merge Sort", \
     "smoothed_mixed_case_data.csv" using 1:6 with lines title "Quick Sort", \
     "smoothed_mixed_case_data.csv" using 1:7 with lines title "Heap Sort"
