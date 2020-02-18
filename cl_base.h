#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define SIGNAL_D( signal_f) ( ( void(*) ( string & ) ) ( & ( signal_f ) ) )
#define HANDLER_D( handler_f ) ( ( void(*) ( cl_base *, string & ) ) ( & ( handler_f ) ) )

using namespace std;

class cl_base

{
public:
cl_base(cl_base * p_parent = 0);
void set_object_name(string s_object_name);
string get_object_name();

//--------------------------------------------------------------- Иерархия объектов

void set_parent(cl_base * p_parent);
void add_child(cl_base * p_child);
void delete_child(string s_object_name);

cl_base * take_child(string s_object_name);
cl_base * get_child(string s_object_name);

//--------------------------------------------------------------- Состояние объекта

void set_state(int i_state);
int get_state();

//--------------------------------------------------------------- Сервис

void show_object_state();
void show_obj_next(cl_base * ob_parent);
void setlevel(int i);
int getlevel();
void show_hierarchy();

cl_base * get_object_root();
cl_base * get_path(string path);

//Сигналы и обработчики

void set_connect (void(*p_signal)(string &),cl_base * p_ob_handler, void(* p_handler)(cl_base * p_pb, string & ));

//void delete_connect (void (*p_signal) (string &), cl_base * p_ob_handler, void (*p_handler) (cl_base * p_ob, string &));

void emit_signal (void(*p_signal)(string &),string & s_command);

//k

int cnt = 0;
bool founder = 0;
int LINE;
int COL;
char field[10][10];
void step(int lines, int coloumns);
void first(int x);
bool flag = 1;

private:

struct o_sh{

cl_base * p_cl_base;

void( * p_handler )(cl_base * p_ob, string &);
};

multimap < void(*)(string &),o_sh * > connects;
multimap < void(*)(string &),o_sh * >::iterator it_connects;

int LEVEL;

vector<cl_base*> children; // Ссылки на подчиненные объекты
vector<cl_base*>::iterator it_child;
string object_name; // Имя объекта
cl_base * p_parent; // Ссылка на головной объект
int i_state; // Состояние объекта
void show_state_next(cl_base * ob_parent);
};

#endif 
