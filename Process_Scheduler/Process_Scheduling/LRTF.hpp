#ifndef LRTF
#define LRTF
#include"utilities.hpp"
#include<queue>
#include<limits.h>
using namespace std;
class ComparePriority_LRTF {
public:
    bool operator()(const process* a, const process* b);
       
};
void lrtf(vector<process> proc_list);
#endif