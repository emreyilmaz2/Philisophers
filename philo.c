#include "philo.h"

void    ft_print_warning(void)
{
    printf("    ____________________________________\n");
    printf("    |  please enter 4 or 5 arguments   |\n");
    printf("    |__________________________________|\n");
    printf("    |    [1] number of philosopher     |\n");
    printf("    |         [2] time to die          |\n");
    printf("    |         [3] time to eat          |\n");
    printf("    |        [4] time to sleep         |\n");
    printf("    | [5] how many times they must eat |\n");
    printf("    |__________________________________|\n");
}

int ft_ctrl_arguments(int arrc, char **arr)
{
    size_t i = 0;
    if(arrc < 5 || arrc > 6)
    {
        ft_print_warning();
        return(1);
    }
    while(arr[++i])
    {
        if(!ft_isdigit(arr[i]) || (!ft_atoi(arr[i])))
        {
            printf("you might be enter the wrong answers");
            return (1);
        }
    }
    return(0);
}

void    ft_init_philos(t_mother *platon)
{
    int i;
    i = 0;
    platon->all_philos = malloc(sizeof(t_philo)*platon->num_philo);
    while(i < platon->num_philo)
    {
        platon->all_philos[i].philo_id = i;
        platon->all_philos[i].counter_eat = 0;
        platon->all_philos[i].l_fork_id = i;
        platon->all_philos[i].r_fork_id = ((i+1)%platon->num_philo);
        platon->all_philos[i].link = platon;
        platon->all_philos[i].last_eat = gettime();
        i++;
    }
}

void    ft_init_common(t_mother *descartes, int argc, char **argv)
{
    int len;
    int i;
    i=0;
    descartes->num_philo = ft_atoi(argv[1]);
    len = descartes->num_philo;
    descartes->time_to_die = ft_atoi(argv[2]);
    descartes->time_to_eat = ft_atoi(argv[3]);
    descartes->time_to_sleep = ft_atoi(argv[4]);
    if(argc==6)
        descartes->num_to_eat = ft_atoi(argv[5]);
    else
        descartes->num_to_eat = -1;

    descartes->dead = false;
    descartes->is_eat_all = false;
    descartes->start_time = gettime();
    descartes->mutex_fork = malloc(sizeof(pthread_mutex_t)*descartes->num_philo);
    if(!descartes->mutex_fork)
        return;
    while(i<len)
        pthread_mutex_init(&descartes->mutex_fork[i++],NULL);
    ft_init_philos(descartes);
}

void    time_to_dinner(t_philo *sude)
{
    pthread_mutex_lock(sude->link->mutex_fork[sude->l_fork_id]);
    // printf("left alindi");
    pthread_mutex_lock(sude->link->mutex_fork[sude->r_fork_id]);
    // printf("right alindi");
    // printf("eating");
    time_machine(sude->link->time_to_eat, sude->link);
    sude->last_eat = gettime();
    pthread_mutex_unlock(sude->link->mutex_fork[sude->l_fork_id]);
    pthread_mutex_unlock(sude->link->mutex_fork[sude->r_fork_id]);
    sude->counter_eat++;
}

void    create_threads(t_mother *descartes)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while(++i < descartes->num_philo)
        pthread_create(&descartes->all_philos[i].thread_id, NULL, start, &descartes->all_philos[i]);
    die();
    while (++j < descartes->num_philo)
        pthread_join(descartes->all_philos[j].thread_id, NULL);
}

void    time_machine(int time, t_mother *common)
{
    unsigned long long beginning;

    beginning = gettime();//15:35 15:36
    while(common->dead == false)
    {
        if((gettime()-beginning) >= time)
            break;
        usleep(42);
    }
}

void    *start(void *toto)
{
    t_philo *philo;

    philo = (t_philo *)toto;
    if(philo->philo_id % 2)
        usleep(1000);
    while(philo->link->dead == false)
    {
        if(philo->link->dead)
            break;
        time_to_dinner(philo);
        if(philo->link->num_to_eat <= philo->counter_eat && philo->link->num_to_eat != -1)
        {
            philo->link->is_eat_all == ture;
            break;
        }
        if(philo->link->dead == true)
            break;
        // printf("sleeping");
        time_machine(philo->link->time_to_sleep, philo->link);
        if(philo->link->dead == true)
            break;
        // printf("thinking");
    }
    return(NULL);
}

int main(int argc, char **argv)
{
    t_mother *kant;
    kant = malloc(sizeof(sizeof(t_mother)));
    if(!kant)
        return(0);
    if(ft_ctrl_arguments(argc, argv))
        return(1);
    ft_init_common(kant, argc, argv);
    return(0);
}