#include <stdio.h>
#include <stdlib.h>

void validatedWord(char *word, char *line);
void writeWord(char *word);
void readWords (FILE *file);
void readFile(char *filename);

int ignoring = 0;

/*
int main() {
    
    // Teste
    remove("/Users/RodrigoSoldi/Documents/Projetos/jflap/projetoLinguagemDeProgramacao/automatos/words.txt");
    char * filename = "/Users/RodrigoSoldi/Documents/Projetos/jflap/projetoLinguagemDeProgramacao/automatos/yourfile.txt";
    
    //remove("words.txt");
    //char *filename;
    //printf("Informe o nome do arquivo para leitura: ");
    //scanf("%s", filename);
    
    readFile(filename);
    printf("\n\nUm novo arquivo com o nome words.txt foi gerado\n");
    return 0;
}
*/

/*
    Método responsável por fazer o carregamento do arquivo a ser lido
 */
void readFile(char *filename) {
    FILE *handler = fopen(filename, "r");
    
    if (handler == NULL) {
        printf("%s", "O arquivo nao pode ser lido.");
        exit(0);
    }
    
    readWords(handler);
}

/*
    Faz a iteração por todo o arquivo
    enviando linha por linha para avialiação
 */
void readWords(FILE *file) {
    char word[1024];
    
    char * line = NULL;
    size_t len = 0;
    
    while (fscanf(file, "%1023s", word) == 1) {
        puts(word);
        
        getline(&line, &len, file);
        puts(line);
        validatedWord(word, line);
    }
}

/*
    Valida se a linha,
    lida palavra por palavra
    deve ser inserida no arquivo
    validando e retirando comentarios
 */
void validatedWord(char *word, char *line) {
    
    int lineLength = 0;
    char cLetter = line[0];
    while (cLetter != '\0') {
        ++lineLength;
        cLetter = line[lineLength];
    }
    
    char firstLetter = word[0];
    char secondLetter = word[1];
    
    if (firstLetter == '/' && secondLetter == '*' && ignoring == 0) {
        ignoring = 1;
    }
        
    char lastLetter = line[lineLength - 2];
    char lastLastLetter = line[lineLength - 3];
    
    if ((lastLastLetter == '*' && lastLetter == '/') || (firstLetter == '*' && secondLetter == '/')) {
        ignoring = 0;
        return;
    }
    
    
    if (ignoring == 1) {
        return;
    }
    
    if (strlen(word) >= 2) {
        
        if (firstLetter == '/' && secondLetter == '/') {
            return;
        }
    }
    writeWord(word);
    
    // Escrever line
    int i, j;
    char *currentWord = malloc(sizeof(char) * lineLength);
    for (i = 0, j = 0; i < lineLength; i++) {
        char currentLetter = line[i];
        if (currentLetter == ' ' || currentLetter == '\n' || currentLetter == '\t') {
            if (currentWord[0] != '\0') {
                currentWord[j] = '\0';
                writeWord(currentWord);
            }
            free(currentWord);
            memset(&currentWord[0], 0, sizeof(currentWord));
            currentWord = malloc(sizeof(char) * lineLength);
            currentWord[0] = '\0';
            j = 0;
        } else {
            if (currentLetter != '\0' && currentLetter != '\n' && currentLetter != '\t') {
                currentWord[j] = currentLetter;
                j++;
            }
        }
    }
}

/*
    Escreve a palavra no arquivo
 */
void writeWord(char *word) {
    if (word[0] == '\0') {
        return;
    }
    
    FILE *file = fopen("/Users/RodrigoSoldi/Documents/Projetos/jflap/projetoLinguagemDeProgramacao/automatos/words.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s\n", word);
    fclose(file);
}



