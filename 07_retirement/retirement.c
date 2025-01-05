#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

 struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired);
void calculate_money(int* age, double* total, retire_info status);

int main(void)
{
  retire_info working = {489, 1000, 0.045 / 12};
  retire_info retired = {384, -4000, 0.01 / 12};
  int startAge = 327;
  double initial = 21345;

  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired)
{
  calculate_money(&startAge, &initial, working);
  calculate_money(&startAge, &initial, retired);
}

void calculate_money(int* age, double* total, retire_info status)
{
  for (int i = 0; i < status.months; i++)
    {
      printf("Age %3d month %2d you have $%.2lf\n", *age / 12, *age % 12, *total);
      *total += *total * status.rate_of_return + status.contribution;
      (*age)++;
    }
}
