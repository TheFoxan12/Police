#ifndef POLICE_H
# define POLICE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <sys/time.h>
# include <windows.h>
# include "utils/get_next_line.h"

# define CALLS_AMOUNT 1000
# define NUMBERS_AMOUNT 25

// stucture principale, pour le parsing du fichier
typedef struct s_calls {
	char	*num;
	char	*name;
	char	*type;
} t_calls;

// calls mais num est int
typedef struct s_callsv2 {
	int		num;
	char	*name;
	char	*type;
} t_callsv2;

// structure pour l'histogramme
typedef struct s_pair {
	char	*name;
	int		amount;
} t_pair;

// structure pour l'histogramme ameliore
typedef struct s_stats {
	char	*name;
	int		amount;
	int		in;
	int		out;
} t_stats;

// parsing
void	frees(char **strs);
void	free_calls(t_calls **calls);
t_calls	**parsefile(char *path);
t_calls **copy_calls(t_calls **calls);
void	display_calls(t_calls **calls);
void	swap_calls(t_calls **calls, int i, int j);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
//

// parsing v2
t_callsv2	**nums_to_int(t_calls **calls);
void		free_callsv2(t_callsv2 **calls);
t_callsv2	**copy_callsv2(t_callsv2 **calls);
void		display_callsv2(t_callsv2 **calls);
void		swap_callsv2(t_callsv2 **calls, int i, int j);
//

// sorts
t_calls		**bubble_sort(t_calls **calls);
t_calls		**insertion_sort(t_calls **calls);
t_callsv2	**bubble_sortv2(t_callsv2 **calls);
t_callsv2	**insertion_sortv2(t_callsv2 **calls);
//

// histograms
t_pair	**count_calls(t_callsv2 **calls);
int		find_name(t_pair **histogram, const char *name);
void	display_histogram(t_pair **histogram);
void	free_histogram(t_pair **histogram);
//

// histogramsv2
t_stats	**count_stats(t_callsv2 **calls);
int		find_namev2(t_stats **histogram, const char *name);
void	display_histogramv2(t_stats **histogram);
void	free_histogramv2(t_stats **histogram);
//

// histogramsint
int		*count_ints(int *list, int n);
int		*generate_randint(int n, int a, int b);
void	display_histogramints(int *list, int n);
int		*count_intsv2(const int *list, int n);
//

#endif //POLICE_H
