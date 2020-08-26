#include <iostream>
#include <ctime>
#include <string.h>
#include <sqlite3.h>

using namespace std;

int main(int argc, const char *argv[]){
	sqlite3_stmt *stmt = NULL;
	sqlite3 *db;
	if(sqlite3_open_v2("/Users/sophieyou/Desktop/alan/todo/todo.db", &db, SQLITE_OPEN_READWRITE, NULL)){
		cerr << "error : " << sqlite3_errmsg(db) << endl;
		return false;
	}
	if(argc==1){
		cout << "arguments:" << endl << "add - add an item to todo list" << endl;
	}
	else if(string(argv[1])=="add"){
		if(argc < 3){
			cout << "not enough arguments(needs the context)" << endl;
		}
		else{
			char *query=NULL;
			asprintf(&query, "INSERT INTO todos VALUES ('%s', 0)", argv[2]);
			cout << query << endl;
			sqlite3_prepare_v2(db, query, strlen(query), &stmt, NULL);

			if( sqlite3_step(stmt) != SQLITE_DONE ){
				cerr << "error : " << sqlite3_errmsg(db) << endl;
			}
			else{
				cout << argv[2] << " - successfully added" << endl;
			}
		}
	}
	//else if(string(argv[1])=="-l"){
		//sqlite3_exec(db, )
	//}
	else {
		cout << "unknown argument" << endl;
	}

	sqlite3_close(db);
	return 0;
}
