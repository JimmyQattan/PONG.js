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
 
  if(strcmp(r->question,parent)==0)
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

bool TwentyQuestionsTree::modifyAndInsert(BinaryNode *n,char *parent, char *left, char *right)
{
  
    if(strcmp(n->question,left)==0 || strcmp(n->question,right)==0)
      {
	delete n->question;
	n->question = new char[strlen(parent)+1];
	strcpy(n->question,parent);
	n->left = new BinaryNode(left);
	n->right = new BinaryNode(right);
	return true;
      }
  else
  {
    modifyAndInsert(n->left,parent,left,right);
    modifyAndInsert(n->right,parent,left,right);
    return false;
     
  }
  
    
 
}
void TwentyQuestionsTree::modifyAndInsert(char* parent,char* left,char* right)
{
  modifyAndInsert(root,parent,left,right);
}


void TwentyQuestionsTree::reset()
{
  iterator = root;
}


char *TwentyQuestionsTree::currentQuestion()
{
  if(iterator == NULL)
    return NULL;
  else
    return iterator->question;
}



void TwentyQuestionsTree::recordAnswer(int answer)
{
  if(answer == 0)
    iterator = iterator->left;
  else if(answer == 1)
    iterator = iterator->right;
  else
    return;

}


void TwentyQuestionsTree::storeTree(BinaryNode *n,FILE *fp)
{
  if(n == NULL)
    return;
  else if(n->left != NULL || n->right != NULL)
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
