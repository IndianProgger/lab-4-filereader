#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  FILE *file = NULL;

  int i,c;

  int   num;
  char  string[256];
  float fl;

  if (argc > 1)
  {
    file = fopen(argv[1], "rb");
  }
  else
  {
    char fileN[256];

    printf("Data file name was not provided. Please, enter file name: ");
    scanf("%s", fileN);
    file = fopen(fileN, "rb");
  }

  if (file == NULL)
  {
    printf("Error: this file can not be read!\n");
    exit(1);
  }
  i = 1;
  while ((c = getc(file))!=EOF)
  {
    ungetc(c, file);
    fread(&num, sizeof(int), 1, file);
    fread(string, sizeof(char), 256, file);
    fread(&fl, sizeof(float), 1, file);
    printf("Chunk %d:"   "\t%d"   "\t%s"   "\t%f\n", i, num, string, fl);
    i++;
  }
  return 0;
}