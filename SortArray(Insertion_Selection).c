
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void remplirTableauAvecEntiersAleatoires(int * tab, int taille, int valeurMax);
/* Preconditions : tab est un tableau pouvant contenir "taille" entiers.
   Postconditions : tab est rempli avec des nombres entiers aleatoires compris
   entre 0 (inclus) et ValeurMax (exclue). */

void triParSelectionDuMinimum(int * tab, int taille);
/* Preconditions : tab est un tableau contenant "taille" entiers.
   Postconditions : les elements de tab sont ranges dans l'ordre croissant
   a l'aide de l'algorithme de tri par selection du minimum. */


void triParInsertion(int * tab, int taille);
/* Preconditions : tab est un tableau contenant "taille" entiers.
   Postconditions : les elements de tab sont ranges dans l'ordre croissant
   a l'aide de l'algorithme de tri par insertion. */





int main()
{
  int n, algo;
  int * mesNombres;
 clock_t heureDebut, heureFin;

 /* input the table size */
  do{
    printf("Table size: ? ( Size must be less than 1000000 (1 million) ) \n");
    scanf("%d", &n);
  }
  while( (n < 1) || (n > 1000000));



  // Display the array before sorting
   // displayArray(arr , size , "The generated array");



  /* Saisie de l'algorithme de tri a utiliser */
  do
    {
      printf("\nChoisissez l'algorithme de tri a executer : \n");
      printf("0 : selection du minimum\n");
      printf("1 : insertion\n");
      scanf("%d", &algo);
    }
  while ((algo < 0) || (algo > 1));

  mesNombres = (int *) malloc(n*sizeof(int));
  remplirTableauAvecEntiersAleatoires(mesNombres, n, 1000000);

  heureDebut = clock();
  switch(algo)
    {
    case 0: {triParSelectionDuMinimum(mesNombres, n); break;}
    case 1: {triParInsertion(mesNombres, n); break;}
    }
  heureFin = clock();



  printf(" Execution time: %f sec.\n", ((float)(heureFin - heureDebut))/CLOCKS_PER_SEC);


  free(mesNombres);

  exit(EXIT_SUCCESS);
}



void remplirTableauAvecEntiersAleatoires(int * tab, int taille, int valeurMax)
{
  int i;

  for(i =0; i < taille; i++)
    {
      tab[i] = (int)(rand() / (((double)RAND_MAX + 1)/ valeurMax));
    }
}



void triParSelectionDuMinimum(int * tab, int taille)
{
  int i, j;
  int indmin;
  int min;

  for(i = 0; i < taille - 1; i++)
    {

      indmin = i;
      for(j = i+1; j < taille; j++)
        {
          if (tab[j] < tab[indmin])
            {
              indmin = j;
            }
        }
      min = tab[indmin];
      tab[indmin] = tab[i];
      tab[i] = min;
    }
}



void triParInsertion(int * tab, int taille)
{
  int i, j;
  int elt_a_placer;

  for(j = 1; j < taille; j++)
    {
      elt_a_placer = tab[j];
      i = j - 1;
      while ((i >= 0) && (tab[i] > elt_a_placer))
        {
          tab[i+1] = tab[i];
          i--;
        }
      tab[i+1] = elt_a_placer;
    }
}


void displayArray(int *arr, int size, char *s)
{
	int i;
     printf("\n%s : \n", s);
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
