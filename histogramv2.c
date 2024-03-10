# include "police.h"

// count_stats renvoie un histogramme de la liste de struct callsv2 passee en parametre
// contient en plus les appels entrants et sortants, par rapport a count_calls
t_stats **count_stats(t_callsv2 **calls) {
	if (!calls) return NULL;
	t_stats	**histogram = malloc((CALLS_AMOUNT / 4) * sizeof(t_stats *));
	int		j, k = 0;

	histogram[0] = NULL;
	for (int i = 0; calls[i]; i++) {
		if ((j = find_namev2(histogram, calls[i]->name)) == -1) {
			histogram[k] = malloc(sizeof(t_stats));
			histogram[k]->name = strdup(calls[i]->name);
			histogram[k]->amount = 1;
			histogram[k]->in = strcmp(calls[i]->type, "Entrant") == 0 ? 1 : 0;
			histogram[k]->out = strcmp(calls[i]->type, "Sortant") == 0 ? 1 : 0;
			histogram[k + 1] = NULL;
			k++;
		}
		else {
			histogram[j]->amount++;
			histogram[j]->in += strcmp(calls[i]->type, "Entrant") == 0 ? 1 : 0;
			histogram[j]->out += strcmp(calls[i]->type, "Sortant") == 0 ? 1 : 0;
		}
	}
	histogram[k] = NULL;
	return histogram;
}

// find_name renvoie l'index ou name a ete trouve dans la liste de struct stats ou renvoie -1
// sur le name n'a pas ete trouve dedans
int	find_namev2(t_stats **histogram, const char *name) {
	if (!histogram) return -1;
	for (int i = 0; histogram[i]; i++) {
		if (strcmp(histogram[i]->name, name) == 0) return i;
	}
	return (-1);
}

// free histogram libere la memoire de la liste de struct stats passee en parametre
void free_histogramv2(t_stats **histogram) {
	if (!histogram) return;
	for (int i = 0; histogram[i]; i++) {
		free(histogram[i]->name);
		free(histogram[i]);
	}
	free(histogram);
}

// display histogram affiche l'histogram passe en parametre
void display_histogramv2(t_stats **histogram) {
	if (!histogram) return;
	for (int i = 0; histogram[i]; i++)
		printf("nom : %s : %d appels dont %d entrants, %d sortants\n",
			   histogram[i]->name, histogram[i]->amount, histogram[i]->in, histogram[i]->out);
}
