#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strtok(char *str, const char *delim);

int main(void) {
  printf("Starting\n");
  char s[] = " , Hello Wor,ld";
  char s_org[] = " , Hello Wor,ld";

  char *token = my_strtok(s, " ,");
  char *token_org = strtok(s_org, " ,");
  assert(strcmp(token, token_org) == 0);

  token = my_strtok(NULL, " ,");
  token_org = strtok(NULL, " ,");
  assert(strcmp(token, token_org) == 0);

  printf("%s\n", token);
  token = my_strtok(NULL, " ,");
  token_org = strtok(NULL, " ,");
  assert(strcmp(token, token_org) == 0);

  printf("%s\n", token);
  token = my_strtok(NULL, " ,");
  token_org = strtok(NULL, " ,");
  assert(strcmp(token, token_org) == 0);

  return 0;
}

char *my_strtok(char *str, const char *delim) {
  static char *next;
  char *str_start = str;

  if (str != NULL) {
    next = str;
  }

  while (*str) {
    if (*str == *delim) {
      *str = '\0';
      str++;
      my_strtok_state.current_char = str;
      return str;
    }
    str++;
  }
  return str;
}
