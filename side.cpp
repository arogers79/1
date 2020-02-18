#include "side.h"
#include "cl_1.h"

side::side(int lv)

{
setlevel(lv);
}

void side::handler_3(cl_1*p_ob, string&s_text)

{

side * new_side = (side*)p_ob;
string command = "connect";
if ((p_ob->field[p_ob->LINE][p_ob->COL+1] == '1') && (p_ob->founder == 0))

{
p_ob->COL = p_ob->COL+1;
p_ob->set_connect(SIGNAL_D ( new_side->signal_1), p_ob, HANDLER_D (p_ob->handler_0) );
new_side -> emit_signal(SIGNAL_D(new_side -> signal_1),command);
}

else

{
p_ob->set_connect(SIGNAL_D ( new_side->signal_2), p_ob, HANDLER_D (p_ob->handler_b) );
new_side -> emit_signal(SIGNAL_D(new_side -> signal_2),command);
}
}
