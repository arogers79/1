#ifndef CL_1_H
#define CL_1_H
#include "cl_base.h"

class cl_1: public cl_base

{
public: cl_1(int lv);

static void handler_0 (cl_1 * p_ob, string & s_text);
static void handler_b (cl_1 * p_ob, string & s_text);
static void signal_0 (string & s_text) { };
};

#endif
