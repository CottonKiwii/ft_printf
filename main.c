
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
/* CHAR TESTS */
	printf("CHARACTER TESTS\n\n");
	int f = ft_printf("%c\n", 1);
	int c = printf("%c\n", 1);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%c\n", 'A');
	c = printf("%c\n", 'A');
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%c\n", 127);
	c = printf("%c\n", 127);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%c, %c, %c\n", 'F', 'U', 'K');
	c = printf("%c, %c, %c\n", 'F', 'U', 'K');
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* STR TESTS */
	char *s = "GAY";
	printf("STRING TESTS\n\n");
	f = ft_printf("%s\n", NULL);
	c = printf("%s\n", NULL);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%s\n", "");
	c = printf("%s\n", "");
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%s\n", s);
	c = printf("%s\n", s);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%s\n", "Hello World");
	c = printf("%s\n", "Hello World");
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("Goodbye %s!\n", "Jojo");
	c = printf("Goodbye %s!\n", "Jojo");
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%s, %s and %s...\n", "Hans", "Joseph", "Gray");
	c = printf("%s, %s and %s\n", "Hans", "Joseph", "Gray");
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* INT TESTS */
	printf("INTEGER TESTS\n\n");
	f = ft_printf("%i\n", 42);
	c = printf("%i\n", 42);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%i\n", 0);
	c = printf("%i\n", 0);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%i\n", -1);
	c = printf("%i\n", -1);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%i\n", -1);
	c = printf("%i\n", -1);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%i\n", 2147483647);
	c = printf("%i\n", 2147483647);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%i\n", -2147483648);
	c = printf("%i\n", -2147483648);
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* DEC TESTS */
	printf("DECIMAL TESTS\n\n");
	f = ft_printf("%d\n", 24);
	c = printf("%d\n", 24);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%d\n", 0);
	c = printf("%d\n", 0);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%d\n", -1);
	c = printf("%d\n", -1);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%d\n", -2147483648);
	c = printf("%d\n", -2147483648);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%d\n", 2147483647);
	c = printf("%d\n", 2147483647);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%d\n", -1000);
	c = printf("%d\n", -1000);
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* PTR TESTS */
	printf("POINTER TESTS\n\n");
	char *p;
	f = ft_printf("%p\n", NULL);
	c = printf("%p\n", NULL);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%p\n", p);
	c = printf("%p\n", p);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%p\n", 0xFFFFFFFFFFFFFFFFUL);
	c = printf("%p\n", 0xFFFFFFFFFFFFFFFFUL);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%p\n", 0x54);
	c = printf("%p\n", 0x54);
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* HEX TESTS */
	printf("HEXADECIMAL TESTS\n\n");
	f = ft_printf("%x\n", 0x54);
	c = printf("%x\n", 0x54);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%x\n", 2147483647);
	c = printf("%x\n", 2147483647);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%x\n", -2147483648);
	c = printf("%x\n", -2147483648);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	f = ft_printf("%x\n", 0);
	c = printf("%x\n", 0);
	printf("ft len is %d, cl len is %d\n\n", f, c);
/* % TESTS */
	printf("PERCENTSIGN TESTS\n\n");
	f = ft_printf("%%%\n", 0x54);
	c = printf("%%%\n", 0x54);
	printf("ft len is %d, cl len is %d\n\n", f, c);
	return (0);
}
