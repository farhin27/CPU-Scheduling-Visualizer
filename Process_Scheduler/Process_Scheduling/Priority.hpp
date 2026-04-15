#ifndef Priority
#define Priority
#include"utilities.hpp"
#include<queue>
using namespace std;
class ComparePriority_priority {
    public:
    bool operator()(const process* a, const process* b);
};
void priority(vector<process> proc_list);
#endif