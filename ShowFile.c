#include <stdio.h>
#include <stdlib.h>

void read_words (FILE *f) {
    char x[1024];
    while (fscanf(f, "%1023s", x) == 1) {
        puts(x);
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
   return 0;
}
