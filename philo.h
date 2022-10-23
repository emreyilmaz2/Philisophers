#ifndef PHILO_H
#define PHILO_H

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>
#include "sys/time.h"


//structs
struct	s_main;

typedef struct s_philo
{
	int				   philo_id;
	int				   r_fork_id;
	int				   l_fork_id;
	int				   counter_eat;
	unsigned long long last_eat;
	pthread_t			thread_id;
	struct s_mother		*link;
}					t_philo;

typedef struct s_mother
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	bool			dead;
	bool			is_eat_all;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	test;
	time_t			start_time;
	t_philo			*all_philos;
}					t_mother;


//functions
int	ft_atoi(const char *str);
int ft_isdigit(const char *hdr);

#endif