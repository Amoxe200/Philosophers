/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoxe <amoxe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:47 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 23:16:30 by amoxe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_info
{
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_p_m_eat;
    int nb_philos;
    pthread_mutex_t     *forks;
    pthread_mutex_t     mutex;
    
}t_info;


typedef struct s_philo
{
    int *philo_id;
    int nb_meals;
    int left_fork;
    int right_fork;
    t_info *info;

}t_philo;

t_info g_info;

typedef struct s_table
{
    t_info *info;
    //t_philo *philos;
       
}t_table;


void    parser(int argc, char **argv, t_info *info);
int		ft_atoi(const char *ptr);
int		ft_isdigit(int c);
int    thread_init(t_info *info);
void    init(t_info *info);

#endif