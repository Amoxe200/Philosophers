/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:02:27 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/02 15:13:11 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int to_ms(struct timeval timer)
{
    int x;

    x = (((int)timer.tv_sec) * 1000) + (((int)timer.tv_usec) / 1000);
    return (x);
}

void    print(char *str, t_philo *philo)
{
    struct timeval now;

    pthread_mutex_lock(&philo->eat);
    gettimeofday(&now,NULL);
    printf("%d %d %s\n" ,to_ms(now) - to_ms(philo->info->base), philo->philo_id + 1, str);
    pthread_mutex_unlock(&philo->eat);
    //printf("%c\n", str[3]);
    if (str[3] == 'e')
    {
        //printf("i was here");
        usleep(philo->info->time_to_eat * 1000);
    }    
    else if (str[3] == 's')
    {
        //printf("i wasn't here\n");
        usleep(philo->info->time_to_sleep * 1000);
        
    }
}

void    *routine(void* arg)
{
    t_philo *philo;
    int     next;
    struct timeval now;

    philo = (t_philo *)arg;
    //if (philo->philo_id % 2 != 0)
    philo->lt_eat = to_ms(philo->info->base);
    next = (philo->philo_id + 1) % philo->info->nb_philos;
    while (1)
    {
        pthread_mutex_lock(&(philo->info->forks[philo->philo_id]));
        print("has taken a fork1", philo);
        pthread_mutex_lock(&(philo->info->forks[next]));
        print("has taken a fork2", philo);
        gettimeofday(&now,NULL);
        //philo->lt_eat = philo->lt_eat - to_ms(philo->info->base);
        //printf("%d\n",philo->lt_eat);
        print("is eating", philo);
        philo->nb_meals++;
        pthread_mutex_unlock(&(philo->info->forks[philo->philo_id]));
        pthread_mutex_unlock(&(philo->info->forks[next]));
        printf("klo\n");
        print("is sleeping", philo);
        print("is thinking", philo);
    }
}


void    thread_init(t_philo *philo, pthread_t *thread)
{
    int i;

    i = 0;
    while (i < philo->info->nb_philos)
    {
        pthread_create(&thread[i], NULL, &routine, &philo[i]);
        usleep(100);
        i++;
    }
}