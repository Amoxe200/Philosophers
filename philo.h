/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:47 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 19:01:34 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*typedef struct s_philo
{
    int philo_id;
    int nb_meals;
    int left_fork;
    int right_fork;
}               t_philo;*/

typedef struct s_info
{
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_p_m_eat;
    int nb_philos;
    //--
    int *philo_id;
    int nb_meals;
    int left_fork;
    int right_fork;

}t_info;

t_info g_info;

typedef struct s_table
{
    t_info *info;
    //t_philo *philos;
       
}t_table;


void    parser(char **argv, t_info *info);
int		ft_atoi(const char *ptr);
int		ft_isdigit(int c);
int    thread_init(t_info *info);
void    init(t_info *info);

#endif