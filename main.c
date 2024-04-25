#include "ft_printf.h"
#include <limits.h>

int main ()
{
	char * a = "abdjabs";
	int i = ft_printf("nazywam się %s, moja ulubion liczba to %d. moje imie zaczyna się na literę %c. \nliczba %i jest równa w formacie hexadecymalnym: %x lub wielkimi literami %X. nieasygnowany int = %u %% %% %%%%%%. adres:%p ","kacper", 20, 'c', -675432747, -675432747, -675432747, -8237490, a);
	printf("\nDługość: %d \n", i);
	// printf("printf: ");
	i = printf("nazywam się %s, moja ulubion liczba to %d. moje imie zaczyna się na literę %c. \nliczba %i jest równa w formacie hexadecymalnym: %x lub wielkimi literami %X. nieasygnowany int = %u %% %% %%%%%%. adres:%p ","kacper", 20, 'c', -675432747, -675432747, -675432747, -8237490, a);
	printf("\nDługość: %d\n", i);

	ft_printf("%X\n", 768249);
	printf("%X\n", 768249);
	ft_printf("%X\n", -675432747);
	printf("%X\n", -675432747);

	ft_printf("%x %X %x %X\n", -675432747, -675432747, -675432747, -8237490);
	printf("%x %X %x %X\n", -675432747, -675432747, -675432747, -8237490);

	a = NULL;
	i = ft_printf("%s", a);
	printf("\nDługość mój: %d\n", i);
	i = printf("%s", a);
	printf("\nDługość: %d\n", i);

	
	return 0;
}
