typedef struct {
  char oper;
  int priority;
} operation_template;

typedef struct _element {
  double number;
  char operat;
  struct _element *past;
  struct _element *next;
} element;

typedef struct {
  element *actual;
  element *first;
  element *last;
} list_options;

list_options *create_first_element();
void free_all_elements(list_options *list);
void adding_element(list_options *list, int operr, double value);
void remove_element(list_options *list);

void output_list(list_options *main_list);
void output_element(element *tmp);
void output_all_elements(list_options *list);

int finding_a_subfunction(char *func, char *str_term, int j);
char *subfunction_reading(const char *str1, int *i);
char *string_stabilization(const char *str1, const char *X);
void definition_of_unary_operations(const char *str1, char *str_term, int i,
                                    int j);
int this_number_or_point(char c);

list_options *dijkstra_algorithm(const char *str, const char *X);
void main_loop_dijkstra(char *main_str, list_options *main_list);
void close_bracket_handling(list_options *main_list, operation_template *stack,
                            int *last_el_stack);
void push_out_of_stack(list_options *main_list, operation_template *stack,
                       char *main_str, int i, int *last_el_stack);
void cleaning_stack(list_options *main_list, operation_template *stack,
                    int last_el_stack);
void basic_add_to_stack(char c, operation_template *stack, int last_el_stack);
void add_al_and_nullify(list_options *main_list, operation_template *stack,
                        int last_el_stack);
int rank_determination(char c);
void adding_number_to_list(char *main_str, int *i, list_options *list);

double calculations(list_options *main_list);
void unary_operations(list_options *main_list);
void binary_operations(list_options *main_list);

double begin(const char *str1, double X);
double are_you_a_cockerel(const char *str);
int check_str(char *main_str);
int check_str_two(char *str1);
