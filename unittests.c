#include <string.h>
#include "CUnit/Basic.h"
#include "db.h"
#include <stdlib.h>

int init_suite_1(void)
{
  return 0;
}

int clean_suite_1(void)
{
  return 0;
}

void testInit_database(){
  Node* n = init_database("SWE.db");
  char* val = getValue(*search(&n, "Dagger"));
  printf("%s", val);
  CU_ASSERT(strcmp(val, "2 4 0 2") == 0);
  clear(n);
}


void testUpdate(void){
  Node* n = init_database("SWE.db");
  update(n, "Dagger", "1 3 3 7" );
  char* val = getValue(*search(&n, "Dagger"));
  CU_ASSERT(strcmp(val, "1 3 3 7") == 0);
  clear(n);
}

void testInsert(){
  Node* n = init_database("SWE.db");
  insert(&n, "Pettan", "1");
  char* val = getValue(*search(&n, "Pettan"));
  CU_ASSERT(strcmp(val, "1") == 0);
  clear(n);
}
void testDelete(){
  Node* n = init_database("SWE.db");
  delete(&n, "Boatman");
  CU_ASSERT(*search(&n, "Boatman") == NULL);
  clear(n);
}

 int main(){
  CU_pSuite pSuite1 = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suites to the registry */
  pSuite1 = CU_add_suite("Basic Functions Suite", init_suite_1, clean_suite_1);
  if (NULL == pSuite1){
    CU_cleanup_registry();
    return CU_get_error();
  }
  
  /* add the tests to the suites */
  if ((NULL == CU_add_test(pSuite1, "test of init_database", testInit_database)) || (NULL == CU_add_test(pSuite1, "test of update", testUpdate)) || 
      NULL == CU_add_test(pSuite1, "test of insert", testInsert) || NULL == CU_add_test(pSuite1, "test of delete", testDelete)){
    CU_cleanup_registry();
    return CU_get_error();
  }


  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}

