#ifndef INTERFACE_H
#define INTERFACE_H
#include "cl_base.h"
#include "cl_1.h"

class interface: public cl_base

{
public: interface(int lv);
void input(cl_1 * p_ob_1);
void output(cl_1 * p_ob_1);
};

#endif 
