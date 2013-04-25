#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tasklinkedlist.h"


/* makeTask                                                                                         
 *  *                                                                                               
 *   * This function takes the parameters with the information for a task.                          
 *    * These parameters are stored in **temporary** strings.  Your job is                          
 *     * to create a new task and fill in the fields properly.  Return this                         
 *      * new task.  Make sure you think carefully about what malloc call(s)                        
 *       * you need to make.                                                                        
 *        */

task *makeTask(char *name,char *date,char *priority)
{
  int i;
  task *t = (struct _task*)malloc(sizeof(struct _task));
  t->priority = atoi(priority);

  //allocate memory for the struct                                                                  
  t->task_name = (char *)malloc(sizeof(char)*(strlen(name)+1));

  //set value for the struct pieces                                                                 
  for(i=0;i<strlen(name)-1;i++){
    t->task_name[i]=name[i];
    if(t->task_name[i]=='\n'){
      t->task_name[i]='\0';
    }
  }


  for(i=0;i<=strlen(date)-1;i++){
    t->date_entered[i]=date[i];
    if(t->date_entered[i]=='\n'){
      t->date_entered[i]='\0';
    }
  }
  return t; // FILL THIS IN                                                                         

}


/* createAndInitialize                                                                              
 * *                                                                                                
 * * This function allocates space for a task list and initializes the task list                    
 * * to an initial state. Additionally, it returns the newly created task list                      
 * * structure to the caller.                                                                       
 * *                                                                                                
 * * Initializing the task list involves assigning values to each of the attributes                 
 * * of the 'tasklinkedlist' structure.                                                             
 * */

tasklinkedlist *createAndInitialize()
{
  tasklinkedlist *pTaskLinkedList = (struct _tasklinkedlist*)malloc(sizeof(struct _tasklinkedlist))\
;
  //node *pNode = (struct _node*)malloc(sizeof(struct _node));                                      
  pTaskLinkedList->head = NULL;
  //pNode->theTask = NULL;                                                                          
  //pNode->next = NULL;                                                                             
  return pTaskLinkedList;
}



/* addHead                                                                                          
 * *                                                                                                
 * * This function takes two parameters - the task list and the task to be inserted.                
 * * It attempts to add the said task to the head of the tasklinkedlist.                            
 * *                                                                                                
 * * NOTE:                                                                                          
 * * Two possible cases to consider :                                                               
 * * 1 - when the list is empty                                                                     
 * * 2 - when the list is non-empty                                                                 
 * */

void addHead(tasklinkedlist *list,task *new_task)
{
  node *pNode = (struct _node*)malloc(sizeof(struct _node));
  pNode->theTask = new_task;
  pNode->next = NULL;
  if(list->head == NULL)
  {
    list->head = pNode;
  }
  else
  {
    pNode->next = list->head;
    list->head = pNode;
  }

}

/* listLength                                                                                       
 * *                                                                                                
 * * This function takes as input the task list and returns the number of tasks/nodes in the list.  
 * */
int listLength(tasklinkedlist *list)
{
  int count = 0;
  node *current;
  for(current=list->head;current!=NULL;current=current->next)
  {
    count++;
  }
  return count;
}

/* printTaskList                                                                                    
 * *                                                                                                
 * * This function takes as input the task list and prints the contents of the list on the screen.  
 * */

void printTaskList(tasklinkedlist *list)
{
        //insert code here                                                                          
       //make sure your printf is of the format as below                                            
       // if no entries :                                                                           
  int i=0;
  node *current = list->head;
  if(current == NULL)
  {
    printf("No entries in the tasklinkedlist\n");
  }
  else
  {
    printf("The entries in the Task List are:\n");
    for(current;current!=NULL;current=current->next)
    {
      printf("%d: %s, priority: %d.  Entered %s\n",i,current->theTask->task_name,current->theTask->\
priority,current->theTask->date_entered);
      i++;
    }
  }
       //printf("No entries in the tasklinkedlist\n");                                              
       // else there are entries :                                                                  
       //  printf("The entries in the Task List are:\n");                                           
       // followed by details about every entry of the format                                       
       // printf("%d: %s, priority: %d.  Entered %s\n",A,B,C,D); //replace A,B,C,D accordingly      
       //A is position in the list (starting with 0), B is the task name,                           
       //C is the priority, and D is the date.                                                      

}

/* deleteItem                                                                                       
 * *                                                                                                
 * * This function takes two parameters - the task list and the index of the task to be deleted     
 * * The method traversed through the list to find the task at the given index                      
 * * If match is found, re-adjust the pointers, so that the node/task is deleted                    
 * * Adjust head pointer if necessary                                                               
 * *                                                                                                
 * */
void deleteItem(tasklinkedlist *list,int toDelete)
{
  node *previous = (struct _node*)malloc(sizeof(struct _node));
  previous = NULL;
  node *current = list->head;
  if(toDelete > listLength(list) || toDelete < 0)
  {

  }
  else if(current !=NULL)
  {
    int i;
    for(i=0;i<toDelete-1;i++)
    {

      previous = current;
      current = current->next;
    }
   if(current == list->head)
   {
     list->head = current->next;
     current = NULL;
   }
   else
   {
     previous->next = current->next;
     current=NULL;
   }
  }
}



/* addTasksFromFile                                                                                 
 * * * Reads each task line by line from the buffer and adds it to the tasklinkedlist               
 * * */

void addTasksFromFile(tasklinkedlist * mytasklinkedlist, FILE *fp)
{
  
  char *t, *p, *d;
  task *t1 = (struct _task*)malloc(sizeof(struct _task));
  fscanf(fp,"%s,%s,%s\n",t,p,d);
  t1 = makeTask(t,p,d);
  addHead(mytasklinkedlist,t1);
      
}



