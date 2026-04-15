
#include"SRTF.hpp"

bool ComparePriority_SRTF::operator()(const process* a, const process* b) {
    // Higher priority goes first
    return a->remaining_bur_time > b->remaining_bur_time;
}

void srtf(std::vector<process> proc_list){
    
    fun(6); 
    cout << BOLDMAGENTA << "SHORTEST REMAINING TIME FIRST" << RESET;
    
    int i = 0;
    int n = proc_list.size();
    while(i<n){
        proc_list[i].remaining_bur_time = proc_list[i].bur_time;
        i++;    
    }

    sort(proc_list.begin(), proc_list.end(), compare_atime);
 
    priority_queue<process*, vector<process*>, ComparePriority_SRTF> pq;
    std::vector<block> gantt_blocks;
    block gantt_blk;
    int curr_time = 0, completed = 0, temp;
    process *proc_en, *proc_de;
    i = 0;
    
    while(completed != n){
        // add processes that have arrived at time 'curr_time' or before curr_time into the priority queue.
        while(i < n){
            proc_en = &proc_list[i];
            if(proc_en->arr_time > curr_time)
                break;
            pq.push(proc_en);
            i++;
        }

        //if queue is empty, curr time would change to the time of next arriving process 
        if(pq.empty() == true){
            curr_time = proc_list[i].arr_time;
            continue;
        }

        proc_de= pq.top();
        pq.pop();
        gantt_blk.process_no = proc_de->num, gantt_blk.start_time = curr_time;

        if(proc_de->remaining_bur_time == proc_de->bur_time)
            proc_de->res_time = curr_time - proc_de->arr_time;
        
        temp = curr_time;

        if(proc_de->bur_time > 0){
            if(i == n){
                curr_time += proc_de->remaining_bur_time;
                proc_de->remaining_bur_time = 0;
            }
            else{
                curr_time += min(proc_de->remaining_bur_time, proc_list[i].arr_time - curr_time);
                proc_de->remaining_bur_time -= min(proc_list[i].arr_time - temp, proc_de->remaining_bur_time);
            }
        }

        gantt_blk.end_time = curr_time;
        gantt_blocks.push_back(gantt_blk);

        if(proc_de->remaining_bur_time == 0){
            completed++;
            proc_de->com_time = curr_time ;
            proc_de->turn_time = proc_de->com_time - proc_de->arr_time;
            proc_de->wait_time = proc_de->turn_time - proc_de->bur_time;
        }
        else
            pq.push(proc_de);
    }
    display_sched(proc_list);
    display_avg(proc_list);
    std::vector<block> chart_blocks = insert_idle_blocks(gantt_blocks);
    display_gantt_chart(chart_blocks);
}
