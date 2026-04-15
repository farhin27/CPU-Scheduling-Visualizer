#include "utilities.hpp"

void fun(size_t max){
    long int j=1 <<16;
    for (size_t i = 0; i < max; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
}

bool compare_atime(process P, process Q) //to sort according to arrival time
{
    if(P.arr_time == Q.arr_time)
        return P.bur_time < Q.bur_time;
    return (P.arr_time < Q.arr_time);
} 

void display_avg(vector<process> proc_list){
    int n = proc_list.size();
    double avg_turnaround_t, avg_waiting_t, avg_response_t;
    double total_turnaroun_t = 0, total_waiting_t = 0, total_response_t = 0;
    for(int i = 0; i < n; i++){
        total_turnaroun_t += proc_list[i].turn_time;
        total_waiting_t += proc_list[i].wait_time;
        total_response_t += proc_list[i].res_time;
    }
    avg_turnaround_t = total_turnaroun_t / n;
    avg_waiting_t = total_waiting_t / n;
    avg_response_t = total_response_t / n;
    cout << BOLDCYAN << "\nAverage Turnaround Time: " << BOLDWHITE << avg_turnaround_t << "\n\n";
    cout << BOLDCYAN << "Average Waiting Time: " << BOLDWHITE << avg_waiting_t << "\n\n";  
    cout << BOLDCYAN << "Average Response Time: " << BOLDWHITE << avg_response_t; 
}

void display_sched(std::vector<process> &proc_list){
    int n = proc_list.size();
    
    std::cout<< BOLDCYAN << "\n\nProcess No.\tArrival Time\tBurst Time\tCompletion Time\t\tTurn-around Time\tWaiting Time\tResponse Time\n" << RESET;
    for(int i = 0; i < n; i++){
        std::cout<<proc_list[i].num<<"\t\t";
        std::cout<<proc_list[i].arr_time<<"\t\t";
        std::cout<<proc_list[i].bur_time<<"\t\t";
        std::cout<<proc_list[i].com_time<<"\t\t\t";
        std::cout<<proc_list[i].turn_time<<"\t\t\t";
        std::cout<<proc_list[i].wait_time<<"\t\t";
        std::cout<<proc_list[i].res_time<<"\n";
    }
}
/*
void display_gantt_chart(std::vector<block> gantt_blocks){
    int i, n = gantt_blocks.size();
    cout << "\n\n\n" << BOLDGREEN << "Gantt Chart:\n\n" << BOLDWHITE;
    if(gantt_blocks[0].start_time != 0)
        cout << "Idle\t\t|";
    cout<<"+";
    for(i = 0; i < n; i++){
        cout<<"-------+";
    }
    cout << "\n|" << BOLDCYAN;
    for(i = 0; i < n; i++){
        cout << BOLDCYAN <<"   P" << gantt_blocks[i].process_no << "  " << BOLDWHITE<< "|";
    }
    cout << BOLDWHITE <<"\n+";
    for (i = 0; i < n; i++){
        cout<<"-------+";
    }
    
}
*/



// ---------- Insert Idle Blocks (call this separately) ----------
std::vector<block> insert_idle_blocks(const std::vector<block>& schedule) {
    std::vector<block> result;
    if (schedule.empty()) return result;
    int prev_end = 0;
    for (const auto& blk : schedule) {
        if (blk.start_time > prev_end)
            result.push_back({0, prev_end, blk.start_time});
        result.push_back(blk);
        prev_end = blk.end_time;
    }
    return result;
}


void display_gantt_chart(const std::vector<block>& gantt_blocks) {
    if (gantt_blocks.empty()) return;

    // ---- 1. Determine cell width ----
    int max_label_len = 4; // "Idle"
    for (const auto& blk : gantt_blocks) {
        if (blk.process_no != 0) {
            std::string label = "P" + std::to_string(blk.process_no);
            max_label_len = std::max(max_label_len, (int)label.size());
        }
    }
    const int cell_width = std::max(max_label_len + 2, 3); // at least 3

    // Helper to centre a string
    auto centre = [cell_width](const std::string& s) {
        int pad = cell_width - (int)s.size();
        int left = pad / 2;
        int right = pad - left;
        return std::string(left, ' ') + s + std::string(right, ' ');
    };

    // ---- 2. Build the chart strings ----
    std::string top_border = "+";
    std::string process_row = "|" BOLDCYAN;
    std::string bottom_border = "+";
    std::string timestamp_row; // we'll fill this manually

    // For timestamp positions, we'll store the column index (character position) of each '+'
    std::vector<int> plus_positions;
    plus_positions.push_back(0); // first '+' at position 0

    int current_pos = 1; // after the first '+'

    for (size_t i = 0; i < gantt_blocks.size(); ++i) {
        const auto& blk = gantt_blocks[i];

        // Add cell dashes
        top_border += std::string(cell_width, '-') + "+";
        bottom_border += std::string(cell_width, '-') + "+";

        // Process label
        std::string label = (blk.process_no == 0) ? "Idle" : ("P" + std::to_string(blk.process_no));
        process_row += centre(label) + BOLDWHITE "|" BOLDCYAN;

        // Record next '+' position
        current_pos += cell_width;
        plus_positions.push_back(current_pos);
        current_pos += 1; // for the '+'
    }

    process_row += BOLDWHITE; // reset colour

    // ---- 3. Build timestamp row by placing numbers at plus_positions ----
    // We'll create a string with enough spaces, then overwrite at exact indices
    int total_width = current_pos; // length of the border string
    timestamp_row = std::string(total_width, ' ');

    // Place first timestamp (start of first block) at position 0
    std::string first_time = std::to_string(gantt_blocks[0].start_time);
    timestamp_row.replace(0, first_time.size(), first_time);

    // Place end times at each '+' after the first one (index 1..n)
    for (size_t i = 0; i < gantt_blocks.size(); ++i) {
        int pos = plus_positions[i + 1]; // position of the '+' after block i
        std::string time_str = std::to_string(gantt_blocks[i].end_time);
        // Ensure we don't write past the end
        if (pos < total_width) {
            timestamp_row.replace(pos, time_str.size(), time_str);
        }
    }

    // ---- 4. Output everything ----
    std::cout << "\n\n" << BOLDGREEN << "Gantt Chart:\n\n" << BOLDWHITE;
    std::cout << top_border << "\n";
    std::cout << process_row << "\n";
    std::cout << bottom_border << "\n";
    std::cout << timestamp_row << RESET << "\n";
}