#include <assert.h>
#include <stdio.h>
#include <string.h>

#ifdef DEMO_OVERFLOW
my_strcpy(small, "hello");
#endif

size_t my_strlen_idx(const char *s);
size_t my_strlen_p(const char *s);
char *my_strcpy(char *dst, const char *src);

int main(void) {
  char buf[32];
  char small[4];
  char exact[6];

  assert(my_strlen_idx("hello") == strlen("hello"));
  assert(my_strlen_idx("") == strlen(""));
  assert(my_strlen_idx("h") == strlen("h"));
  assert(my_strlen_idx("hello world") == strlen("hello world"));

  assert(my_strlen_p("hello") == strlen("hello"));
  assert(my_strlen_p("") == strlen(""));
  assert(my_strlen_p("h") == strlen("h"));
  assert(my_strlen_p("hello world") == strlen("hello world"));

  memset(buf, 'X', sizeof(buf));
  assert(my_strlen_p(my_strcpy(buf, "")) == 0);

  memset(buf, 'X', sizeof(buf));
  assert(my_strcpy(buf, "hello") == buf);
  assert(strcmp(buf, "hello") == 0);

  my_strcpy(exact, "hello");
  assert(strcmp(exact, "hello") == 0);

  /*
   * Ok so this call is leading the address sanitizer to panic
   * A stack-buffer-overflow has happend on address 0x7b72d33f0034
   * This means that our small buffer that is allocated on the stack has
   * overflowed because we are copying a larger buffer into a smaller buffer The
   * specific error is a write of 1 byte to the buffer over the size
   * It is happening when calling my_strcpy on line 79
   */
  // my_strcpy(small, "hello");
}

/*
 * Why size_t and not int?
 * Well according to its man page size_t is an unsigned int that counts the
 * number of bytes
 * So it is an int just an unsigned one that is within a specific range
 * I guess the main idea of using size_t instead of int or uint
 * is because size_t is always sized according to the system as it is fixed by
 * the platform at compile time
 */
size_t my_strlen_idx(const char *s) {
  if (!s)
    return 0;

  size_t i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

/*
 * Why const char *s?
 * It's a promise, and the compiler enforces it: if your function tried to write
 * through s, it wouldn't compile. It also tells callers they can safely pass
 * read-only data like string literals.
 *
 * What happens if we pass NULL?
 * In my functions a 0 is returned but in the standard strlen function a SIGSEGV
 * signal is raised
 */
size_t my_strlen_p(const char *s) {
  if (!s)
    return 0;
  size_t counter = 0;
  while (*s) {
    s++;
    counter++;
  }
  return counter;
}

/*
 * The while loop runs while the expression is nonzero so the loop runs until we
 * are assigning \0 then we have assigned the null terminator to the dst buffer
 * and the expression is zero so the loop exits
 * The double parenthesis are so the complier doesn't complain
 */
char *my_strcpy(char *dst, const char *src) {
  char *start_p = dst;
  while ((*dst++ = *src++))
    ;
  return start_p;
}
