#ifndef UP_H
#define UP_H
#include "cl_base.h"
#include "cl_1.h"

class up: public cl_base

{
public: up(int lv);

static void signal_1 (string & s_text) { };
static void signal_2 (string & s_text) { };
static void handler_1 (cl_1 * p_ob, string & s_text);
};

#endif
