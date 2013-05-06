using namespace std;
#include <cstdio>
#include "Stack.h"

Stack::Stack()
{
  this->list = new IntLinkedList();
}
Stack::~Stack()
{
  this->list= NULL;
}
void Stack::push(int v)
{
  this->list->addHead(v);
}
bool Stack::isEmpty()
{
  return (this->list->removeHead()==0 || this->list->removeTail()==0);
}
int Stack::pop()
{
  if(this->isEmpty()){}
  else
  {
    this->list->removeHead();
  }
}
int Stack::peek()
{
  if(this->isEmpty()){}
  else
  {
    this->list->peekHead();
  }
}
void Stack::printStack(FILE *fp)
{
  this->list->printList(fp);
}
