#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	h_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

int print_hex(unsigned long long arg)
{  
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	int char_count;

	char_count = 0;
	if (arg >= 16)
		print_hex(arg / 16);
	write(1, &upper_digits[arg % 16], 1);
	return 1;
}

int hex_length (unsigned long long nbr)
{
	print_hex(nbr);
	return (h_digits(nbr));
}

// int main ()
// {
// 	unsigned long long a = 87385744684;
// 	int i = 0;

// 	i = hex_length(a);
// 	return 0;
// }