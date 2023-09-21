#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of  stack (or queue)
 * @n: int
 * @prev: this points to the previous element of stack (or queue)
 * @next: this points to the next element of stack (or queue)
 *
 * Description: the doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - the opcode and its function
 * @opcode: this is the opcode
 * @f: this is the function to handle the opcode
 *
 * Description: this is the opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Stack operation*/
stack_t *create_node(int n);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);

/*file operation*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
void read_file(FILE *);

/*String operation*/
void print_char(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);

/*Math operation with nodes*/
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*Error handling*/
void err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);
void more_err(int error_code, ...);

#endif
