#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasklist.h"



/* makeTask                                                                                               
 *                                                                                                        
 * This function takes the parameters with the information for a task.                                    
 * These parameters are stored in **temporary** strings.  Your job is                                     
 * to create a new task and fill in the fields properly.  Return this                                     
 * new task.  Make sure you think carefully about what malloc call(s)                                     
 * you need to make.                                                                                      
 */

task *makeTask(char *name, char *date, char *priority)
{
  int i;
  task *t = (struct _task*)malloc(sizeof(struct _task));
  t->priority = atoi(priority);

  //allocate memory for the struct                                                                        
  t->task_name = (char *)malloc(strlen(name)*sizeof(char)+1);

  //set value for the struct pieces                                                                       
  for(i=0;i<strlen(name)-1;i++)
    t->task_name[i]=name[i];


  for(i=0;i<strlen(date)-1;i++)
    t->date_entered[i]=date[i];
   return t; // FILL THIS IN                                                                              
}

/* createAndInitialize                                                                                    
 *                                                                                                        
 * This function allocates space for a task list and initializes the task list                            
 * to an initial state. Additionally, it returns the newly created task list                              
 * structure to the caller.                                                                               
 *                                                                                                        
 * Initializing the task list involves assigning values to each of the attributes                         
 * of the 'tasklist' structure. You would also have to allocate ,memory for the task                      
 * array.                                                                                                 
 */

tasklist *createAndInitialize()
{
  tasklist *pTaskList = (struct _tasklist*)malloc(sizeof(struct _tasklist));
  pTaskList->array_size=10;
  pTaskList->task_array = (struct _task**)malloc(sizeof(struct _task*)*pTaskList->array_size);
  pTaskList->occupied_count = 0;

  return pTaskList;
}


/* addTaskToEnd                                                                                           
 *                                                                                                        
 * This function takes two parameters - the task list and the task to be inserted.                        
 * It attempts to append said task into an array of tasks maintained by the task                          
 * list. When the array reaches its capacity, the function proceeds to re-allocate the                    
 * array before carrying out the insertion operation.                                                     
 *                                                                                                        
 * NOTE:                                                                                                  
 * The use of realloc() is NOT permitted in this exercise. You would have to figure out                   
 * a way to perform the re-allocation using other memory allocation operations                            
 *                                                                                                        
 * HINT: Think malloc() and memcpy()!                                                                     
 */

void addTaskToEnd(tasklist *list,task *input_task)
{
  if(list->occupied_count < list->array_size)
  {
    list->task_array[list->occupied_count]=input_task;
    list->occupied_count++;
  }
  else
  {
    tasklist *pTaskList = (struct _tasklist*)malloc(sizeof(struct _tasklist)*list->occupied_count+1);
    memcpy(pTaskList,list,sizeof(struct _tasklist*)*list->occupied_count+1);
    pTaskList = list;
    pTaskList->task_array[pTaskList->occupied_count]=input_task;
    pTaskList->occupied_count++;

  }
}


/* removeTask                                                                                             
 *                                                                                                        
 * This function takes two parameters - the task list and the index value associated with                 
 * the task to be removed.                                                                                
 *                                                                                                        
 * The task to be removed can occur anywhere in the task array. You are required to write                 
 * code that handles all possible cases.                                                                  
 */


task *removeTask(tasklist *list, int task_index)
{
    int count = list->occupied_count;
    int j;
    if(task_index <= count)
    {
      for(j = task_index; j != count-1;j++)
        list->task_array[j] = list->task_array[j+1];

      list->occupied_count = list->occupied_count - 1;
    }
    else
        return NULL;
    return list->task_array[task_index];
}


/* printTaskList                                                                                          
 *                                                                                                        
 * This function takes as input the task list and prints the contents of the list on the screen.          
 */

void printTaskList(tasklist *list)
{
  int i = 0;

  if (list == NULL)
    printf("List is NULL\n");

  printf("\n The number of occupied entries in the Task List is : %d",
         list->occupied_count);
    printf("\n The entries in the Task List are:\n");
    for (i = 0;i < list->occupied_count; i++)
    {
        if (list->task_array[i] == NULL)
            printf("NULL\n");
        else
            printf("%d: %s, priority: %d.  Entered %s\n ", i,
                list->task_array[i]->task_name,
                list->task_array[i]->priority,
                list->task_array[i]->date_entered);
    }
}









