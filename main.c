#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("data.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        system("pause");
        
        return 1;
    } 
//	else {
//    	printf("Connected to database! \n");
//	}
    
    char *sql1 = "DELETE FROM event WHERE dict_event_type = 0;";
    
    rc = sqlite3_exec(db, sql1, 0, 0, &err_msg);
    
       
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        system("pause");
        
        return 1;
    } 
    
    sqlite3_close(db);  
    
    printf("All 0 were removed from event table! \n");
    
    system("pause");   
       
	return 0;
}
