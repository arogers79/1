#include "interface.h"
#include "cl_1.h"

interface::interface(int lv)

{
setlevel(lv);
}

void interface::input(cl_1 * p_ob_1)

{
for (int i = 0; i < 10; i++)
{
for (int j = 0; j < 10; j++)
std::cin >> p_ob_1->field[i][j];
}
}

void interface::output(cl_1 * p_ob_1)

{
for (int i = 0; i < 10; i++)
{
for (int j = 0; j < 10; j++)
std::cout << p_ob_1->field[i][j];
if (i != 9) std::cout << std::endl;
}
}
