#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(char[], int);
void decimal_to_octal(char[], int);
void decimal_to_hexa(char[], int);
bool is_valid(int);

int main(int argc, char *argv[]) {
  printf("------------------------\n");
  printf("   Number Conversions\n");
  printf("------------------------\n");

  char str[20] = "19280";
  printf("Number in decimal: %s", str);

  int count = sizeof(str) / sizeof(char);

  printf("\nBinary: ");
  decimal_to_binary(str, count);

  printf("\nOctal: ");
  decimal_to_octal(str, count);

  printf("\nHexa: ");
  decimal_to_hexa(str, count);

  return 0;
}

void decimal_to_binary(char number[], int numCount) {
  int x = atoi(number);
  int answer[20];
  int index = 0;

  // Validate
  if (is_valid(x) == false) {
    return;
  }

  // Convert "x" to binary
  while (x != 0) {
    answer[index] = x % 2;
    index++;

    x = x / 2;
  }

  // Print answer in reverse order
  for (int i = index - 1; i >= 0; i--) {
    printf("%d", answer[i]);
  }
}

void decimal_to_octal(char number[], int numCount) {
  int x = atoi(number);
  int answer[20];
  int index = 0;

  while (x != 0) {
    answer[index] = x % 8;
    index++;
    x = x / 8;
  }

  // Print answer in reverse order
  for (int i = index - 1; i >= 0; i--) {
    printf("%d", answer[i]);
  }
}

void decimal_to_hexa(char number[], int numCount) {
  int x = atoi(number);
  char answer[20];
  int index = 0;

  while (x != 0) {
    int remainder = x % 16;
    switch (remainder) {
    case 10:
      answer[index] = 'A';
      break;

    case 11:
      answer[index] = 'B';
      break;

    case 12:
      answer[index] = 'C';
      break;

    case 13:
      answer[index] = 'D';
      break;

    case 14:
      answer[index] = 'E';
      break;

    case 15:
      answer[index] = 'F';
      break;

    default:
      // converting int to char by adding 48 in it to make it an ascii code
      // and also typecasting it into a char
      // For example, if 4 is the remainder, it will first convert 4 into its
      // ascii code 4 + 48 = 52, and then typecast 52 into a char, resulting in
      // character '4'
      answer[index] = (char)(remainder + 48);
      break;
    }

    index++;
    x = x / 16;
  }

  // Print answer in reverse order
  for (int i = index - 1; i >= 0; i--) {
    printf("%c", answer[i]);
  }
}

bool is_valid(int x) {
  if (x > INT_MAX) {
    printf("Number is too large");
    return false;
  }

  return true;
}
