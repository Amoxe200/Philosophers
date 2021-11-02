/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:02:27 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/01 20:03:49 by aaqari           ###   ########.fr       */
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
        if(pthread_create(&ph[i], NULL, &routine, &info->nb_philos) != 0)
        {
            perror("Failed to create thread");
            return (1);   
        }
        i++;
    }
    return (0);
}