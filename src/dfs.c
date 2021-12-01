/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node *root)
{
  //Initializing stack to push the root of the tree onto
  stack *list = NULL;
  push(&list, root);

  /*
  Nodes from the tree will be popped, and pushed onto the stack
  until the tree is traversed.
  */
  while(!isEmpty(list))
  {
    stack *popped = pop(&list);
    printf("%d\n", popped->node->num);

    if(popped->node->rchild != NULL)
    {
      push(&list, popped->node->rchild);
    }

    if(popped->node->lchild != NULL)
    {
      push(&list, popped->node->lchild);
    }
  }
}

node *make_node (int num, node * left, node * right)
{
	node *new = malloc(sizeof(node));
  new->num = num;
  new->visited = false;
  new->lchild = left;
  new->rchild = right;
  return new;
}

void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
  {
    print_tree (p->rchild, depth + 1);
  }
}


void push(stack **topp, node * node)
{
  stack *new_element = malloc(sizeof(stack));
  
  new_element -> node = node;
  new_element -> next = NULL;

  stack *top = *topp;

  if (isEmpty(top))
  {
    *topp = new_element;
  }
  else
  {
    stack *temp = top;
    while(temp->next != NULL)
      temp = temp->next;
    temp->next = new_element;
  }
}

bool isEmpty (stack * topp)
{
  return(topp == NULL);
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack **topp)
{
  stack *top = *topp;
  stack *temp = top;
  if (temp -> next == NULL)
  {
    *topp = NULL;
    return temp;
  }
  else
  {
   stack *prev = top;
    while (temp->next != NULL)
    {
      prev = temp;
      temp = temp->next;
    }

    prev->next = NULL;
    return temp;
  }
}
	


void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");
}
