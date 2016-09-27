#include <stdio.h>
#include <stdlib.h>


// Functions
static void validatedWord(char *word, char *line);
static void writeWord(char *word);
static void iterateFile(FILE *file);
static void readFile(char *filename);

static int ignoringLine = 0;

/*
    Método responsável por fazer o carregamento do arquivo a ser lido
 */
static void readFile(char *filename) {
    FILE *handler = fopen(filename, "r");
    
    if (handler == NULL) {
        printf("%s", "O arquivo nao pode ser lido.");
        exit(0);
    }
    
    iterateFile(handler);
}

/*
    Faz a iteração por todo o arquivo
    enviando linha por linha para avialiação
 */
static void iterateFile(FILE *file) {
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
static void validatedWord(char *word, char *line) {
    
    int lineLength = 0;
    char cLetter = line[0];
    while (cLetter != '\0') {
        ++lineLength;
        cLetter = line[lineLength];
    }
    
    char firstLetter = word[0];
    char secondLetter = word[1];
    
    if (firstLetter == '/' && secondLetter == '*' && ignoringLine == 0) {
        ignoringLine = 1;
    }
        
    char lastLetter = line[lineLength - 2];
    char lastLastLetter = line[lineLength - 3];
    
    if ((lastLastLetter == '*' && lastLetter == '/') || (firstLetter == '*' && secondLetter == '/')) {
        ignoringLine = 0;
        return;
    }
    
    
    if (ignoringLine == 1) {
        return;
    }
    
    if (strlen(word) >= 2) {
        
        if (firstLetter == '/' && secondLetter == '/') {
            return;
        }
    }
    writeWord(word);
    
    // Escrever line
    int it, jt;
    char *currentWord = malloc(sizeof(char) * lineLength);
    for (it = 0, jt = 0; it < lineLength; it++) {
        char currentLetter = line[it];
        if (currentLetter == ' ' || currentLetter == '\n' || currentLetter == '\t') {
            if (currentWord[0] != '\0') {
                currentWord[jt] = '\0';
                writeWord(currentWord);
            }
            free(currentWord);
            memset(&currentWord[0], 0, sizeof(currentWord));
            currentWord = malloc(sizeof(char) * lineLength);
            currentWord[0] = '\0';
            jt = 0;
        } else {
            if (currentLetter != '\0' && currentLetter != '\n' && currentLetter != '\t') {
                currentWord[jt] = currentLetter;
                jt++;
            }
        }
    }
}

/*
    Escreve a palavra no arquivo
 */
static void writeWord(char *word) {
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



