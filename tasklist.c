void TaskLinkedList::addTasksFromFile(FILE *fp)
{
  char buf[50];
  char *items[5];
  int i = 0;
  Task *t1;
  while(fgets(buf,50,fp)!=NULL)
  {
    items[0] = strtok(buf,",\n");
    items[1] = strtok(NULL,",\n");
    items[2] = strtok(NULL,",\n");
    t1 = new Task(items[0],items[2],items[1]);
    this->addSorted(t1);
  }
}
void TaskLinkedList::addSorted(Task *f)
{
  Node *dummy = new Node();
   Node *current = new Node();
  current = this->head;
  dummy->theTask = f;
  int comp = f->compare(current->theTask);
  while(current->next!=NULL){
  if(comp < 0)
    this->addHead(f);
  else if(comp == 0)
  {
    dummy = current->next;
    current->next = dummy;
  }
  else
    current = current->next;
  }
}
__________________________________________________________________________
//Task.CPP
int Task::compare(Task *g)
{
  Task *newT = g;
  int date, date2;
  if(newT->priority < (this->priority))
    return -1;
  else if(newT->priority == (this->priority))
    return 0;
  else
    return 1;

}
________________________________________________________________________
//TaskApp.cpp
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "TaskLinkedList.h"




int main(int argc, char *argv[])
{
                //File open error                                               
  //    printf("ERROR: Could not open file %s\n");                              
  char buf1[50], buf2[100], buf3[100], buf4[50], buf5[50], buf6[50], buf7[50];
  int p=1,q=0, i, toDelete, length;
  TaskLinkedList *list = new TaskLinkedList();
  Task *pTask = new Task;
  FILE *fp;
  while(!q)
  {
    printf("0) Exit\n1) List Tasks\n2) Add Task\n");                           \

    printf("3) Delete Task\n4) Add Task From File\n");                         \

    printf("What would you like to do?\n");
    fgets(buf1, 50, stdin);                                                    \

    p = atoi(buf1);
      switch(p)
      {
          case 0:
            q=1;
            break;
          case 1:
            list->printList(fp);
            break;
          case 2:
            printf("Enter task name: ");
            fgets(buf2,100,stdin);
            printf("Enter task priority: ");
            fgets(buf3,100,stdin);
            printf("Enter task start date: ");
            fgets(buf4,50,stdin);
            pTask = new Task(buf2,buf4,buf3);
            list->addSorted(pTask);
            break;
          case 3:
            list->printList(fp);
            printf("Enter the index of the task to be deleted? ");
            fgets(buf6,50,stdin);
            toDelete = atoi(buf6);
            list->deleteItem(toDelete);
            break;
            //case 4:                                                           
            //length = list->listLength();                                      
            //printf("Length of the list : %i\n", length);                      
            //break;                                                            
          case 4:
            printf("Enter the filename ");
            fgets(buf7,50,stdin);
            i = strlen(buf7);
            if((buf7[i-1])=='\n'){buf7[i-1]='\0';}
            fp = fopen(buf7,"r");
            if(fp==NULL){printf("ERROR: Could not open file %s\n",buf7);}
            else{list->addTasksFromFile(fp);}
              break;
          default:
            printf("ERROR: %d: Incorrect menu option\n", p);
            }
      }
}
