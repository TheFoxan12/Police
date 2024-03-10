# include "police.h"

// implementation du tri par insertion sur une liste de struct s_calls
t_calls **insertion_sort(t_calls **calls) {
	if (!calls) return NULL;
	int i, j;
	t_calls *key;
	for (i = 1; i < CALLS_AMOUNT; i++) {
		key = calls[i];
		j = i - 1;
		while (j >= 0 && strcmp(calls[j]->num, key->num) > 0) {
			calls[j + 1] = calls[j];
			j = j - 1;
		}
		calls[j + 1] = key;
	}
	return (calls);
}

// implementation du tri par insertion sur une liste de struct s_callsv2
t_callsv2 **insertion_sortv2(t_callsv2 **calls) {
	if (!calls) return NULL;
	int i, j;
	t_callsv2 *key;
	for (i = 1; i < CALLS_AMOUNT; i++) {
		key = calls[i];
		j = i - 1;
		while (j >= 0 && calls[j]->num > key->num) {
			calls[j + 1] = calls[j];
			j = j - 1;
		}
		calls[j + 1] = key;
	}
	return (calls);
}
