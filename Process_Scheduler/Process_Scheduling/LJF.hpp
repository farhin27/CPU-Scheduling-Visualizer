#ifndef LJF
#define LJF
#include"utilities.hpp"
#include <queue>
using namespace std;
void ljf(vector<process> proce_list);
class ComparePriority_ljf {
public:
    bool operator()(const process* a, const process* b);
};

#endif
