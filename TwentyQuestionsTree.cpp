ing namespace std;
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include "TwentyQuestionsTree.h"

TwentyQuestionsTree::TwentyQuestionsTree(FILE *)
{

  char buf1[150];
  char *questions[5];
  TwentyQuestionsTree *tree = new TwentyQuestionsTree();
  while(fgets(buf1,150,stdout)!=NULL)
    {
      questions[0] = strtok(buf1,",\n");
      questions[1] = strtok(NULL,",\n");
      questions[2] = strtok(NULL,",\n");
      BinaryNode *r = new BinaryNode(tree->currentQuestion());
      tree->insert(r,questions[0],questions[1],questions[2]);

    }


}

TwentyQuestionsTree::TwentyQuestionsTree()
{
  root = new BinaryNode("Is it a platypus?");
}

/* insert                                                                                                                                                                                                                                                                                                                                                                                                                                               
 * This inserts two questions into the tree - the children of the parent.                                                                                                                                                                                                                                                                                                                                                                               
 * This is used when building the tree from scratch.                                                                                                                                                                                                                                                                                                                                                                                                    
 * The assumption is that the parent is already in the tree, and we are                                                                                                                                                                                                                                                                                                                                                                                 
 * merely adding the left and right children.                                                                                                                                                                                                                                                                                                                                                                                                           
 */
bool TwentyQuestionsTree::insert(BinaryNode *r,char *parent, char *left, char *right)
{

  if(r->question != parent)
    {
      return false;
    }
  else
    {
      BinaryNode *RNode = new BinaryNode(right);
      BinaryNode *LNode = new BinaryNode(left);
      r->left = LNode;
      r->right = RNode;
      return true;
    }
}

/* modifyAndInsert                                                                                                                                                                                                                                                                                                                                                                                                                                      
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                      
 * This modifies the tree as a result of the game being incorrect.  Either                                                                                                                                                                                                                                                                                                                                                                              
 * the left child or right child is already in the tree.  This method replaces                                                                                                                                                                                                                                                                                                                                                                          
 * that existing one with the new parent and creates new left and right                                                                                                                                                                                                                                                                                                                                                                                 
 * children.                                                                                                                                                                                                                                                                                                                                                                                                                                            
 */
bool TwentyQuestionsTree::modifyAndInsert(BinaryNode *n,char *parent, char *left, char *right)
{
  if(n->question == NULL)
    return false;
  else
    {
      n->question = parent;
      BinaryNode *RNode = new BinaryNode(right);
      BinaryNode *LNode = new BinaryNode(left);
      n->left = LNode;
      n->right = RNode;
      return true;
    }

}
void TwentyQuestionsTree::modifyAndInsert(char *parent, char *left, char *right)
{
  modifyAndInsert(root,parent,left,right);
}

/* reset                                                                                                                                                                                                                                                                                                                                                                                                                                                
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                      
 * This resets the iterator to the beginning of the game                                                                                                                                                                                                                                                                                                                                                                                                
 */
void TwentyQuestionsTree::reset()
{
  iterator = root;

}

/* currentQuestions                                                                                                                                                                                                                                                                                                                                                                                                                                     
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                      
 * This has been provided for you.  This looks at the current position of                                                                                                                                                                                                                                                                                                                                                                               
 * the iterator and returns the question stored in that BinaryNode.                                                                                                                                                                                                                                                                                                                                                                                     
 */
char *TwentyQuestionsTree::currentQuestion()
{
  if(iterator == NULL)
    return NULL;
  else
    return iterator->question;
}


/* recordAnswer                                                                                                                                                                                                                                                                                                                                                                                                                                         
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                      
 * This advances the iterator.  If the answer was yes (1), go right.  If                                                                                                                                                                                                                                                                                                                                                                                
 * no (0), go left.                                                                                                                                                                                                                                                                                                                                                                                                                                     
 */
void TwentyQuestionsTree::recordAnswer(int answer)
{
  if(answer == 0)
    iterator = iterator->left;
  else if(answer == 1)
    iterator = iterator->right;
  else
    return;

}

/* storeTree                                                                                                                                                                                                                                                                                                                                                                                                                                            
 *                                                                                                                                                                                                                                                                                                                                                                                                                                                      
 * This writes the tree out to the file in the same format as the                                                                                                                                                                                                                                                                                                                                                                                       
 * sample input file was.                                                                                                                                                                                                                                                                                                                                                                                                                               
 */
void TwentyQuestionsTree::storeTree(BinaryNode *n,FILE *fp)
{
  if(n == NULL)
    return;
  else if(n != NULL)
    {
      fprintf(fp,"%s,%s,%s\n",n->question,n->left->question,n->right->question);
      storeTree(n->left,fp);
      storeTree(n->right,fp);
    }
}
void TwentyQuestionsTree::storeTree(FILE *fp)
{
  storeTree(root, fp);
}


