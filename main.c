/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:37 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 19:40:43 by aaqari           ###   ########.fr       */
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

void    parser(char **argv, t_info *info)
{
    int i;
    checker(argv);
    init(info);
    info->nb_philos = ft_atoi(argv[1]);
    info->time_to_die = ft_atoi(argv[2]);
    info->time_to_eat = ft_atoi(argv[3]);
    info->time_to_sleep = ft_atoi(argv[4]);
    info->nb_p_m_eat = ft_atoi(argv[5]);
    info->philo_id = malloc(sizeof(int) * info->nb_philos);
    i = 0;
    printf("Number of philos is %d\n", info->nb_philos);
    while (i < info->nb_philos)
    {
        info->philo_id[i] = i;
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
    parser(argv, &info);
    thread_init(&info);
    return (0);
} 