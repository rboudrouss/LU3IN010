#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>
#include <unistd.h>
#include <time.h>

void lance_commande(char *commande)
{
  printf("Executing \"%s\"\n", commande);
  int resp = system(commande);
  if (resp != 0)
    printf("Error, command not executed properly\n");
}

void print_time(char *commande)
{
  struct timeval tv1, tv2;
  gettimeofday(&tv1, NULL);
  lance_commande(commande);
  gettimeofday(&tv2, NULL);

  printf("Time of %s: %ldμs\n", commande, (tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec));
}

void print_times(char *commande)
{
  struct tms *tms1, *tms2;
  tms1 = malloc(sizeof(struct tms));
  tms2 = malloc(sizeof(struct tms));

  clock_t tStart, tEnd;

  times(tms1);
  lance_commande(commande);
  times(tms2);
  tStart = times(tms1);
  tEnd = times(tms2);

  printf("%d %d %d %d \n", tms2->tms_utime, tms2->tms_stime, tms2->tms_cutime, tms2->tms_cstime);

  printf("Temps totale: %6.6f\n", (double)(tEnd - tStart) / CLOCKS_PER_SEC);
  printf("Temps utilisateur: %6.6f\n", (double)(tms2->tms_utime - tms1->tms_utime) / CLOCKS_PER_SEC);
  printf("temps système: %6.6f\n", (double)(tms2->tms_stime - tms1->tms_stime) / CLOCKS_PER_SEC);
  printf("temps utilisateur fils: %6.6f\n", (double)(tms2->tms_cutime - tms1->tms_cutime) / CLOCKS_PER_SEC);
  printf("temps système fils: %6.6f\n", (double)(tms2->tms_cstime - tms1->tms_cstime) / CLOCKS_PER_SEC);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s <commande>\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++)
    print_times(argv[i]);
}
