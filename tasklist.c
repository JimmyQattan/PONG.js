using namespace std;
#include <cstdio>
#include "Stack.h"

Stack::Stack()
{
  this->list->head = NULL;
}
Stack::~Stack()
{
  this->list->head = NULL;
}
void Stack::push(int v)
{
  IntNode *current = new IntNode(v);
  current->next = NULL;
  if(this->list->head == NULL){
    this->list->head->next = current;
  }
  else
  {
    current->next = this->list->head;
    this->list->head = current;
  }

}
bool Stack::isEmpty()
{
  return (this->list->head == NULL);
}
int Stack::pop()
{
  IntNode *current = new IntNode;
  IntNode *previous = new IntNode;
  current = this->list->head;
  if(this->isEmpty()){}
  else
  {
    while(current->next!=NULL)
    {
      previous = current;
      current = current->next;
    }
    while(this->list->head->next->next!=NULL)
    {
      this->list->head = this->list->head->next;
    }
    this->list->head->next = previous;
    return (current->value);
  }
}
int Stack::peek()
{
  IntNode *current = this->list->head;
  if(this->isEmpty()){}
  while(current->next!=NULL)
  {
    current = current->next;
  }
  return (current->value);
}
void Stack::printStack(FILE *fp)
{
  int i=0;
  IntNode *current = this->list->head;
  if(this->isEmpty())
    printf("No entries in the Stack\n");
  else
  {
    printf("The entires in the Stack are:\n");
    for(current;current!=NULL;current=current->next)
    {
      fprintf(stdout,"%i:",i);
      current->list->printList(stdout);
      fprintf(stdout,"\n");
      i++;
    }
  }
}


