using namespace std;
#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include "TwentyQuestionsTree.h"

TwentyQuestionsTree::TwentyQuestionsTree(FILE *fp)
{

    char buf1[512];
    char *questions[6];
    int i = 0;
    while(fgets(buf1,512,fp))
      {
        questions[0] = strtok(buf1,",\n");
        questions[1] = strtok(NULL,",\n");
        questions[2] = strtok(NULL,",\n");
        if(root == NULL)
        {
            root = new BinaryNode(questions[0]);
            root->left = new BinaryNode(questions[1]);
            root->right = new BinaryNode(questions[2]);
        }
        else
          insert(root,questions[0],questions[1],questions[2]);
      }

}


TwentyQuestionsTree::TwentyQuestionsTree()
{
  root = new BinaryNode("Is it a platypus?");
}

bool TwentyQuestionsTree::insert(BinaryNode *r,char *parent, char *left, char *right)
{
  if(r == NULL)
  {
    r = new BinaryNode(parent);
    r->left = new BinaryNode(left);
    r->right = new BinaryNode(right);
    return true;
  }
  else if(!r->left && !r->right)
  {
      r->question = parent;
      r->left = new BinaryNode(left);
      r->right = new BinaryNode(right);
      return true;
  }
  else if(r->question == parent)
  {
    r->left = new BinaryNode(left);
    r->right = new BinaryNode(right);
    return true;
  }
  else
  {
    if(r->left != NULL)                                                                          
        if(insert(r->left,parent,left,right)) return true;
    if(r->right != NULL)                                                                     
        if(insert(r->right,parent,left,right)) return true;
     return false;
  }
}
void TwentyQuestionsTree::insert(char* parent, char* left, char* right)
{
  insert(root,parent,left,right);
}
/* modifyAndInsert                                                                                 \
                                                                                                    
 *                                                                                                 \
                                                                                                    
 * This modifies the tree as a result of the game being incorrect.  Either                         \
                                                                                                    
 * the left child or right child is already in the tree.  This method replaces                     \
                                                                                                    
 * that existing one with the new parent and creates new left and right                            \
                                                                                                    
 * children.                                                                                       \
                                                                                                    
 */
bool TwentyQuestionsTree::modifyAndInsert(BinaryNode *n,char *parent, char *left, char *right)
{

  if(n->question == left || n->question == right)
    {
      n->question = parent;
      n->left = new BinaryNode(left);
      n->right = new BinaryNode(right);
      return true;
    }
  else
    {
      if(n->left!=NULL)
        if(modifyAndInsert(n->left,parent,left,right))return true;
      if(n->right!=NULL)
        if(modifyAndInsert(n->right,parent,left,right))return true;
      return false;
    }
}
void TwentyQuestionsTree::modifyAndInsert(char *parent, char *left, char *right)
{
  modifyAndInsert(root,parent,left,right);
}

/* reset                                                                                           \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 *                                                                                                 \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * This resets the iterator to the beginning of the game                                           \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 */
void TwentyQuestionsTree::reset()
{
  iterator = root;

}

/* currentQuestions                                                                                \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 *                                                                                                 \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * This has been provided for you.  This looks at the current position of                          \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * the iterator and returns the question stored in that BinaryNode.                                \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 */
char *TwentyQuestionsTree::currentQuestion()
{
  if(iterator == NULL)
    return NULL;
  else
    return iterator->question;
}


/* recordAnswer                                                                                    \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 *                                                                                                 \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * This advances the iterator.  If the answer was yes (1), go right.  If                           \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
* no (0), go left.                                                                                 \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
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

/* storeTree                                                                                       \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 *                                                                                                 \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * This writes the tree out to the file in the same format as the                                  \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 * sample input file was.                                                                          \
                                                                                                   \
                                                                                                   \
                                                                                                   \
                                                                                                    
 */
void TwentyQuestionsTree::storeTree(BinaryNode *n,FILE *fp)
{
  if(n == NULL)
    return;
  else if(n != NULL)
    {
      storeTree(n->left,fp);
      fprintf(fp,"%s,%s,%s\n",n->question,n->left->question,n->right->question);
      storeTree(n->right,fp);
    }
}
void TwentyQuestionsTree::storeTree(FILE *fp)
{
  storeTree(root, fp);
}






