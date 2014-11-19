typedef struct node Node;
//reads line from buffer
void readline(char *dest, int n, FILE *source);
//intializes database from .db file
Node* init_database(char *filename);
//Finds given key in database
Node** search(Node** n, char* key);
//updates the value of given key
void update(Node*list, char* key, char* value);
//inserts new key and value into the database
void insert(Node** n, char* key, char* value);
//deletes item with given key in database
void delete(Node** n, char* key);
//prints the database
void print(Node* n);
//prints the the key and the value given the key.
void query(Node** n, char* key);

