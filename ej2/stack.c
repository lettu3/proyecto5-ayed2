#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
    stack output = malloc(sizeof(struct _s_stack));
    output->elems = malloc(sizeof(stack_elem));
    output->size = 0u;
    output->capacity = 1u;
    return output;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'elem' at the top
*/
stack stack_push(stack s, stack_elem e){
    if (s->size == s->capacity){    //si el tamano de mi arreglo esta en su capacidad maxima
        s->capacity = (s->capacity) * 2;    //duplico la capacidad
        s->elems = realloc(s->elems, sizeof(stack_elem) * s->capacity); //realojo el arreglo en un nuevo bloque de memoria con la nueva capacidad
        s->size = (s->size) + 1;        //aumento el tamano
        (s->elems)[(s->size) - 1] = e;  //agrego el elemento
    }
    else{
        s->size = (s->size) + 1;
        (s->elems)[(s->size) - 1] = e;
    }

    return s;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s){
    assert((!stack_is_empty(s)) && s != NULL);
    s->size = (s->size) - 1;
    return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
    unsigned int stack_size = s->size;
    return stack_size; 
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
    assert((!stack_is_empty(s)) && s != NULL);
    stack_elem output = (s->elems)[(s->size) - 1];
    return output;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s){
    bool res = (s->size == 0);
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
    unsigned int array_size = stack_size(s);
    stack_elem * array = calloc(sizeof(stack_elem), array_size);
    for(int i = array_size-1; i >= 0; --i){
        array[i] = (s->elems)[i];
    }
    return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s){
    free (s->elems);
    free(s);
    return s;
}
