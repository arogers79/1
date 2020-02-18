#ifndef DOWN_H
#define DOWN_H
#include "cl_base.h"
#include "cl_1.h"
	
class down: public cl_base

{
public: down(int lv);
static void signal_1 (string & s_text) { };
static void signal_2 (string & s_text) { };
static void handler_2 (cl_1 * p_ob, string & s_text);

};

#endif 
