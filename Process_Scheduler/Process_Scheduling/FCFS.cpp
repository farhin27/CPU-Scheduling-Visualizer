
#include "FCFS.hpp"

using namespace std;



void fcfs(vector<process> proc_list){
    fun(6);
    cout << BOLDMAGENTA << "FIRST COME FIRST SERVE" << RESET;
    int n = proc_list.size();
    sort(proc_list.begin(), proc_list.end(), compare_atime);
    
    int curr_time = proc_list[0].arr_time, completed = 0, ptr = 0; 
    vector<block> gantt_blocks;
    block gantt_blk;

    while(completed != n){
        proc_list[ptr].res_time = curr_time - proc_list[ptr].arr_time;
        gantt_blk.process_no = proc_list[ptr].num, gantt_blk.start_time = curr_time;
        curr_time += proc_list[ptr].bur_time;
        gantt_blk.end_time = curr_time;
        gantt_blocks.push_back(gantt_blk);
        completed++;
        proc_list[ptr].com_time = curr_time ;
        proc_list[ptr].turn_time = proc_list[ptr].com_time - proc_list[ptr].arr_time;
        proc_list[ptr].wait_time = proc_list[ptr].turn_time - proc_list[ptr].bur_time;
        ptr++;
        curr_time = max(curr_time, proc_list[ptr].arr_time);
    }

    display_sched(proc_list);
    display_avg(proc_list);
    vector<block> chart_blocks = insert_idle_blocks(gantt_blocks);
    display_gantt_chart(chart_blocks);
}

