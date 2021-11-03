/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:02:27 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/03 16:40:44 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	itsmytime(void)
{
	struct timeval	ctime;

	gettimeofday(&ctime, NULL);
	return ((ctime.tv_sec * 1000) + (ctime.tv_usec / 1000));
}

void	mysleep(long int sleeptime)
{
	long	end;
	long	start;

	start = itsmytime();
	end = start + sleeptime;
	while (itsmytime() < end)
		usleep(100);
}

int	print(char *str, t_philo *philo)
{
	if (str[3] == 'e' || str[3] == 'D')
		pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&philo->info->printer);
	printf("%d %d %s\n", itsmytime() - philo->info->base,
		philo->philo_id + 1, str);
	if (str[3] != 'D')
		pthread_mutex_unlock(&philo->info->printer);
	if (str[3] == 'e')
		mysleep(philo->info->time_to_eat);
	else if (str[3] == 's')
		mysleep(philo->info->time_to_sleep);
	if (str[3] == 'e')
		pthread_mutex_unlock(&philo->eat);
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	int				next;

	philo = (t_philo *)arg;
	next = (philo->philo_id + 1) % philo->info->nb_philos;
	while (1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->philo_id]);
		print("has taken a fork", philo);
		pthread_mutex_lock(&philo->info->forks[next]);
		print("has taken a fork", philo);
		philo->lt_eat = itsmytime();
		print("is eating", philo);
		philo->nb_meals++;
		pthread_mutex_unlock(&philo->info->forks[philo->philo_id]);
		pthread_mutex_unlock(&philo->info->forks[next]);
		print("is sleeping", philo);
		print("is thinking", philo);
	}
}

void	thread_init(t_philo *philo, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < philo->info->nb_philos)
	{
		pthread_create(&thread[i], NULL, &routine, &philo[i]);
		i += 2;
	}
	usleep(60);
	i = 1;
	while (i < philo->info->nb_philos)
	{
		pthread_create(&thread[i], NULL, &routine, &philo[i]);
		i += 2;
	}
	supervisor(philo);
}
