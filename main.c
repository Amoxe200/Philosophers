/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:11:37 by aaqari            #+#    #+#             */
/*   Updated: 2021/11/02 19:49:04 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = (t_info *)malloc(sizeof(t_info));
	info->nb_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->nb_p_m_eat = ft_atoi(argv[5]);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philos);
	pthread_mutex_init(&info->printer, NULL);
	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	gettimeofday(&info->base, NULL);
	return (info);
}

t_philo	*init_data(int argc, char **argv)
{
	t_philo	*philo;
	t_info	*info;
	int		i;

	info = init_info(argc, argv);
	philo = malloc(sizeof(t_philo) * info->nb_philos);
	i = 0;
	while (i < info->nb_philos)
	{
		philo[i].philo_id = i;
		philo[i].info = info;
		philo[i].nb_meals = 0;
		philo[i].lt_eat = 0;
		philo[i].is_eating = 0;
		i++;
	}
	return (philo);
}

static	int	checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				perror("Error In Args Check Again\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	return (0);
}

int	supervisor(t_philo *philo)
{
	int				i;
	int				nb;
	struct timeval	now;

	i = 0;
	nb = philo[i].info->nb_philos;
	while (1)
	{
		i = 0;
		while (i < nb)
		{
			gettimeofday(&now, NULL);
			if (((int)(to_ms(now) - philo[i].lt_eat))
			> philo[i].info->time_to_die)
			{
				print("Is Dead", philo);
				return (0);
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	pthread_t	*thread;

	if (argc == 5 || argc == 6)
	{
		if (checker(argv))
			return (0);
		philos = init_data(argc, argv);
		thread = malloc(sizeof(pthread_t) * philos->info->nb_philos);
		thread_init(philos, thread);
	}
	return (0);
}
