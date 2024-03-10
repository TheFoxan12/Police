# include "police.h"

// frees permet de free tous les elements d'un tableau de char*
void frees(char **strs) {
	if (!strs)
		return;
	int i = 0;
	while (strs[i]) {
		free(strs[i]);
		i++;
	}
	free(strs);
}

// free_calls permet de free tous les elements d'un tableau de structures s_calls
void free_calls(t_calls **calls) {
	int i = 0;
	while (calls[i]) {
		free(calls[i]->name);
		free(calls[i]->num);
		free(calls[i]->type);
		free(calls[i]);
		i++;
	}
	free(calls);
}

// parsefile parse le releve d'appels passe en parametre et
// stocke les informations de chaque ligne dans un structure s_calls
// et renvoie l'ensemble des structures dans un tableau de structures s_calls
t_calls **parsefile(char *path) {
	t_calls	**calls = malloc((CALLS_AMOUNT + 1) * sizeof(t_calls *));
	// on alloue la place pour le nombre d'appels et le NULL de fin
	t_calls	*current_call = NULL; // stock les infos de la ligne en cours
	int 	i = 0; // stock le numero de la ligne en cours

	int fd = open(path, O_RDONLY); // on ouvre le fichier
	if (fd < 0) { printf("error opening file\n"); return NULL; } // si erreur on return NULL
	char *line = get_next_line(fd); // on lit le fichier ligne par ligne
	char **splitted = NULL; // pour stocker les informations de la ligne separement
	while (line) {
		// on separe les informations et on les stocke dans la structure
		frees(splitted); splitted = ft_split(line, ' ');
		calls[i] = malloc(sizeof(t_calls));
		calls[i]->num = strdup(splitted[0]);
		calls[i]->name = malloc(strlen(splitted[1]) + strlen(splitted[2]) + 2);
		calls[i]->name = ft_strjoin(splitted[1], splitted[2]);
		splitted[3][strlen(splitted[3])] = '\0'; // on supprime le saut de ligne
		calls[i]->type = strdup(splitted[3]);
		i++;
		// on passe a la ligne suivante
		free(line);
		line = get_next_line(fd);
	}
	calls[i] = NULL; // on termine le tableau par NULL pour marquer la fin
	return (calls);
}

// copy_calls creer une copie de la struct s_calls passee en parametre
t_calls **copy_calls(t_calls **calls) {
	if (!calls) return NULL;
	t_calls **copy = malloc((CALLS_AMOUNT + 1) * sizeof(t_calls));
	int i = 0;
	for (; calls[i]; i++) {
		copy[i] = malloc(sizeof(t_calls));
		copy[i]->name = strdup(calls[i]->name);
		copy[i]->num = strdup(calls[i]->num);
		copy[i]->type = strdup(calls[i]->type);
	}
	copy[i] = NULL;
	return (copy);
}

// display_calls affiche tous les calls d'une liste de s_calls
// avec toutes les informations ligne par ligne dans l'ordre de la liste
void display_calls(t_calls **calls) {
	if (!calls) return ;
	for (int i = 0; calls[i]; i++)
		printf("num: %s, nom : %s, type: %s\n", calls[i]->num, calls[i]->name, calls[i]->type);
}

// swap_calls intervertit les calls aux positions i et j d'une liste de struct s_calls
void swap_calls(t_calls **calls, int i, int j) {
	t_calls *tmp;
	tmp = calls[j];
	calls[j] = calls[i];
	calls[i] = tmp;
}
