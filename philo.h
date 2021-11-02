/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:47 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/02 18:00:47 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_info
{
    int time_to_eat;
    unsigned long long time_to_die;
    int time_to_sleep;
    int nb_p_m_eat;
    int nb_philos;
    struct timeval base;
    pthread_mutex_t     *forks;
    pthread_mutex_t     printer;
}t_info;


typedef struct s_philo
{
    int philo_id;
    int nb_meals;
    unsigned long long lt_eat;
    int is_eating;
    pthread_mutex_t     eat;
    t_info *info;
}t_philo;

t_philo    *init_data(int argc, char **argv);
int		ft_atoi(const char *ptr);

int		ft_isdigit(int c);
void    thread_init(t_philo *philo, pthread_t *thread);
void    init(t_info *info);
t_info  *init_info(int argc, char **argv);
unsigned long long to_ms(struct timeval timer);
void    print(char *str, t_philo *philo);
int supervisor(t_philo *philo);

#endif