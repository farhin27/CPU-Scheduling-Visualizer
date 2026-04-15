
#include"LJF.hpp"


bool ComparePriority_ljf::operator()(const process* a, const process* b) {
    // Higher priority goes first
    return a->bur_time < b->bur_time;
}



void ljf(vector<process> proc_list){
    fun(6);
    cout << BOLDGREEN << "LONGEST JOB FIRST" << RESET;
    int n = proc_list.size();
    sort(proc_list.begin(), proc_list.end(), compare_atime);

    priority_queue<process*, vector<process*>, ComparePriority_ljf> pq;
    vector<block> gantt_blocks;
    block gantt_blk;
    int curr_time = 0, completed = 0, ptr = 0;
    process* proc_en, *proc_de;
   
    while(completed != n){
        // add processes into priority queue, priority is high burst time in this case
        while(ptr<n){
            proc_en = &proc_list[ptr];
            if(proc_en->arr_time > curr_time)
                break;
            pq.push(proc_en);
            ptr++;
        } 
        if(pq.empty()){
            curr_time = proc_list[ptr].arr_time;
            continue;
        }
        proc_de = pq.top();
        pq.pop();
        gantt_blk.process_no = proc_de->num, gantt_blk.start_time = curr_time;

        proc_de->res_time = curr_time - proc_de->arr_time;
        curr_time += proc_de->bur_time;

        gantt_blk.end_time = curr_time;
        gantt_blocks.push_back(gantt_blk);

        completed++;
        proc_de->com_time = curr_time;
        proc_de->turn_time = proc_de->com_time - proc_de->arr_time;
        proc_de->wait_time = proc_de->turn_time - proc_de->bur_time;
    }

     //Displaying the times in tabular form
    display_sched(proc_list);
    display_avg(proc_list);
    vector<block> chart_blocks = insert_idle_blocks(gantt_blocks);
    display_gantt_chart(chart_blocks);
}
