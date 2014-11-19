#include <stdlib.h>
#include <stdio.h>
#include "db.h"

int main(void){
  Node *list = NULL;
  insert(&list, "anna", "1");
  insert(&list, "boatman", "3");
  insert(&list, "anders", "3");
  insert(&list, "paladin", "1337");
  insert(&list, "sven", "10");
  insert(&list, "citrus", "88");
  insert(&list, "dansande", "9999");
  update(list, "paladin", "123");
  delete(list, "paladin");
  delete(list, "anna");
  print(list);
  return 0;
}
