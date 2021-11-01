/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:02:27 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 19:09:46 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine()
{
    
    return (NULL);
}


int    thread_init(t_info *info)
{
    int i;
    pthread_t ph[info->nb_philos];

    i = 0;
    while (i < info->nb_philos)
    {
        if(pthread_create(&ph[i], NULL, &routine, &info->philo_id[i]) != 0)
        {
            perror("Failed to create thread");
            return (1);   
        }
        i++;
    }
    i = 0;
    while (i < info->nb_philos)
    {
        if (pthread_join(ph[i], NULL) != 0)
            return (2);
        i++;
    }
    return (0);
}