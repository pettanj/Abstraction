typedef struct node Node;

/**
 * reads next line from a source into the buffer
 * @param dest the write destination
 * @param n size of Buffer
 * @param source to read from
 */
void readline(char *dest, int n, FILE *source);

/**
 * Initializes database 
 * @param filename the name of db-file to open
 * @return Returns an initialized database from input file 
 */
Node* init_database(char *filename);

/**
 * Changes the value of given key
 * @param n the database 
 * @param key key to update
 * @param value the new value 
 */
void update(Node* n, char* key, char* value);


/**
 * inserts new element to the database
 * @param n the database
 * @param key key of the element to insert
 * @param value the value of the element to insert
 */
void insert(Node** n, char* key, char* value);

/**
 * deletes an element from a database
 * @param n the database
 * @param key key to be deleted
 */
void delete(Node** n, char* key);

/**
 * prints the whole database
 * @param n the database
 *
 */
void print(Node* n);

/**
 * prints a given key
 * @param n the database
 * @param key the key of the element to print
 */
void query(Node** n, char* key);

Node** search(Node** n, char* key);

char* getValue(Node* n);

void clear(Node* n);
