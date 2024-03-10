# include "police.h"

// count_calls renvoie un histogramme de la liste de struct callsv2 passee en parametre
t_pair **count_calls(t_callsv2 **calls) {
	if (!calls) return NULL;
	t_pair	**histogram = malloc((CALLS_AMOUNT / 4) * sizeof(t_pair *));
	int		j, k = 0;

	histogram[0] = NULL;
	for (int i = 0; calls[i]; i++) {
		if ((j = find_name(histogram, calls[i]->name)) == -1) {
			histogram[k] = malloc(sizeof(t_pair));
			histogram[k]->name = strdup(calls[i]->name);
			histogram[k]->amount = 1;
			histogram[k + 1] = NULL;
			k++;
		}
		else histogram[j]->amount++;
	}
	histogram[k] = NULL;
	return histogram;
}

// find_name renvoie l'index ou name a ete trouve dans la liste de struct pair ou renvoie -1
// sur le name n'a pas ete trouve dedans
int	find_name(t_pair **histogram, const char *name) {
	if (!histogram) return -1;
	for (int i = 0; histogram[i]; i++) {
		if (strcmp(histogram[i]->name, name) == 0) return i;
	}
	return (-1);
}

// free histogram libere la memoire de la liste de struct pairs passee en parametre
void free_histogram(t_pair **histogram) {
	if (!histogram) return;
	for (int i = 0; histogram[i]; i++) {
		free(histogram[i]->name);
		free(histogram[i]);
	}
	free(histogram);
}

// display histogram affiche l'histogram passe en parametre
void display_histogram(t_pair **histogram) {
	if (!histogram) return;
	for (int i = 0; histogram[i]; i++)
		printf("nom : %s : %d appels\n", histogram[i]->name, histogram[i]->amount);
}
