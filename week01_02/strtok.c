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

  // skip any delim

  if (*next == '\0') {
    return NULL;
  }

  // Mark the start of the token
  char *start_address = next;

  // advance until delim or null
  // If delim overwrite it with '\0' and move past it, return start of token
  while (*next) {
    for (size_t i = 0; i < strlen(delim); i++) {
      if (*next == delim[i]) {
        if (next == str_start) {
          next++;
          continue;
        }
        *next = '\0';
        next++;
        return start_address;
      }
    }
    next++;
  }
  return start_address;
}
