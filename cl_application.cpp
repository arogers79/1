#include "cl_application.h"

cl_application::cl_application()

{
set_object_name("root");
setlevel(0);
}

void cl_application::build_tree_objects()

{
find_u = new up(2);
find_u->set_object_name("U");
find_u->set_parent(this);
find_d = new down(2);
find_d->set_object_name("D");
find_d->set_parent(this);
find_r = new side(2);
find_r->set_object_name("R");
find_r->set_parent(this);

matrix = new cl_1(1);
matrix->set_parent(this);
matrix->set_object_name("M");

call = new interface(3);
call->set_parent(this);
call->set_object_name("I");

//cl_base *pBase = matrix;

//cl_1 *cl1 = (cl_1*)pBase;
}

int cl_application::exec_app()

{
string command = "connection";
string sg = "asd";
call -> input(matrix);
//call -> output(matrix);
this->set_connect(SIGNAL_D ( matrix->signal_0), matrix, HANDLER_D (find_u->handler_1) ); //Второй аргумент - ссылка на cl_base
this->set_connect(SIGNAL_D ( matrix->signal_0), matrix, HANDLER_D (find_d->handler_2) );
this->set_connect(SIGNAL_D ( matrix->signal_0), matrix, HANDLER_D (find_r->handler_3) );

matrix->first(0);

do

{
matrix->cnt = 0;
matrix->founder = 0;
matrix->step(matrix->LINE, matrix->COL);

this -> emit_signal(SIGNAL_D(matrix -> signal_0),command);//Отправка сигнала на поиск направления
}

while(matrix->flag);
call -> output(matrix);

return 0;

}
