/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>	/* bool, true, false */
#include "dfs.h"
#include <assert.h>

/* Recursive function */
void DFT (node * root) 
{
	/* If the current element is NULL, then there is nothing to print */
  if (root == NULL)
  {
    return;
  }

  print_node(root);   /* Prints the current element */
  DFT(root->lchild);  /* Moves to the left child and use DFT */
  DFT(root->rchild);  /* Moves to the right chide and use DFT */

  return;
}

node *make_node (int num, node * left, node * right)
{
	node *new = (node*)malloc(sizeof(node)); /* Allocating memeory to new node */
  
  /* Assigning data to the new node */
  new->num = num;
  new->lchild = left;
  new->rchild = right;
  new->visited = false;

  return new;
}

/* Not used */
void free_node (node * p)
{
    if (p == NULL)  /* If the node is empty, then there is nothing to free */
    {
      return;
    }
    
    /* Otherwise the children and root are freed */
    free_node(p->lchild);
    free_node(p->rchild);
    free(p);

  return;
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d, ", p->num);
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
    print_tree (p->rchild, depth + 1);
}

/* Not used */
stack *push (stack * topp, node * node)
{
	stack *new_top = (stack*)malloc(sizeof(stack)); /* Allocating memory to the new top stack */
  
  /* Assigning new values to the new top stack */
  new_top->node = node;
  new_top->next = topp;

  return new_top; /* Returning new top stack */
}

/* Not used */
bool isEmpty (stack * topp)
{
  if (topp = NULL)
  {
    return true;
  } 
  else 
  {
  return false;
  }
}

/* Not used */
node *top (stack * topp)
{
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
	assert(isEmpty(topp) == false); /* Precondtion: stack must not be empty */
  
  stack *temp = topp; /* Temporary stack pointing to the top stack */  
  topp = topp->next;  /* Assigning the top stack to become the sexond top stack */

  free(temp); /* Freeing the original top */

  return topp;
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

  return;
}
