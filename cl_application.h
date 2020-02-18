#ifndef CL_APPLICATION_H
#define CL_APPLICATION_H
#include "cl_1.h"
#include "up.h"
#include "down.h"
#include "side.h"
#include "interface.h"

class cl_application: public cl_base
{
public: cl_application();

interface * call;
cl_1 * matrix;
up * find_u;
down * find_d;
side * find_r;

void build_tree_objects();
int exec_app();
void signal_1(string & s_text) {}
private: cl_base * p_ob;

};

#endif
