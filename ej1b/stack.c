#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct _s_stack{
  unsigned int size;
  struct node * first;
};

struct node{
    stack_elem elem;
    struct node * next;
};

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
    stack output = malloc(sizeof(struct _s_stack)); 
    output->first = NULL;
    output->size = 0;
    return output;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){
    struct node * new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = s->first;
    s->first = new;
    s->size = (s->size) + 1u;

    return s;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    struct node * aux = s->first; //creo un nodo auxiliar
    s->first = (s->first)->next;    // mi stack ahora apunta al segundo elemento;
    s->size = (s->size) -1u;        // resto el tamano
    free(aux);                      //libero al primer nodo
    return s;

}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
    unsigned int size_stack = s->size;
    return size_stack;
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    stack_elem output = (s->first)->elem;
    return output;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s){
    bool res = (s->size == 0u) && (s->first == NULL);
    return res;
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s){
    unsigned int size = stack_size(s);
    stack_elem * array = calloc(sizeof(stack_elem), size);
    for (int i = size -1; i >= 0; --i){
        array[i] = stack_top(s);
        s = stack_pop(s);
    }

    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s){
    while (!stack_is_empty(s)){
        s = stack_pop(s);
    }
    free(s);
    return s;
}
