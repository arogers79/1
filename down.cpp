#include "down.h"

down::down(int lv)

{
setlevel(lv);
}

void down::handler_2 (cl_1 * p_ob, string & s_text)

{
down * new_down = (down*)p_ob;
string command = "connect";
if ((p_ob->field[p_ob->LINE+1][p_ob->COL] == '1') && (p_ob->founder == 0))

{
p_ob->founder = 1;
p_ob->LINE = p_ob->LINE+1;
p_ob->set_connect(SIGNAL_D ( new_down->signal_1), p_ob, HANDLER_D (p_ob->handler_0) );
new_down -> emit_signal(SIGNAL_D(new_down -> signal_1),command);
}

else

{
p_ob->set_connect(SIGNAL_D ( new_down->signal_2), p_ob, HANDLER_D (p_ob->handler_b) );
new_down -> emit_signal(SIGNAL_D(new_down -> signal_2),command);
}
} 
