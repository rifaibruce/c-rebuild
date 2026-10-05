#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Strtok_State {
  char *current_char;
};
struct Strtok_State my_strtok_state = {0};
char *my_strtok(char *str, const char *delim);

int main(void) {
  printf("Starting\n");
  char *token = my_strtok("Hello World", " ");
  printf("%s\n", token);
  return 0;
}

char *my_strtok(char *str, const char *delim) {
  if (my_strtok_state.current_char == NULL) {
    my_strtok_state.current_char = str;
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
