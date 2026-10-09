#include <assert.h>
#include <stdio.h>
#include <string.h>

char *my_strtok(char *str, const char *delim);

int main(void) {
  printf("Starting\n");
  char s_one[] = "Hello Wor,ld";
  char s_one_org[] = "Hello Wor,ld";

  char s_two[] = " , Hello Wor,ld";
  char s_two_org[] = " , Hello Wor,ld";

  char s_three[] = "a,,b";
  char s_three_org[] = "a,,b";

  char s_four[] = " , Hello Wor,ld , a,,b";
  char s_four_org[] = " , Hello Wor,ld , a,,b";

  char *token_one = my_strtok(s_one, " ,");
  char *token_one_org = strtok(s_one_org, " ,");
  assert(strcmp(token_one, token_one_org) == 0);

  token_one = my_strtok(NULL, " ,");
  token_one_org = strtok(NULL, " ,");
  assert(strcmp(token_one, token_one_org) == 0);

  token_one = my_strtok(NULL, " ,");
  token_one_org = strtok(NULL, " ,");
  assert(strcmp(token_one, token_one_org) == 0);

  char *token_two = my_strtok(s_two, " ,");
  char *token_two_org = strtok(s_two_org, " ,");
  assert(strcmp(token_two, token_two_org) == 0);

  token_two = my_strtok(NULL, " ,");
  token_two_org = strtok(NULL, " ,");
  assert(strcmp(token_two, token_two_org) == 0);

  token_two = my_strtok(NULL, " ,");
  token_two_org = strtok(NULL, " ,");
  assert(strcmp(token_two, token_two_org) == 0);

  char *token_three = my_strtok(s_three, " ,");
  char *token_three_org = strtok(s_three_org, " ,");
  assert(strcmp(token_three, token_three_org) == 0);

  token_three = my_strtok(NULL, " ,");
  token_three_org = strtok(NULL, " ,");
  assert(strcmp(token_three, token_three_org) == 0);

  char *token_four = my_strtok(s_four, " ,");
  char *token_four_org = strtok(s_four_org, " ,");
  assert(strcmp(token_four, token_four_org) == 0);

  token_four = my_strtok(NULL, " ,");
  token_four_org = strtok(NULL, " ,");
  assert(strcmp(token_four, token_four_org) == 0);

  token_four = my_strtok(NULL, " ,");
  token_four_org = strtok(NULL, " ,");
  assert(strcmp(token_four, token_four_org) == 0);

  token_four = my_strtok(NULL, " ,");
  token_four_org = strtok(NULL, " ,");
  assert(strcmp(token_four, token_four_org) == 0);

  token_four = my_strtok(NULL, " ,");
  token_four_org = strtok(NULL, " ,");
  assert(strcmp(token_four, token_four_org) == 0);

  assert(my_strtok(NULL, ",") == NULL);

  return 0;
}

char *my_strtok(char *str, const char *delim) {
  static char *next;

  if (str != NULL) {
    next = str;
  }

  while (*next && strchr(delim, *next)) {
    next++;
  }

  if (*next == '\0') {
    return NULL;
  }

  char *start_address = next;

  while (*next && !strchr(delim, *next)) {
    next++;
  }

  if (*next) {
    *next = '\0';
    next++;
  }
  return start_address;
}
