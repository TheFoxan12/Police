# include "police.h"

// nums_to_int prend une liste de struct s_calls et la copie dans une liste de
// struct s_callsv2 avant de la renvoyer
t_callsv2 **nums_to_int(t_calls **calls) {
	if (!calls) return NULL;
	t_callsv2 **copy = malloc((CALLS_AMOUNT + 1) * sizeof(t_callsv2));
	int i = 0;
	for (; calls[i]; i++) {
		copy[i] = malloc(sizeof(t_callsv2));
		copy[i]->name = strdup(calls[i]->name);
		copy[i]->num = atoi(strdup(&(calls[i]->num)[3]));
		copy[i]->type = strdup(calls[i]->type);
	}
	copy[i] = NULL;
	return (copy);
}

// free_calls permet de free tous les elements d'un tableau de structures s_callsv2
void free_callsv2(t_callsv2 **calls) {
	int i = 0;
	while (calls[i]) {
		free(calls[i]->name);
		free(calls[i]->type);
		free(calls[i]);
		i++;
	}
	free(calls);
}

// copy_calls creer une copie de la struct s_callsv2 passee en parametre
t_callsv2 **copy_callsv2(t_callsv2 **calls) {
	if (!calls) return NULL;
	t_callsv2 **copy = malloc((CALLS_AMOUNT + 1) * sizeof(t_callsv2));
	int i = 0;
	for (; calls[i]; i++) {
		copy[i] = malloc(sizeof(t_callsv2));
		copy[i]->name = strdup(calls[i]->name);
		copy[i]->num = calls[i]->num;
		copy[i]->type = strdup(calls[i]->type);
	}
	copy[i] = NULL;
	return (copy);
}

// display_calls affiche tous les calls d'une liste de s_callsv2
// avec toutes les informations ligne par ligne dans l'ordre de la liste
void display_callsv2(t_callsv2 **calls) {
	if (!calls) return ;
	for (int i = 0; calls[i]; i++)
		printf("num: %d, nom : %s, type: %s\n", calls[i]->num, calls[i]->name, calls[i]->type);
}

// swap_calls intervertit les calls aux positions i et j d'une liste de struct s_callsv2
void swap_callsv2(t_callsv2 **calls, int i, int j) {
	t_callsv2 *tmp;
	tmp = calls[j];
	calls[j] = calls[i];
	calls[i] = tmp;
}
