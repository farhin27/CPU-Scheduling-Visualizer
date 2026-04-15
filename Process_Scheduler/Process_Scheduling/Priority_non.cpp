
#include"Priority_non.hpp"




bool ComparePriority::operator()(const process* a, const process* b){
    // Higher priority goes first
    return a->priority > b->priority;
}



void priority_non(vector<process> proc_list){
    fun(6); 
    cout << BOLDMAGENTA <<"PRIORITY FIRST (Non-Preemptive Version)\n\n" << RESET;
   
    int i = 0, n = proc_list.size() ;
    
    cout << BOLDGREEN <<"\nEnter the priority for the " << BOLDWHITE << n << BOLDGREEN << " processes.\n\n";
    while(i<n){
        
        cout << BOLDGREEN << "Enter priority(0 is highest priority): " << BOLDWHITE;
        cin >> proc_list[i].priority;
        i++;
        
    }
    
    sort(proc_list.begin(), proc_list.end(), compare_atime);

    priority_queue<process*, vector<process*>, ComparePriority> pq;
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

    std::cout<< BOLDCYAN << "\n\nProcess No.\tPriority\tArrival Time\tBurst Time\tCompletion Time\t\tTurn-around Time\tWaiting Time\tResponse Time\n" << RESET;
    for(int i = 0; i < n; i++){
        std::cout<<proc_list[i].num<<"\t\t";
        std::cout<<proc_list[i].priority<<"\t\t";
        std::cout<<proc_list[i].arr_time<<"\t\t";
        std::cout<<proc_list[i].bur_time<<"\t\t";
        std::cout<<proc_list[i].com_time<<"\t\t\t";
        std::cout<<proc_list[i].turn_time<<"\t\t\t";
        std::cout<<proc_list[i].wait_time<<"\t\t";
        std::cout<<proc_list[i].res_time<<"\n";
    }
    display_avg(proc_list); 
    vector<block> chart_blocks = insert_idle_blocks(gantt_blocks);
    display_gantt_chart(chart_blocks);
}
