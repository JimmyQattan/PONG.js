#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "LinkedList.h"

LinkedList::LinkedList()
{
        head = NULL;
        tail = NULL;
        // TODO: initialize tail                                                                                                                         
}

/* copy constructor                                                                                                                                      
 * TODO:  Copy the entire linked list for a DEEP COPY                                                                                                    
 */

LinkedList::LinkedList(LinkedList &oldlist)
{
  Node *nHead = new Node();
  Node *nTail = new Node();
  nHead = oldlist.head;
  for(nTail = nHead; nTail->next !=NULL; nTail = nTail->next)
    ;


}

/* destructor                                                                                                                                            
 *                                                                                                                                                       
 * TODO: delete all of the nodes in the linked list                                                                                                      
 */
LinkedList::~LinkedList()
{
      head = NULL;
      tail = NULL;
}


/* addHead                                                                                                                                               
 * add an item to the front of the linked list                                                                                                           
 * TODO: properly update the tail pointer                                                                                                                
 */

void LinkedList::addHead(int v)
{
        // create a new Link and put v into that Link                                                                                                    
        Node *l = new Node();
        l->value = v;
        // if the list is empty, this link is the only thing in it                                                                                       
        // all we need to do is point head to the link                                                                                                   
        if (head == NULL)
        {
                head = l;
                tail = l;
                head->next = NULL;
                tail->next = NULL;
        }
        // if there is already something there, we point this new link                                                                                   
        // to the old head of the list.  Then, when we point head to this                                                                                
        // Link, it becomes the beginning of the list, and the old beginning                                                                             
        // is now 2nd.                                                                                                                                   
        else
        {

                l->next = head;
                head = l;
                tail = l;
                while(tail->next!=NULL)
                  {
                    //Big-O(n)                                                                                                                           
                    tail = tail->next;

                  }

        }
}

/* addTail                                                                                                                                               
 * add an element to the end of the linked list                                                                                                          
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
  else
    return removeTailRec(head);



}

/* removeTail(Node *)                                                                                                                                    
 * recursive implementation of removeTail                                                                                                                
 * TODO: fill in implementation                                                                                                                          
 */

int LinkedList::removeTailRec(Node *n)
{
  // check for the base case(s)                                                                                                                          
  if(n == NULL)
    return 0;
  if(n->next == NULL)
  {
    int retval = n->value;
    n          = NULL;
    return retval;
  }
  if(n->next->next == NULL)
  {
    int retval = n->next->value;
    n->next    = NULL;
    return retval;
  }
  else
    return removeTailRec(n->next);

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
  // base case(s) outside of recursive call                                                                                                              
  if(head == NULL)
    return;
  else
    addSortedRec(head, v);
}


        // call recursive method                                                                                                                         




/* addSorted                                                                                                                                             
 *                                                                                                                                                       
 * RECURSIVE private implementation of addSorted                                                                                                         
*  TODO: fill in code                                                                                                                                    
*/
void LinkedList::addSortedRec(Node *n, int v)
{



  // base case(s) outside of recursive call                                                                                                              
  if(head == NULL)
    {
      n->value = v;
      head = n;
    }
  //Smaller Case                                                                                                                                         
  if(head->next == NULL)
  {
    n->value = v;
    if(v < head->value)
    {
      n->next = head;
      head = n;
    }
    else
    {
      head->next = n;
    }
  }
  else
    addSortedRec(n->next, v);
}



























