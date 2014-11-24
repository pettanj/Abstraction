#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

typedef struct node{
  char *key;
  char *value;
  struct node *left;
  struct node *right;
} Node;

char* getValue(Node* n){
  return n->value;
}
Node** search(Node** n, char* key){
  if (*n == NULL){
    return n;
  }
  int compare = strcmp((*n)->key, key);

  if (compare == 0){
    return n;
  }
  if(compare < 0){
    search(&((*n)->right), key);
  }
  if(compare > 0){
    search(&((*n)->left), key);
  }
}

void query(Node** n, char* key){
  Node** temp = search(n, key);
  if(*temp == NULL){
    puts("Key not found...");
  }else{
    printf("Key: %s\nValue: %s\n", (*temp)->key, (*temp)->value);
  }
  return;
}

void insert(Node** n, char* key, char* value){
  Node** temp = search(n, key);
  if(*temp == NULL){
    Node *newNode = malloc(sizeof(struct node));
			  
    newNode->key = malloc(strlen(key)+ 1);
    strcpy(newNode->key, key);
    
    newNode->value = malloc(strlen(value) + 1);
    strcpy(newNode->value, value);  

    *temp = newNode;
  }
}

void print(Node* n){
  if (n != NULL){
    print(n->left);
    printf("%s, %s\n", n->key, n->value);
    print(n->right);
  }
}

void update(Node* n, char* key, char* value){
  Node** temp = search(&n, key);
  if(*temp == NULL){
    puts("Does not exist!\n");
  }else{
    strcpy((*temp)->value, value);
  }
}

Node* find_min(Node* n){
  if(n == NULL){
    return NULL; 
  }  

  if(n->left){
    find_min(n->left);
  }else{
    return n;
  }
}

void delete(Node** n, char* key){
  Node** temp = search(n,key);

  if (*temp == NULL){
    printf("The key does not exist.\n");
  }

  if ((*temp)->left && (*temp)->right){
    Node* min      = find_min((*temp)->right);
    (*temp)->key   = min->key;
    (*temp)->value = min->value;
    

  }else{
    if ((*temp)->left == NULL){
      (*temp) = (*temp)->right;
    }else if((*temp)->right == NULL){
      (*temp) = (*temp)->left;
    }else{
      return;
    }
  }
}

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n'){
    dest[len-1] = '\0';
  }
}

Node* init_database(char *filename){
  printf("Loading database \"%s\"...\n\n", filename);
  FILE *database = fopen(filename, "r");
  char buffer[128];
  char buffer_2[128];
  Node *list = NULL;
  while(!(feof(database))){
    readline(buffer, 128, database);
    readline(buffer_2, 128, database);
    insert(&list, buffer, buffer_2);
  }
  return list;
}
