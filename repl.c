/* cc -std=c99 -Wall repl.c -ledit -o repl */

#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

static char buf[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buf, 2048, stdin);
  char* cpy = malloc(strlen(buf) + 1);
  strcpy(cpy, buf);
  cpy[strlen(cpy) - 1] = \'\0\';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
/* #include <editline/history.h> */
#endif

int main(int argc, char** argv) {
  /* version and exit information */
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while(1) {
    /* output and get input */
    char* input = readline("user> ");

    /* add input to history */
    add_history(input);

    /* echo input back to user */
    printf("%s\n", input);

    /* free retrieved input */
    free(input);
  }

  return 0;
}
