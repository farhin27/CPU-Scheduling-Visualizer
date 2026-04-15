#include"proc_sched_driver.hpp"

void process_sched_animation(){
    long int j=1 <<16;
    for (size_t i = 0; i < 5; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    cout << BOLDCYAN;
    cout << "██████╗ ██████╗  █████╗  █████╗ ███████╗ ██████╗ ██████╗" << endl;
    cout << "██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝" << endl;
    cout << "██████╔╝██████╔╝██║  ██║██║  ╚═╝█████╗  ╚█████╗ ╚█████╗" << endl;
    cout << "██╔═══╝ ██╔══██╗██║  ██║██║  ██╗██╔══╝   ╚═══██╗ ╚═══██╗" << endl;
    cout << "██║     ██   ██║╚█████╔╝╚█████╔╝███████╗██████╔╝██████╔╝" << endl;
    cout << "╚═╝     ╚═╝  ╚═╝ ╚════╝  ╚════  ╚══════╝╚═════╝ ╚═════╝" << endl;
    cout << endl;
    cout << " ██████╗ █████╗ ██╗  ██╗███████╗██████╗ ██╗   ██╗██╗     ██╗███╗  ██╗ ██████╗" << endl;
    cout << "██╔════╝██╔══██╗██║  ██║██╔════╝██╔══██╗██║   ██║██║     ██║████╗ ██║██╔════╝" << endl;
    cout << "╚█████╗ ██║  ╚═╝███████║█████╗  ██║  ██║██║   ██║██║     ██║██╔██╗██║██║  ███╗" << endl;
    cout << " ╚═══██╗██║  ██╗██╔══██║██╔══╝  ██║  ██║██║   ██║██║     ██║██║╚████║██║  ╚██╗" << endl;
    cout << "██████╔╝╚█████╔╝██║  ██║███████╗██████╔╝╚██████╔╝███████╗██║██║ ╚███║╚██████╔╝" << endl;
    cout << "╚═════╝  ╚════╝ ╚═╝  ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚══════╝╚═╝╚═╝  ╚══╝ ╚═════╝" << endl;
    cout << RESET;
    j=1 <<16;
    for (size_t i = 0; i < 5; i++){
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
    
}
/*
vector<process> take_input(){
	fun(4);
	cout << BOLDGREEN << "Enter the number of processes you want for the simulation of algorithm: " << BOLDWHITE;
    int n;
    cin >> n;
	//if zero do something
	// code here
    vector<process> proc_list(n);
    int i = 0;
    cout << BOLDGREEN <<"\nEnter the arrival time and burst time for the "<< BOLDWHITE << n << BOLDGREEN << " processes.\n" ;
    while(i<n){
        proc_list[i].num = i + 1;
        cout << BOLDGREEN <<"\n\nPROCESS " << BOLDWHITE << i + 1 << "\n\n";
        cout << BOLDGREEN<<"Arrival time: " << BOLDWHITE;
        cin >> proc_list[i].arr_time;
        cout << BOLDGREEN <<"Burst time: " << BOLDWHITE;
        cin >> proc_list[i].bur_time;
        i++;
    }
	cout << RESET << "\n";
	return proc_list;
}
int policy_choice(){
	long int j=1 <<16;
    for (size_t i = 0; i < 5; i++)
    {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        cout << endl;
    }
	int choice;
	cout << BOLDGREEN << "Choose Algorithm to simulate" << BOLDWHITE << "\n\n";
	cout << "1. First Come First Serve [FCFS]\n";
	cout << "2. Shortest Job First [SJF]\n";
	cout << "3. Round Robin [RR]\n";
	cout << "4. Longest Job First [LJF]\n";
	cout << "5. Shortest Remaining Time First [SRTF]\n";
	cout << "6. Longest Remaining Time First [LRTF]\n";
	cout << "7. Priority Non-preemptive [Pri_non]\n";
	cout << "8. Priority Preemptive [Pri_p]\n";
	cout << "0. Exit \n\n";

	cout << BOLDGREEN <<  "Your choice : " << BOLDWHITE;
	cin >> choice;
	cout << RESET;
	return choice;
}
int post_policy_choice(){
	
    
	int choice;
	cout << BOLDGREEN <<"\nChoose among the following options and enter the corresponding number\n\n" << BOLDWHITE;
	cout << "1. To continue with the same set of processes entered\n";
	cout << "2. To enter new set of processes\n";
	cout << "3. To exit\n";
	cout << BOLDGREEN <<"Your choice: " << BOLDWHITE;
	cin >> choice;
	cout << RESET; 
	return choice;
}
int main(){
	int flag;
	process_sched_animation();
	while(true){
		vector<process> proc_list = take_input();	
		flag = 1;
		while(true){
        	int choice = policy_choice();
			switch (choice){
				case 1:
					fcfs(proc_list);
					break;
				case 2:
					sjf(proc_list);
					break;
				case 3:
					round_robin(proc_list);
					break;
				case 4:
					ljf(proc_list);
					break;
				case 5:
					srtf(proc_list);
					break;
				case 6:
					lrtf(proc_list);
					break;
				case 7:
					hrrf(proc_list);
					break;
				case 8:
					priority_non(proc_list);
					break;
				case 9:
					priority(proc_list);
					break;
				case 0:
					return;
				default:
					cout << BOLDRED << "Invalid key!\n\n"; 
					return;
			}
			long int j = 1<<16;
    		for (size_t i = 0; i < 5; i++){
        		usleep(j); // move faster and faster,
        		j = (int)(j * 0.9); // so sleep less each time
        		cout << endl;
    		}
			cout << BOLDGREEN <<"Enter a key to continue: \n" << BOLDWHITE;
			getchar();
			getchar();
			choice = post_policy_choice();
			switch (choice){
				case 1://same choice of processes, don't break from loop 
					break;
				case 2://new set of processes, break from the current loop
					flag = 0;
					break;
				case 3://exit, return
					return;
				default:
					cout << BOLDRED << "Invalid key!\n\n"; 
					break;
			}
			if(flag == 0)
				break;
		}		
	}
}
*/


// Helper: clear cin after a failed read
void clearCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Helper: get an integer with a custom validator
int getValidatedInt(const std::string& prompt, std::function<bool(int)> validator) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            clearCin();
            std::cout << BOLDRED << "\nInvalid input. Please enter an integer.\n\n" << RESET;
        } else if (!validator(value)) {
            clearCin(); // consume leftover newline
            std::cout << BOLDRED << "\nValue out of allowed range.\n\n" << RESET;
        } else {
            clearCin(); // good input, clean newline
            return value;
        }
    }
}

vector<process> take_input() {
    fun(4);
    std::string prompt = BOLDGREEN + std::string("Enter the number of processes you want for the simulation of algorithm: ") + BOLDWHITE;
    int n = getValidatedInt(prompt, [](int v) { return v > 0; });

    vector<process> proc_list(n);
    int i = 0;
    cout << BOLDGREEN << "\nEnter the arrival time and burst time for the " << BOLDWHITE << n << BOLDGREEN << " processes.\n";
    while (i < n) {
        proc_list[i].num = i + 1;
        cout << BOLDGREEN << "\n\nPROCESS " << BOLDWHITE << i + 1 << "\n\n";

        // Arrival time (non‑negative)
        std::string arrPrompt = BOLDGREEN + std::string("Arrival time: ") + BOLDWHITE;
        proc_list[i].arr_time = getValidatedInt(arrPrompt, [](int v) { return v >= 0; });

        // Burst time (positive)
        std::string burPrompt = BOLDGREEN + std::string("Burst time: ") + BOLDWHITE;
        proc_list[i].bur_time = getValidatedInt(burPrompt, [](int v) { return v > 0; });

        i++;
    }
    cout << RESET << "\n";
    return proc_list;
}

int policy_choice() {
    long int j = 1 << 16;
    for (size_t i = 0; i < 5; i++) {
        usleep(j);
        j = (int)(j * 0.9);
        cout << endl;
    }

    cout << BOLDGREEN << "Choose Algorithm to simulate" << BOLDWHITE << "\n\n";
    cout << "1. First Come First Serve [FCFS]\n";
    cout << "2. Shortest Job First [SJF]\n";
    cout << "3. Round Robin [RR]\n";
    cout << "4. Longest Job First [LJF]\n";
    cout << "5. Shortest Remaining Time First [SRTF]\n";
    cout << "6. Longest Remaining Time First [LRTF]\n";
    cout << "7. Priority Non-preemptive [Pri_non]\n";
    cout << "8. Priority Preemptive [Pri_p]\n";
    cout << "0. Exit Simulation \n\n";

    std::string prompt = BOLDGREEN + std::string("Your choice : ") + BOLDWHITE;
    // Allow 0..9 (change to 1..8 if needed by modifying lambda)
    return getValidatedInt(prompt, [](int v) { return v >= 0 && v <= 9; });
}

int post_policy_choice() {
    
    cout << BOLDGREEN << "\nChoose among the following options and enter the corresponding number\n\n" << BOLDWHITE;
    cout << "1. To continue with the same set of processes entered\n";
    cout << "2. To enter new set of proceses\n";
    cout << "3. Exit Simulation\n\n";
    std::string prompt = BOLDGREEN + std::string("Your choice: ") + BOLDWHITE;
    // Valid options: 1, 2, 3 (no zero here, but you can add if needed)
    return getValidatedInt(prompt, [](int v) { return v >= 1 && v <= 3; });
}

int proc_sched_main(){
    int flag;
    process_sched_animation();
    while (true) {
        vector<process> proc_list = take_input();
        flag = 1;
        while (true) {
            int choice = policy_choice();
            switch (choice) {
                case 1: fcfs(proc_list); break;
                case 2: sjf(proc_list); break;
                case 3: round_robin(proc_list); break;
                case 4: ljf(proc_list); break;
                case 5: srtf(proc_list); break;
                case 6: lrtf(proc_list); break;
                case 7: priority_non(proc_list); break;
                case 8: priority(proc_list); break;
                case 0: return 0;   // exit entire simulation
                default: 
                    return 0;
            }

            long int j = 1 << 16;
            for (size_t i = 0; i < 5; i++) {
                usleep(j);
                j = (int)(j * 0.9);
                cout << endl;
            }

            cout << BOLDGREEN << "Enter a key to continue: \n" << BOLDWHITE;
            getchar();
            
            choice = post_policy_choice();
            switch (choice) {
                case 1: break;//same set of processes return 0;
                case 2: flag = 0; break; //new set of processes
                case 3: return 0;//exit                   
                default: // not possible due to validator
                    return 0;
            }
            if(flag == 0) break;
        }
    }
}

int main(){
	proc_sched_main();
}