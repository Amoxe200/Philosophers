/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:37 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 23:22:16 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int checker(char **argv)
{
    int i;
    int j;
    
    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
        {
            if (!ft_isdigit(argv[i][j]))
            {
                perror("Error In Args Check Again\n");
                exit(1);
            }
        }
    }
    return (1);
}

void    init(t_info *info)
{
    info->nb_philos  = 1;
    info->time_to_die  = 0;
    info->time_to_eat = 0;
    info->time_to_sleep = 0;
    info->nb_p_m_eat = 0;
}

void    parser(int argc, char **argv, t_info *info)
{
    t_philo *philo;
    t_info  *info
    
    checker(argv);
    init(info);
    
    info->nb_philos = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        info->nb_p_m_eat = ft_atoi(argv[5]);
    info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
    pthread_mutex_init(&info->mutex, NULL);
    i = 0;
    while (i < info->nb_philos)
        {
            pthread_mutex_init(&info->forks[i], NULL);
            i++;
        }
}

int main(int argc, char **argv)
{
    
    t_info  info;
    
    if (argc != 5 && argc != 6)
    {
        perror("Error In argc");
        exit(1);
    }
    parser(argc, argv, &info);
    thread_init(&info);
    return (0);
} 