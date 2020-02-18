#include <iostream>
#include "cl_base.h"

cl_base::cl_base(cl_base * p_parent)

{
set_object_name("cl_base");
if(p_parent)

{
this->p_parent = p_parent;
p_parent->add_child(this);
}

else

{
this->p_parent = 0;
}
}

void cl_base::set_object_name(string s_object_name)

{
object_name = s_object_name;
}

string cl_base::get_object_name()

{
return object_name;
}

void cl_base::set_parent(cl_base * p_parent)

{
if(p_parent)
{
this->p_parent = p_parent;
p_parent->children.push_back(this);
}
}

void cl_base::add_child(cl_base * p_child)

{
this->children.push_back(p_child);
}

void cl_base::delete_child(string s_object_name)

{
if(children.size() == 0) return;
it_child = children.begin();
while(it_child != children.end())
{

if((*it_child)->get_object_name() == s_object_name)

{
children.erase(it_child);
return;
}
it_child++;
}
}

cl_base * cl_base::take_child(string s_object_name)

{
cl_base * ob_child;
ob_child = get_child(s_object_name);
if(ob_child == 0) return 0;
delete_child(s_object_name);
return ob_child;
}

cl_base * cl_base::get_child(string s_object_name)

{
if(children.size() == 0) return 0;
it_child = children.begin();
while(it_child != children.end())
{
if((*it_child)->get_object_name() == s_object_name)

{
return (*it_child);
}

it_child++;

}
return 0;
}

void cl_base::set_state(int i_state)

{
this->i_state = i_state;
}

int cl_base::get_state()

{
return i_state;
}

void cl_base::show_object_state()

{
show_state_next((cl_base*)this);
}

void cl_base::show_state_next(cl_base * ob_parent)

{
if(ob_parent->get_state() == 1)
{
std::cout << "The object " << ob_parent->get_object_name() << " is ready" << std::endl;
}

else

{
std::cout << "The object " << ob_parent->get_object_name() << " is not ready" << std::endl;
}
if(ob_parent->children.size() == 0) return;
ob_parent->it_child = ob_parent->children.begin();
while(ob_parent->it_child != ob_parent->children.end())

{
show_state_next((*(ob_parent->it_child)));
ob_parent->it_child++;
}
}

void cl_base::setlevel(int i)

{
LEVEL = i;
}

int cl_base::getlevel()

{
return LEVEL;
}

void cl_base::show_hierarchy()

{
show_obj_next((cl_base*)this);
}

void cl_base::show_obj_next(cl_base * ob_parent)

{

if (ob_parent -> get_object_name() != "root")
std::cout << std::endl;
for(int i = 0; i < ob_parent->getlevel() * 4; i++)
std::cout << " ";
std::cout << ob_parent->get_object_name();
if(ob_parent->children.size() == 0) return;
ob_parent->it_child = ob_parent->children.begin();
while(ob_parent->it_child != ob_parent->children.end())

{
show_obj_next((*(ob_parent->it_child)));
ob_parent->it_child++;
}
}

//l 2

cl_base * cl_base::get_path (string path)

{
if (path != "")
path.replace(0,1,"");
else return this;
int cnt = 0;
string current = "";
while(cnt< path.size())

{

if (path[cnt] != '/')
current = current + path[cnt];
else return (*(this->get_child(current))).get_path(path.replace(0,cnt,""));
cnt++;
}

return (*(this->get_child(current))).get_path("");

}
cl_base * cl_base::get_object_root()
{

cl_base * p_parent_previous;
if(object_name == "root") return this;
p_parent_previous = p_parent;
while(p_parent_previous->p_parent)

{
p_parent_previous = p_parent_previous->p_parent;
}
return p_parent_previous;
}

//l 3
void cl_base::set_connect (void ( * p_signal) (string &),cl_base * p_ob_handler, void ( * p_handler)(cl_base*p_pb,string &))

{
void(* p_key)(string &);
o_sh * p_value;
if (connects.size()>0)

{
it_connects = connects.begin();
while (it_connects != connects.end())

{
p_key = it_connects->first;
p_value = it_connects->second;
if((p_key == p_signal) && (p_value -> p_cl_base) == p_ob_handler && (p_value -> p_handler) == p_handler) return;
it_connects++;
}
}

p_value = new o_sh();
p_value -> p_cl_base = p_ob_handler;
p_value -> p_handler = p_handler;
connects.insert({ p_signal,p_value });
}

void cl_base::emit_signal(void (*s_ignal)(string &) , string & s_command)

{
void (*p_handler)(cl_base * p_ob, string &);
if (connects.empty()) return;
if (connects.count(s_ignal) == 0) return;
(s_ignal)(s_command);
it_connects = connects.begin();
while (it_connects != connects.end())

{
if ((it_connects->first)==s_ignal)

{
p_handler = it_connects->second->p_handler;
(p_handler) (it_connects->second->p_cl_base, s_command);
}
it_connects++;
}
}

//k

void cl_base::first(int x)

{
while ( x < 10 )

{
bool D = (field[x][0] == '1');
bool B = (field[x+1][0] == '1');
bool C = (field[x][1] == '1');
bool A = (field[x-1][0] == '1');

if ( D && ((A&&!B&&!C) || (B&&!A&&!C) || (!A&&!B&&C)))

{
LINE = x;
COL = 0;
return ;
}

x ++;
}
}

void cl_base::step(int lines, int coloumns)

{
field[lines][coloumns] = 'F';
}
