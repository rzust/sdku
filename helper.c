#include <unistd.h>

void ft_putchar(char x)
{
  write(1, &x, 1);
}

void ft_putline(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);
    if (str[i + 1])
      ft_putchar(' ');
    i++;
  }
  ft_putchar('\n');
}

void ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    ft_putchar(str[i]);
    i++;
  }
}
