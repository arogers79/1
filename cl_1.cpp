#include "cl_1.h"

cl_1::cl_1(int lv)

{
setlevel(lv);
}

void cl_1::handler_0 (cl_1 * p_ob, string & s_text)

{
p_ob->flag = 1;
}

void cl_1::handler_b (cl_1 * p_ob, string & s_text)

{
p_ob->cnt++;
if (p_ob->cnt == 3) p_ob->flag = 0;
}
