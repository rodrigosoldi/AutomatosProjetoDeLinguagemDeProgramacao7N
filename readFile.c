#include <stdio.h>
#include <stdlib.h>

void write_word(char *word) {
   FILE *f = fopen("words.txt", "a");

   if (f == NULL) {
       printf("Error opening file!\n");
       exit(1);
   }

   char x[1024];
   while (fscanf(f, "%1023s", x) == 1);

   const char *text = word;
   fprintf(f, "%s\n", text);
   fclose(f);
}

void read_words (FILE *f) {
    char x[1024];
    while (fscanf(f, "%1023s", x) == 1) {
        puts(x);
        write_word(x);
    }
}

char* ReadFile(char *filename) {
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");
   read_words(handler);
   return buffer;
}

int main() {
   char *filename;
   printf("Informe o nome do arquivo para leitura: ");
   scanf("%s", filename);
   ReadFile(filename);
   printf("\n\nUm novo arquivo com o nome words.txt foi gerado\n");
   return 0;
}
