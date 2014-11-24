#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"


int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: db [FILE]");
    return -1;
  }
  puts("Welcome to");
  puts(" ____    ____       ");
  puts("/\\  _`\\ /\\  _`\\     ");
  puts("\\ \\ \\/\\ \\ \\ \\L\\ \\   ");
  puts(" \\ \\ \\ \\ \\ \\  _ <\\ ");
  puts("  \\ \\ \\_\\ \\ \\ \\L\\ \\ ");
  puts("   \\ \\____/\\ \\____/ ");
  puts("    \\/___/  \\/___/  ");
  puts("");
  
  Node* list = init_database(argv[1]);
  char buffer[128];
  char buffer_2[128];
  
  int choice = -1;
  while(choice != 0){
    puts("Please choose an operation");
    puts("1. Query a key");
    puts("2. Update an entry");
    puts("3. New entry");
    puts("4. Remove entry");
    puts("5. Print database");
    puts("0. Exit database");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin;
    switch(choice){
    case 1:
      // Query
      printf("Enter key: ");
      

      readline(buffer, 128, stdin);
      query(&list, buffer);
     
      break;
    case 2:
      // Update
      printf("Enter key: ");
      readline(buffer, 128, stdin);
      
      printf("Enter new value: ");
      readline(buffer_2, 128, stdin);

      update(list, buffer, buffer_2); 
      break;

    case 3:
      // Insert
      printf("Enter key: ");
      readline(buffer, 128, stdin);

      printf("Enter value: ");
      readline(buffer_2, 128, stdin);

      insert(&list, buffer, buffer_2);
      break;

    case 4:
      // Delete
      printf("Enter key: ");
      readline(buffer, 128, stdin);

      delete(&list, buffer);
      break;

    case 5:
      // Print database;
      print(list);
      break;
    case 0:
      // Exit
      puts("Good bye!");
      break;
    default:
      // Please try again
      puts("Could not parse choice! Please try again");
    }
    puts("");
  }
  return 0;
}
