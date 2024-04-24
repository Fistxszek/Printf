#include "ft_printf.h"
#include <limits.h>

int main ()
{
	int i = ft_printf(" %x ", -42);
	printf("\n%d \n", i);
	// printf("printf: ");
	i = printf(" %x ", -42);
	printf("\n%d\n", i);
	return 0;
}
