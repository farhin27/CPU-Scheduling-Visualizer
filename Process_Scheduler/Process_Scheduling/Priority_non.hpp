#ifndef Priority_non
#define Priority_non
#include<queue>
#include"utilities.hpp"
using namespace std;
class ComparePriority{
    public:
    bool operator()(const process* a, const process* b);
};
void priority_non(vector<process> proc_list);
#endif