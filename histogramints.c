# include "police.h"

// is_in renvoie 1 si l'entier d est dans la liste list de taille n
int	is_in(const int *list, int n, int d) {
	for (int i = 0; i < n; i++)
		if (list[d] > 0) return 1;
	return 0;
}

// reset met toutes les cases du tableau de taille n passe en parametre
// a 0
void reset(int **list, int n) {
	for (int i = 0; i < n; i++)
		(*list)[i] = 0;
}

// generate_randint renvoie une liste allouee de n ints entre a inclus et b exclus
int *generate_randint(int n, int a, int b) {
	int *res = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		res[i] = (rand() % (b + abs(a))) - abs(a);
	return res;
}

// display_histogramints affiche la liste list de n entiers passee en parametre
void display_histogramints(int *list, int n) {
	for (int i = 0; i < n; i++)
		printf("%d : %d\n", i, list[i]);
}

// count_ints renvoie un histogramme de la liste list de taille n
int *count_ints(int *list, int n) {
	int *res = malloc(NUMBERS_AMOUNT * sizeof(int));
	reset(&res, NUMBERS_AMOUNT);

	for (int i = 0; i < n; i++) {
		if (is_in(res, NUMBERS_AMOUNT, list[i]))
			res[list[i]]++;
		else
			res[list[i]] = 1;
	}
	return res;
}

// count_intsv2 renvoie un histogramme de la liste list de taille n
// beaucoup plus efficace que count_ints
int *count_intsv2(const int *list, int n) {
	int *res = malloc(NUMBERS_AMOUNT * sizeof(int));
	reset(&res, NUMBERS_AMOUNT);

	for (int i = 0; i < n; i++)
		res[list[i]]++;
	return res;
}
