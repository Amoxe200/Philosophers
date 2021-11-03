/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:02:27 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/03 12:50:29 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void mysleep(unsigned int ms)
{
	unsigned int t;
	struct timeval	now;
	struct timeval	end;

	gettimeofday(&now, NULL);
	usleep((ms * 1000) * 0.9);
	t = to_ms(now);
	gettimeofday(&end, NULL);
	while(to_ms(end) - t <= ms)
	{
		gettimeofday(&end, NULL);
		continue;
	}	
}

unsigned int	to_ms(struct timeval timer)
{
	unsigned int	x;

	x = (((unsigned int)timer.tv_sec) * 1000)
		+ (((unsigned int)timer.tv_usec) / 1000);
	return (x);
}

void	print(char *str, t_philo *philo)
{
	struct timeval	now;

	if (str[3] == 'e' || str[3] == 'D')
		pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&philo->info->printer);
	gettimeofday(&now, NULL);
	printf("%d %d %s\n", (int)(to_ms(now)
			- to_ms(philo->info->base)), philo->philo_id + 1, str);
	if (str[3] != 'D')
		pthread_mutex_unlock(&philo->info->printer);
	if (str[3] == 'e')
		mysleep(philo->info->time_to_eat);
	else if (str[3] == 's')
		mysleep(philo->info->time_to_sleep);
	if (str[3] == 'e')
		pthread_mutex_unlock(&philo->eat);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	int				next;
	struct timeval	now;

	philo = (t_philo *)arg;
	philo->lt_eat = to_ms(philo->info->base);
	next = (philo->philo_id + 1) % philo->info->nb_philos;
	while (1)
	{
		pthread_mutex_lock(&philo->info->forks[philo->philo_id]);
		print("has taken a fork1", philo);
		pthread_mutex_lock(&philo->info->forks[next]);
		print("has taken a fork2", philo);
		gettimeofday(&now, NULL);
		philo->lt_eat = to_ms(now);
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
		usleep(100);
		i++;
	}
	supervisor(philo);
}
