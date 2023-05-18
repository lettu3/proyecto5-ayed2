#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
  stack_elem  elem;
  struct _s_stack * next;
};
/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
  stack output = NULL;
  return output;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){
  stack new = malloc(sizeof(struct _s_stack));
  new->elem = e;
  new->next = s;
  s = new;
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
  stack aux = s;
  s = s->next;
  free(aux);
  return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
  unsigned int size = 0u;
  stack aux = s;
  while (!stack_is_empty(aux)){
    aux = aux -> next;
    size = size + 1;
  }
  return size;
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
  assert(!stack_is_empty(s));
  stack_elem output = s->elem;
  return output;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s){
  bool res = (s == NULL);
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
  stack_elem * array = calloc(sizeof(struct _s_stack), size);

  for (int i = size - 1 ; 0 <= i; --i){
      array[i] = stack_top(s);
      s = stack_pop(s);
  }

  stack_destroy(s);

  return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s){
  stack aux = s;
  while(!stack_is_empty(s)){
    aux = s;
    s = s->next;
    free(aux);
  }
  return s;
}