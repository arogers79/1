#ifndef SIDE_H
#define SIDE_H
#include "cl_base.h"
#include "cl_1.h"

class side: public cl_base

{
public: side(int lv);

static void signal_1 (string & s_text) { };
static void signal_2 (string & s_text) { };
static void handler_3 (cl_1 * p_ob, string & s_text);
};

#endif
