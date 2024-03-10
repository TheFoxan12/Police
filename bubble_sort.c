# include "police.h"

// implementation du tri a bulles sur une liste de struct s_calls
t_calls **bubble_sort(t_calls **calls) {
	if (!calls) return NULL;
	int s;
	for (int i = 0; i < CALLS_AMOUNT - 1; i++) {
		s = 0;
		for (int j = 0; j < CALLS_AMOUNT - 1 - i; j++) {
			if (strcmp(calls[j]->num, calls[j + 1]->num) > 0)
				swap_calls(calls, j, j + 1), s = 1;
		}
		if (s == 0) break;
	}
	return (calls);
}

// implementation du tri a bulles sur une liste de struct s_callsv2
t_callsv2 **bubble_sortv2(t_callsv2 **calls) {
	if (!calls) return NULL;
	int s;
	for (int i = 0; i < CALLS_AMOUNT - 1; i++) {
		s = 0;
		for (int j = 0; j < CALLS_AMOUNT - 1 - i; j++) {
			if (calls[j]->num > calls[j + 1]->num)
				swap_callsv2(calls, j, j + 1), s = 1;
		}
		if (s == 0) break;
	}
	return (calls);
}
