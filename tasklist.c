
void addHead(tasklinkedlist *list,task *new_task)
{
  if(list->head == NULL)
  {
    list->head->theTask = new_task;
  }
  else
  {
    list->head->next->theTask = new_task;
  }
  list->head = list->head->next;
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
  int i;
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
      i++;
      printf("%d: %s, priority: %d.  Entered %s\n",i,current->theTask->task_name,current->theTask->priority,current->theTask->date_entered);
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
  node *previous = NULL;
  node *current = list->head;
  if(toDelete > listLength(list))
  {

  }
  else if(current !=NULL)
  {
    int i;
    for(i=0;i<toDelete;i++)
    {
      previous = current;
      current = current->next;
    }
    if(current != NULL)
    {
      if(previous == NULL)
      {
        list->head = current;
      }
      else
      {
        previous->next = current->next;
      }
    }
  }
}

/* addTasksFromFile                                                                                                                           
 * * * Reads each task line by line from the buffer and adds it to the tasklinkedlist                                                         
 * * */
                                                                                                                                             \

void addTasksFromFile(tasklinkedlist * mytasklinkedlist, FILE *fp)
{
       //insert code here                                                                                                                     
}



























