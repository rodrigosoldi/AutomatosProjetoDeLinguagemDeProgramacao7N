//#include <stdio.h>
//#include <stdlib.h>
//
//void write_word(char *word) {
//   FILE *file = fopen("words.txt", "a");
//
//   if (file == NULL) {
//       printf("Error opening file!\n");
//       exit(1);
//   }
//
//   char currentWord[1024];
//   while (fscanf(file, "%1023s", currentWord) == 1);
//
//   const char *text = word;
//   fprintf(file, "%s\n", text);
//   fclose(file);
//}
//
//void read_words (FILE *file) {
//    char currentWord[1024];
//    while (fscanf(file, "%1023s", currentWord) == 1) {
//        puts(currentWord);
//        write_word(currentWord);
//    }
//}
//
//char* ReadFile(char *filename) {
//   char *buffer = NULL;   
//   FILE *handler = fopen(filename, "r");
//   read_words(handler);
//   return buffer;
//}
//
//void startReadFile() {
//    char *filename;
//    printf("Informe o nome do arquivo para leitura: ");
//    scanf("%s", filename);
//    ReadFile(filename);
//    printf("\n\nUm novo arquivo com o nome words.txt foi gerado\n");
//}
//
////int main() {
////   
////   return 0;
////}
