
#ifndef SRTF
#define SRTF
#include"utilities.hpp"
#include<queue>
using namespace std;
class ComparePriority_SRTF {
public:
    bool operator()(const process* a, const process* b);
};
void srtf(std::vector<process> proc_list);
#endif