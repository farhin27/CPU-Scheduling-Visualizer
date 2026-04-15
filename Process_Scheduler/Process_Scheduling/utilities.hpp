#ifndef UTILITIES

#define UTILITIES
#include<vector>
#include<algorithm>
#include<iostream>
#include<unistd.h>
#include<iomanip>
#include<string>


using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define UN "\e[4m"
class process{
    public:
    int num; //process number
    int arr_time; // arrival time
    int bur_time; // burst time
    int com_time; // completion time
    int res_time; // response time
    int wait_time; // wait time
    int turn_time; // turnaround time
    int priority; //priority
    int remaining_bur_time; //remaining_bur_time
    int isCompleted;
};
class block{
    public:
    int process_no;
    int start_time;
    int end_time;
};
void fun(size_t max);
bool compare_atime(process P, process Q); //to sort according to arrival time
void display_sched(std::vector<process> &proc_list);
void display_avg(vector<process> proc_list);
void display_gantt_chart(const vector<block> &gantt_blocks);
std::vector<block> insert_idle_blocks(const std::vector<block>& schedule);
#endif