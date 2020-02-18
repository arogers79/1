#include "up.h"

up::up(int lv)

{
setlevel(lv);
}

void up::handler_1 (cl_1 * p_ob, string & s_text)

{
up * new_up = (up*)p_ob;
string command = "connect";
if (p_ob->field[(p_ob->LINE)-1][p_ob->COL] == '1')

{
p_ob->founder = 1;
p_ob->LINE = p_ob->LINE-1;
p_ob->set_connect(SIGNAL_D ( new_up->signal_1), p_ob, HANDLER_D (p_ob->handler_0) );
new_up -> emit_signal(SIGNAL_D(new_up-> signal_1),command);
}

else

{
p_ob->set_connect(SIGNAL_D ( new_up->signal_2), p_ob, HANDLER_D (p_ob->handler_b) );
new_up -> emit_signal(SIGNAL_D(new_up -> signal_2),command);
}
}
