# include "police.h"

int main() {
	t_calls **calls = parsefile("calls.txt"); //on parse le fichier
	if (!calls)
		return 1;

	// Chapitre 1 : tris et rapidité de tri
	//// les numeros sont des string /////////////////////////////////////////////////
	{
		// struct timeval bstop, bstart, istop, istart;
		LARGE_INTEGER frequency, bstart, bstop, istop, istart;
		/// tri à bulles -----------------------------
		t_calls **bubble_sorted = copy_calls(calls);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&bstart);
		bubble_sort(bubble_sorted);
		QueryPerformanceCounter(&bstop);
		//display_calls(bubble_sorted);

		/// tri par insertion----------------------------
		t_calls **insertion_sorted = copy_calls(calls);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&istart);
		insertion_sort(insertion_sorted);
		QueryPerformanceCounter(&istop);
		//display_calls(insertion_sorted);

		/// resultats ---------------------------
		printf("temps bubble sort : %f usecondes\n", (double)(bstop.QuadPart - bstart.QuadPart) / frequency.QuadPart * 1000000);
		printf("temps insertion sort : %f usecondes\n", (double)(istop.QuadPart - istart.QuadPart) / frequency.QuadPart * 1000000);
		free_calls(bubble_sorted);
		free_calls(insertion_sorted);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	printf("---------------\n");
	//// les numeros deviennent des int /////////////////////////////////////////////////
	{
		LARGE_INTEGER frequency, bstart, bstop, istop, istart;
		/// tri à bulles -----------------------------
		t_callsv2 **bubble_sorted = nums_to_int(calls);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&bstart);
		bubble_sortv2(bubble_sorted);
		QueryPerformanceCounter(&bstop);
		//display_calls(bubble_sorted);

		/// tri par insertion----------------------------
		t_callsv2 **insertion_sorted = nums_to_int(calls);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&istart);
		insertion_sortv2(insertion_sorted);
		QueryPerformanceCounter(&istop);
		//display_calls(insertion_sorted);

		/// resultats ---------------------------
		// nombre de secondes * 1000000 + nombre de micro secondes
		printf("temps bubble sort v2 : %f usecondes\n", (double)(bstop.QuadPart - bstart.QuadPart) / frequency.QuadPart * 1000000);
		printf("temps insertion sort v2 : %f usecondes\n", (double)(istop.QuadPart - istart.QuadPart) / frequency.QuadPart * 1000000);
		free_callsv2(bubble_sorted);
		free_callsv2(insertion_sorted);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	printf("--------------------\n");
	// Chapitre 2 : histogrammes
	{
		t_callsv2	**calls_histo = nums_to_int(calls);
		t_pair		**histogram_amount = count_calls(calls_histo);
		display_histogram(histogram_amount);
		free_histogram(histogram_amount);
		free_callsv2(calls_histo);
	}
	printf("----------\n");
	{
		t_callsv2	**calls_histo = nums_to_int(calls);
		t_stats		**histogram_stats = count_stats(calls_histo);
		display_histogramv2(histogram_stats);
		free_histogramv2(histogram_stats);
		free_callsv2(calls_histo);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	printf("---------------\n");
	// Chapitre 3 : histogrammes et rapidités de traitement
	{
		LARGE_INTEGER frequency, start, stop;
		t_callsv2	**calls_histo = nums_to_int(calls);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		t_stats		**histogram_stats = count_stats(calls_histo);
		QueryPerformanceCounter(&stop);
		display_histogramv2(histogram_stats);
		printf("temps histogramme : %f usecondes\n", (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart * 1000000);
		free_histogramv2(histogram_stats);
		free_callsv2(calls_histo);
	}
	printf("---------------\n");
	// histogramme sur des int
	{
		LARGE_INTEGER frequency, start, stop;
		int *numbers = generate_randint(1000, 0, 25);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		int *histogram_stats = count_ints(numbers, 1000);
		QueryPerformanceCounter(&stop);
		display_histogramints(histogram_stats, 25);
		printf("temps histogramme ints : %f usecondes\n", (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart * 1000000);
		free(numbers);
		free(histogram_stats);
	}
	printf("---------------\n");
	// histogramme sur des ints nouvelle méthode
	{
		LARGE_INTEGER frequency, start, stop;
		int *numbers = generate_randint(1000, 0, 25);
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);
		int *histogram_stats = count_intsv2(numbers, 1000);
		QueryPerformanceCounter(&stop);
		display_histogramints(histogram_stats, 25);
		printf("temps histogramme ints v2 : %f usecondes\n", (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart * 1000000);
		free(numbers);
		free(histogram_stats);
	}
	/////////////////////////////////////////////////////////////////////////////////////
	// free
	free_calls(calls);
	return 0;
}
