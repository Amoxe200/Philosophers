/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:47 by aaqari            #+#    #+#             */
/*   Updated: 2021/10/30 16:41:36 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>

typedef struct s_philo
{
    int philo_id;
    int nb_meals;
    int left_fork;
    int right_fork;
}               t_philo;

typedef struct s_info
{
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int nb_time_philo_must_eat;
    int nb_philos;
}t_info;

typedef struct s_table
{
    t_info *info;
    t_philo *philos;
       
}t_table;

#endif