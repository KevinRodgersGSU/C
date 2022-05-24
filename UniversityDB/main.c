#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct University
{
  char name[50];
  char city[20];
  char state[3];
  int rank;
  int tuition;
};

struct University inputData(char *name, char *city, char *state, int rank, int tuition)
{
  struct University u;
  strcpy(u.name, name);
  strcpy(u.city, city);
  strcpy(u.state, state);
  u.rank = rank;
  u.tuition = tuition;
  return u;
}

void printInfo(struct University u)
{
  printf("Name: %-50sCity: %-20sState: %-3sRank: %-3dTution: %d\n", u.name, u.city, u.state, u.rank, u.tuition);
}

void printTopUniversity(struct University *u, int rank)
{
  printf("\nThe top %dth universities\n", rank);
  for (int i = 0; i < 10; i++)
  {
    if (u[i].rank < rank)
      printInfo(u[i]);
  }
}

void printStateofUniversity(struct University *u, char *state)
{
  printf("\nUniversities in State of %s\n", state);
  for (int i = 0; i < 10; i++)
  {
    if (!strcmp(u[i].state, state))
      printInfo(u[i]);
  }
}

void printMinMaxTuitionUniversity(struct University *u)
{
  int min = 0, max = 0, maxTut = 0;
  int minTut = u[0].tuition;
  for (int i = 0; i < 10; i++)
  {
    if (u[i].tuition < minTut)
    {
      minTut = u[i].tuition;
      min = i;
    }
    if (u[i].tuition > maxTut)
    {
      maxTut = u[i].tuition;
      max = i;
    }
  }
  printf("\nUniversities with highest and lowest tuition\n");
  printInfo(u[max]);
  printInfo(u[min]);
}

void printSortedUniversity(struct University *u)
{
  struct University v;
  printf("\nUniversities Sorted from highest to lowest tution\n");
  for (int i = 0; i < 10; i++)
  {
    for (int j = i; j < 10; j++)
    {
      if (u[i].tuition < u[j].tuition)
      {
        v = u[i];
        u[i] = u[j];
        u[j] = v;
      }
    }
  }
  for (int i = 0; i < 10; i++)
  {
    printInfo(u[i]);
  }
}

int sum(struct University *u, int n)
{
  if (n == 0)
  {
    return 0;
  }
  return (sum(u + 1, n - 1)) + u->tuition;
}

int compare(const void *a, const void *b)
{
  int x = ((struct University *)a)->tuition;
  int y = ((struct University *)b)->tuition;
  return (x - y);
}

int main()
{
  struct University university[10];
  university[0] = inputData("Princeton University", "Princeton", "NJ", 1, 45320);
  university[1] = inputData("University of Virginia", "Charlottesville", "VA", 24, 52040);
  university[2] = inputData("Boston College", "Chestnut Hill", "MA", 31, 51296);
  university[3] = inputData("Georgia Institute of Technology", "Atlanta", "GA", 34, 32404);
  university[4] = inputData("Lehigh University", "Bethlehem", "PA", 44, 48320);
  university[5] = inputData("University of Chicago", "Chicago", "IL", 3, 52491);
  university[6] = inputData("Duke University", "Durham", "NC", 8, 51265);
  university[7] = inputData("University of Georgia", "Athens", "GA", 56, 29844);
  university[8] = inputData("University of Denver", "Denver", "CO", 86, 46362);
  university[9] = inputData("Loyola University Chicago", "Chicago", "IL", 99, 26270);

  for (int i = 0; i < 10; i++)
  {
    printInfo(university[i]);
  }
  printTopUniversity(university, 17);
  printStateofUniversity(university, "GA");
  printMinMaxTuitionUniversity(university);
  printSortedUniversity(university);
  printf("\nThe average tutition of the universities: $%d\n", sum(university, 10) / 10);
  printf("\nUniversity list after being sorted from low to high with quick sort\n");
  qsort(university, 10, sizeof(university[0]), compare);
  for (int i = 0; i < 10; i++)
  {
    printInfo(university[i]);
  }
  return 0;
}