 * TODO: properly update the tail pointer                                                                                                                
 * make code more efficient if tail pointer helps                                                                                                        
 */

void LinkedList::addTail(int v)
{
        // make a new link for the new item                                                                                                              
        Node *l = new Node();
        l->value = v;
        l->next = NULL;
        // if the list is empty, this is the only one                                                                                                    
        if (head == NULL)
        {
                head = l;
                tail = l;
        }
        // otherwise, we need to go to the back and add the node                                                                                         
        else
        {

                // advance l2 so it points to the last link                                                                                              
          /*I changed l2 to tail, because we're practically creating a new Node that's already been created in the class for us*/
                for(tail = head;tail->next != NULL; tail = tail->next)
                        ;
                // now add this l to the end by hooking l2 to it                                                                                         
                // Once again, I used tail instead of l2                                                                                                 
                tail->next = l;

        }
}

/* removeHead                                                                                                                                            
 * remove the first element in a linked list                                                                                                             
 * TODO: update tail pointer                                                                                                                             
 */

int LinkedList::removeHead()
{
        // if the list is empty, return 0                                                                                                                
        if (head == NULL)
                return 0;
        // set a temporary pointer to head                                                                                                               
        Node *tmp = head;
        // advance head so it points to the next one                                                                                                     
        head = head->next;
        // record the return value before deleting the Link                                                                                              
        int retval = tmp->value;
        // delete the Link                                                                                                                               
        delete tmp;
        for(tail = head; tail->next != NULL; tail = tail->next)
          ;
        // return the value                                                                                                                              
        return retval;
}

/* removeTail                                                                                                                                            
 * remove the last element of a linked list                                                                                                              
 * TODO: update tail pointer                                                                                                                             
 * make code more efficient if tail pointer helps                                                                                                        
 */
int LinkedList::removeTail()
{
        // if the list is empty, return 0                                                                                                                
        if (head == NULL)
                return 0;
        // if there is only one item, remove it                                                                                                          
        if (head->next == NULL)
        {
                // record the value to return                                                                                                            
                int retval = head->value;
                // delete the Link                                                                                                                       
                delete head;
                // set head to NULL, indicating an empty list                                                                                            
                head = NULL;
                // return the value from that Link                                                                                                       
                return retval;
        }
        // advance to the next to last link                                                                                                              

        for(tail = head;tail->next->next != NULL; tail = tail->next)
                ;

        // record the return value                                                                                                                       
        int retval = tail->next->value;
        // delete the Link                                                                                                                               
        delete tail->next;
        // set this node to be pointing to null, removing the Link                                                                                       
        tail->next = NULL;

        // return the value                                                                                                                              
        return retval;
}

/* removeTailRec                                                                                                                                         
 *                                                                                                                                                       
 * public method for recursive implementation                                                                                                            
 * TODO: fill in the code                                                                                                                                
 */
int LinkedList::removeTailRec()
{

        // first do the base cases that do not require recursion                                                                                         
  if(head == NULL)
    return 0;
  if(head->next == NULL)
  {
    int retval = head->value;
    delete head;
    head = NULL;
    return retval;
  }


}

/* removeTail(Node *)                                                                                                                                    
 * recursive implementation of removeTail                                                                                                                
 * TODO: fill in implementation                                                                                                                          
 */

int LinkedList::removeTailRec(Node *n)
{
  // check for the base case(s)                                                                                                                          
  n = head;
  if(n == NULL)
    return 0;
  if(n->next == NULL)
  {
    int retval = head->value;
    delete n;
    n = NULL;
    return retval;
  }
  removeTailRec(n->next);

        // else call the recursive method                                                                                                                
}

void LinkedList::printList(FILE *f)
{
        Node *l;
        fprintf(f,"Printing iteratively forwards: ");
        fprintf(f,"List: ");
        for(l = head; l != NULL; l = l->next)
        {
                fprintf(f, "%d, ",l->value);
        }
        fprintf(f,"\n");
}
/* addSorted                                                                                                                                             
 *                                                                                                                                                       
 * RECURSIVE public implementation of addSorted                                                                                                          
* TODO: Fill in implementation                                                                                                                           
*/
void LinkedList::addSortedRec(int v)
{
  Node *pNode = new Node();
  pNode->value = v;
  pNode->next = NULL;
        // base case(s) outside of recursive call                                                                                                        
  if(head == NULL)
  {
    head = pNode;
  }
  if(head->next == NULL)
  {
    if(pNode->value < head->value){
      pNode->next = head;
      head = pNode;
      for(tail = head; tail->next!=NULL;tail = tail->next)
        ;
    }
    else{
      pNode->next = head->next;
      head->next = pNode;
      for(tail = head;tail->next!=NULL;tail = tail->next)
        ;
    }
  }
  head = head->next;
  addSortedRec(pNode->value);
}


        // call recursive method                                                                                                                         




/* addSorted                                                                                                                                             
 *                                                                                                                                                       
 * RECURSIVE private implementation of addSorted                                                                                                         
*  TODO: fill in code                                                                                                                                    
*/
void LinkedList::addSortedRec(Node *n, int v)
{
  n->value = v;
  n->next = NULL;

  // base case(s) outside of recursive call                                                                                                              
  if(head == NULL)
    {
      head = n;
      tail = n;
    }
  //Smaller Case                                                                                                                                         
  else if(head->next == NULL)
    {
      if(n->value < head->value){
        n->next = head;
        head = n;
        tail = n->next;
      }
      else{
        head->next = n;
        tail = head->next;
      }
    }
  else{}

    }




