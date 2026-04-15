#ifndef proc_sched_driver
#define proc_sched_driver

#include"FCFS.hpp"

#include"LJF.hpp"
#include"LRTF.hpp"
#include"Priority.hpp"
#include"Priority_non.hpp"
#include"RR.hpp"
#include"SJF.hpp"
#include"SRTF.hpp"
#include<unistd.h>
#include <limits>  
#include<functional>

using namespace std;
void process_sched_animation();
vector<process> take_input();
int policy_choice();
int post_policy_choice();

#endif