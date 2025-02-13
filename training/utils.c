#include "philo.h"

int	ft_atoi(const char *str)
{
	long int	number;
	int			isaret;

	isaret = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isaret = -1;
		str++;
	}
	int i = 0;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0') * isaret;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
		str++;
	}
	return (number);
}

int ft_isdigit(const char *hdr)
{
    while(*hdr)
    {
        if(!(*hdr >= '0' && *hdr <= '9'))
            return(0);
        hdr++;
    }
    return(1);
}