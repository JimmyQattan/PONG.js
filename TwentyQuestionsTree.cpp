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
  if(r && r->left == NULL && r->right == NULL)
  {
    delete r->question;
    r->question = new char[strlen(parent)+1];
    strcpy(r->question,parent);
    r->left = new BinaryNode(left);
    r->right = new BinaryNode(right);
    return true;
  }
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
    if(n->left!=NULL)
    {
      if(modifyAndInsert(n->left,parent,left,right))
	return true;
    }
    else if(n->right!=NULL)
    {
      if(modifyAndInsert(n->right,parent,left,right))
	return true;
    }
    else
      return false;
  }
  
    
 
}
