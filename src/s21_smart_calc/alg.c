#include "alg.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25
#define COS 97
#define SIN 98
#define TAN 99
#define ACOS 100
#define ASIN 101
#define ATAN 102
#define SQRT 103
#define LN 104
#define LOG 105
#define UNARY_MINES 106
#define UNARY_PLAS 107

double begin(const char *str1, double X) {
  list_options *main_list;
  char buf[255];
  double back = 0;
  sprintf(buf, "%f", X);
  main_list = dijkstra_algorithm(str1, buf);
  if (main_list != NULL) {
    back = calculations(main_list);
    free_all_elements(main_list);
  } else {
    back = sqrt(-1);
  }
  return back;
}

double calculations(list_options *main_list) {
  main_list->actual = main_list->first;
  element *search_engine = main_list->actual;
  while (search_engine->next != search_engine->past) {
    if (search_engine->operat != 'n') {
      int rank = rank_determination(search_engine->operat);
      if ((rank == 6) || (rank == 5)) {
        unary_operations(main_list);
      } else {
        binary_operations(main_list);
      }
      search_engine = main_list->actual;
    } else {
      main_list->actual = search_engine->next;
      search_engine = main_list->actual;
    }
  }
  return search_engine->number;
}

void binary_operations(list_options *main_list) {
  element *prepast, *past, *this_is;
  this_is = main_list->actual;
  past = this_is->past;
  prepast = past->past;
  double number2 = past->number;
  double number1 = prepast->number;
  double result = 0;
  switch (this_is->operat) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 == 0) {
        result = sqrt(-1);
      } else {
        result = number1 / number2;
      }
      break;
    case '^':
      result = pow(number1, number2);
      break;
    case '%':
      result = (int)number1 % (int)number2;
      break;
    default:
      break;
  }
  remove_element(main_list);
  remove_element(main_list);
  this_is = main_list->actual;
  this_is->number = result;
}

void unary_operations(list_options *main_list) {
  element *past, *this_is;
  this_is = main_list->actual;
  past = this_is->past;
  double number = past->number;
  switch (this_is->operat) {
    case COS:
      number = cos(number);
      break;
    case SIN:
      number = sin(number);
      break;
    case TAN:
      number = tan(number);
      break;
    case ACOS:
      number = acos(number);
      break;
    case ASIN:
      number = asin(number);
      break;
    case ATAN:
      number = atan(number);
      break;
    case SQRT:
      number = sqrt(number);
      break;
    case LN:
      number = log(number);
      break;
    case LOG:
      number = log10(number);
      break;
    case UNARY_MINES:
      number = number * -1;
      break;
    case UNARY_PLAS:
      number = number * 1;
      break;
    default:
      printf("error3\n");
      break;
  }
  remove_element(main_list);
  this_is = main_list->actual;
  this_is->number = number;
}

list_options *dijkstra_algorithm(const char *str, const char *X) {
  char *main_str = NULL;
  list_options *main_list = NULL;
  main_str = string_stabilization(str, X);
  if (check_str_two(main_str)) {
    main_list = create_first_element();
    main_loop_dijkstra(main_str, main_list);
    free(main_str);
    element *buf;
    buf = main_list->first;
    main_list->actual = buf;
    remove_element(main_list);
    buf = main_list->last;
    main_list->actual = main_list->last;
  }
  return main_list;
}

void main_loop_dijkstra(char *main_str, list_options *main_list) {
  int i = 0;
  int last_el_stack = 0;
  operation_template stack[250] = {{0, 0}};
  stack[last_el_stack].oper = 'n';
  while (main_str[i] != '\0') {
    if (this_number_or_point(main_str[i])) {
      adding_number_to_list(main_str, &i, main_list);
    } else {
      if (stack[last_el_stack].oper == 'n') {
        stack[last_el_stack].oper = main_str[i];
        stack[last_el_stack].priority = rank_determination(main_str[i]);
      } else {
        if (main_str[i] == '(') {
          last_el_stack++;
          basic_add_to_stack(main_str[i], stack, last_el_stack);
        } else if (main_str[i] == ')') {
          close_bracket_handling(main_list, stack, &last_el_stack);
        } else {
          push_out_of_stack(main_list, stack, main_str, i, &last_el_stack);
        }
      }
      i++;
    }
  }
  cleaning_stack(main_list, stack, last_el_stack);
}

void close_bracket_handling(list_options *main_list, operation_template *stack,
                            int *last_el_stack) {
  if (stack[*last_el_stack].oper == '(') {
    stack[*last_el_stack].oper = 'n';
    stack[*last_el_stack].priority = -1;
    if (*last_el_stack != 0) (*last_el_stack)--;
  } else {
    while (stack[*last_el_stack].oper != '(') {
      add_al_and_nullify(main_list, stack, *last_el_stack);
      stack[*last_el_stack].oper = 'n';
      stack[*last_el_stack].priority = -1;
      if (*last_el_stack != 0) (*last_el_stack)--;
    }
    stack[*last_el_stack].oper = 'n';
    stack[*last_el_stack].priority = -1;
    if (*last_el_stack != 0) (*last_el_stack)--;
  }
  if ((stack[*last_el_stack].oper >= 'a') &&
      (stack[*last_el_stack].oper <= 'i')) {
    add_al_and_nullify(main_list, stack, *last_el_stack);
    if (*last_el_stack != 0) {
      (*last_el_stack)--;
    }
  }

  if ((stack[*last_el_stack].oper == UNARY_MINES) ||
      (stack[*last_el_stack].oper == UNARY_PLAS)) {
    add_al_and_nullify(main_list, stack, *last_el_stack);
    if (*last_el_stack != 0) (*last_el_stack)--;
  }
}

void push_out_of_stack(list_options *main_list, operation_template *stack,
                       char *main_str, int i, int *last_el_stack) {
  int main_rank, stack_rank;
  main_rank = rank_determination(main_str[i]);
  stack_rank = stack[*last_el_stack].priority;
  if (stack_rank >= main_rank) {
    while (stack_rank >= main_rank) {
      adding_element(main_list, stack[*last_el_stack].oper, 0);
      stack[*last_el_stack].oper = 'n';
      stack[*last_el_stack].priority = -1;
      if (*last_el_stack != 0) (*last_el_stack)--;
      stack_rank = stack[*last_el_stack].priority;
    }
    if (stack[*last_el_stack].oper != 'n') (*last_el_stack)++;
    basic_add_to_stack(main_str[i], stack, *last_el_stack);
  } else {
    (*last_el_stack)++;
    basic_add_to_stack(main_str[i], stack, *last_el_stack);
  }
}

void cleaning_stack(list_options *main_list, operation_template *stack,
                    int last_el_stack) {
  while ((last_el_stack > -1) && (stack[last_el_stack].oper != 'n')) {
    adding_element(main_list, stack[last_el_stack].oper, 0);
    stack[last_el_stack].oper = 'n';
    stack[last_el_stack].priority = -1;
    last_el_stack--;
  }
}

void basic_add_to_stack(char c, operation_template *stack, int last_el_stack) {
  stack[last_el_stack].oper = c;
  stack[last_el_stack].priority = rank_determination(c);
}

void add_al_and_nullify(list_options *main_list, operation_template *stack,
                        int last_el_stack) {
  adding_element(main_list, stack[last_el_stack].oper, 0);
  stack[last_el_stack].oper = 'n';
  stack[last_el_stack].priority = -1;
}

int rank_determination(char c) {
  int back = 0;
  if ((c >= 'a') && (c <= 'i')) {
    back = 6;
  } else if ((c == 'j') || (c == 'k')) {
    back = 5;
  } else if ((c == '+') || (c == '-')) {
    back = 2;
  } else if ((c == '*') || (c == '/')) {
    back = 3;
  } else if ((c == '^') || (c == '%')) {
    back = 4;
  } else if (c == '(') {
    back = 0;
  } else if (c == ')') {
    back = 1;
  }
  return back;
}

void adding_number_to_list(char *main_str, int *i, list_options *main_list) {
  double value = 0;
  int factor = 0, fl_point = 0;
  while ((this_number_or_point(main_str[*i])) && (main_str[*i] != '\0')) {
    if (main_str[*i] == '.') {
      fl_point = 1;
      factor = 1;
    } else {
      if (fl_point == 0) {
        value = (main_str[*i] - 48) + value * 10;
        factor++;
      } else {
        value += (main_str[*i] - 48) * pow(10, -factor);
        factor++;
      }
    }
    (*i)++;
  }
  adding_element(main_list, 'n', value);
}

int this_number_or_point(char c) {
  int back = 0;
  if (((c >= '0') && (c <= '9')) || (c == '.')) back = 1;
  return back;
}

int check_str_two(char *str1) {
  int size = strlen(str1), back = 1;
  char str_operators[] = {".+-*/%^("};
  int i = size - 1;
  while ((str1[i] == ')') && (i >= 0)) {
    i--;
  }
  if (strchr(str_operators, str1[i]) != NULL) back = 0;
  return back;
}

char *string_stabilization(const char *str1, const char *X) {
  char *str_term = NULL;
  int size_str_term = SIZE;
  int j = 0;
  if ((str_term = (char *)malloc(size_str_term * sizeof(char))) == NULL) {
    printf("no memory\n");
  } else {
    char str_operators[] = {"0123456789.+-*/%^()"};
    for (int i = 0; str1[i] != '\0'; ++i) {
      if (j == size_str_term - 10) {
        size_str_term += SIZE;
        if ((str_term = (char *)realloc(
                 str_term, size_str_term * sizeof(char))) == NULL) {
          printf("no memory");
          break;
        }
      }
      if (str1[i] != 'X') {
        if (strchr(str_operators, str1[i])) {
          definition_of_unary_operations(str1, str_term, i, j);
          j++;
        } else if (str1[i] == ' ') {
          continue;
        } else {
          if (finding_a_subfunction(subfunction_reading(str1, &i), str_term, j))
            j++;
          else
            break;
        }
      } else {
        for (int k = 0; X[k] != '\0'; ++k) {
          if (X[k] != '-') {
            str_term[j] = X[k];
          } else {
            str_term[j] = UNARY_MINES;
          }
          str_term[j + 1] = '\0';
          j++;
        }
      }
    }
  }
  return str_term;
}

void definition_of_unary_operations(const char *str1, char *str_term, int i,
                                    int j) {
  if (((str1[i] == '-') || (str1[i] == '+')) &&
      ((i == 0) || !((str_term[j - 1] >= '0') && (str_term[j - 1] <= '9'))) &&
      (str_term[j - 1] != ')')) {
    switch (str1[i]) {
      case '-':
        str_term[j] = UNARY_MINES;
        str_term[j + 1] = '\0';
        break;
      case '+':
        str_term[j] = UNARY_PLAS;
        str_term[j + 1] = '\0';
        break;
    }
  } else {
    str_term[j] = str1[i];
    str_term[j + 1] = '\0';
  }
}

char *subfunction_reading(const char *str1, int *i) {
  char *func;
  int k = 0;
  func = (char *)malloc(10 * sizeof(char));
  while (str1[*i] != '(') {
    func[k] = str1[*i];
    func[k + 1] = '\0';
    k++;
    (*i)++;
    if (k == 5) {
      printf("%s\n", func);
      printf("error1\n");
      break;
    }
  }
  (*i)--;
  return func;
}

int finding_a_subfunction(char *func, char *str_term, int j) {
  char all_func[] = {"cossintanacosasinatansqrtlnlog"};
  char *place = NULL;
  if ((place = strstr(all_func, func)) != NULL) {
    switch (place - all_func) {
      case 0:
        str_term[j] = COS;
        str_term[j + 1] = '\0';
        break;
      case 3:
        str_term[j] = SIN;
        str_term[j + 1] = '\0';
        break;
      case 6:
        str_term[j] = TAN;
        str_term[j + 1] = '\0';
        break;
      case 9:
        str_term[j] = ACOS;
        str_term[j + 1] = '\0';
        break;
      case 13:
        str_term[j] = ASIN;
        str_term[j + 1] = '\0';
        break;
      case 17:
        str_term[j] = ATAN;
        str_term[j + 1] = '\0';
        break;
      case 21:
        str_term[j] = SQRT;
        str_term[j + 1] = '\0';
        break;
      case 25:
        str_term[j] = LN;
        str_term[j + 1] = '\0';
        break;
      case 27:
        str_term[j] = LOG;
        str_term[j + 1] = '\0';
        break;
      default:
        place = NULL;
        printf("error2\n");
        break;
    }
  }
  free(func);
  return (place != NULL) ? 1 : 0;
}

void remove_element(list_options *list) {
  element *element_to_be_removed;
  element *buffer;
  element_to_be_removed = list->actual;
  if (list->actual == list->last) {
    list->actual = list->last = element_to_be_removed->past;
    free(element_to_be_removed);
    buffer = list->last;
    buffer->next = NULL;
  } else if (list->actual == list->first) {
    list->actual = list->first = element_to_be_removed->next;
    free(element_to_be_removed);
    buffer = list->first;
    buffer->past = NULL;
  } else {
    element *new_past, *new_next;
    new_past = element_to_be_removed->past;
    new_next = element_to_be_removed->next;
    new_past->next = new_next;
    new_next->past = new_past;
    list->actual = new_past;
    free(element_to_be_removed);
  }
}

void adding_element(list_options *list, int operr, double value) {
  element *tmp;
  element *buffer;
  if ((tmp = (element *)malloc(sizeof(element))) == NULL) {
    printf("no memory\n");
  } else {
    buffer = list->last;
    tmp->operat = operr;
    tmp->number = value;
    tmp->past = buffer;
    tmp->next = NULL;
    buffer->next = tmp;
    list->last = list->actual = tmp;
  }
}

list_options *create_first_element() {
  element *tmp;
  list_options *list;
  if ((tmp = (element *)malloc(sizeof(element))) == NULL) {
    printf("no memory\n");
    list = NULL;
  } else {
    tmp->number = 0;
    tmp->operat = 0;
    tmp->past = NULL;
    tmp->next = NULL;
    if ((list = (list_options *)malloc(sizeof(list_options))) == NULL) {
      printf("no memory\n");
    } else {
      list->actual = list->first = list->last = tmp;
    }
  }
  return list;
}

void free_all_elements(list_options *list) {
  element *tmp, *past = NULL;
  tmp = list->last;
  while (tmp) {
    past = tmp->past;
    free(tmp);
    tmp = past;
  }
  free(list);
}

void output_all_elements(list_options *list) {
  element *buffer;
  buffer = list->first;
  while (buffer != NULL) {
    output_element(buffer);
    buffer = buffer->next;
  }
}

void output_element(element *tmp) {
  printf("%c %f ", tmp->operat, tmp->number);
  printf("%p %p\n", tmp->past, tmp->next);
}

void output_list(list_options *main_list) {
  printf("%p\n", main_list->actual);
  printf("%p\n", main_list->first);
  printf("%p\n", main_list->last);
  printf("\n");
}
