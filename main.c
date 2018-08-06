#ifndef SUDOKU_H
#define SUDOKU_H
# include <stdlib.h>

struct spot {
  int   id;
  char  current;
  int   empty;
  int   x;
  int   y;
};

void ft_putchar(char x);
void ft_putline(char *x);
void ft_putstr(char *x);

#endif

// #include "sudoku.h"
#include <stdio.h>

int count_spaces(char **rw)
{
  int i;
  int j;
  int c;

  i = 0;
  j = 0;
  c = 0;
  while (i < 9)
  {
    while (j < 9)
    {
      if (rw[i][j] == '.')
        c++;
      j++;
    }
    j = 0;
    i++;
  }
  return (c);
}

void set_blanks(char **rw, struct spot *blanks)
{
  int i;
  int j;
  int c;

  i = 0;
  j = 0;
  c = 0;
  struct spot blank;
  blank.current = '0';
  blank.empty = 1;
  while (i < 9)
  {
    while (j < 9)
    {
      if (rw[i][j] == '.')
      {
        blank.x = j;
        blank.y = i;
        blank.id = c;
        blanks[c] = blank;
        c++;
      }
      j++;
    }
    j = 0;
    i++;
  }
}

void print_board(char **rw)
{
  int i;

  i=0;
  while (i < 9)
  {
    ft_putline(rw[i]);
    i++;
  }
  ft_putchar('\n');
}

int check_row(char **rw, int y, char t)
{
  int j;

  j = 0;
  while (j < 9)
  {
    if (rw[y][j] == t)
      return (0); //can't take that value
    j++;
  }
  return (1); //validated
}

int check_column(char **rw, int x, char t)
{
  int i;

  i = 0;
  while (i < 9)
  {
    if (rw[i][x] == t)
      return (0); //can't take that value
    i++;
  }
  return (1); //validated
}

int check_grid(char **rw, int x, int y, char t)
{
  int i;
  int j;
  int remx;
  int remy;

  remx = x % 3;
  remy = y % 3;
  i = y - remy;
  j = x - remx;
  while (i < (y - remy + 3))
  {
    while (j < (x - remx + 3))
    {
      if (rw[i][j] == t)
        return (0); //can't take that value
      j++;
    }
    j = x - remx;
    i++;
  }
  return (1); //validated
}

// void check_solution(char **rw)
// {
//
// }

int solve(char **rw, struct spot *blanks, struct spot blank, int num_blanks)
{
  char current;

  if (blank.id >= num_blanks)
    return (1);
  current = blank.current + 1;
  while (current <= '9')
  {
    if (check_row(rw, blank.y, current) && check_column(rw, blank.x, current) && check_grid(rw, blank.x, blank.y, current))
    {
      rw[blank.y][blank.x] = current;
      blank.current = current;
      blanks[blank.id] = blank;
      print_board(rw);
      if (blank.id == num_blanks - 1)
      {
        printf("OUT: blank-id: %d current: %c (%d,%d)\n", blank.id, current, blank.x, blank.y);
        return (1);
      }
      else
      {
        printf("RECUR: blank-id: %d current: %c (%d,%d)\n", blank.id, current, blank.x, blank.y);
        return solve(rw, blanks, blanks[blank.id + 1], num_blanks);
      }
    }
    current++;
  }
  blank.current = '0';
  blanks[blank.id] = blank;
  if (blank.id - 1 >= 0)
  {
    rw[blank.y][blank.x] = '.';
    printf("BACKING UP\n");
    return solve(rw, blanks, blanks[blank.id - 1], num_blanks);
  }
  else
  {
    ft_putstr("Error");
    ft_putchar('\n');
    return (0);
  }
}



int		main(int argc, char **argv)
{
  int i;
  int j;
  char **rw;
  i = 0;
  j = 0;
  rw = malloc(sizeof(char*) * 9);
	if (argc == 10)
  {
    while (i < 9)
    {
      rw[i] = malloc(sizeof(char) * 10);
      while (j < 9)
      {
        rw[i][j] = argv[i + 1][j];
        j++;
      }
      rw[i][j] = '\0';
      j = 0;
      i++;
    }
    int blank_count;
    blank_count = 0;
    blank_count = count_spaces(rw);
    struct spot *blanks;
    blanks = malloc(sizeof(struct spot) * blank_count);
    set_blanks(rw, blanks);
    solve(rw, blanks, blanks[0], blank_count);
  }
  else
  {
    ft_putstr("Error");
    ft_putchar('\n');
  }
	return (0);
}
