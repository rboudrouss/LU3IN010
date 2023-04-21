#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Please enter numbers as parameters\n ex : ./main 1 2 3\n");
    return 1;
  }
  int max = atoi(argv[1]), act;

  for (int i = 2; i < argc; i++)
  {
    act = atoi(argv[i]);
    if (max < act)
      max = act;
  }

  printf("The maximum is %d\n", max);
  return 0;
}