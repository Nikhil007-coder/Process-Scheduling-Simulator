
#include <iostream>
using namespace std;

// Include each algorithm file without conflicting main() functions.

#define main fcfs_main
#include "FCFS.cpp"
#undef main

#define main priority_main
#include "Priority.cpp"
#undef main

#define main sjf_main
#include "SJF.cpp"
#undef main

#define main srtf_main
#include "SRTF.cpp"
#undef main

#define main rr_main
#include "Round_Robin.cpp"
#undef main

#define main multilevel_main
#include "Multilevel_Queue.cpp"
#undef main

int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   CPU PROCESS SCHEDULING SIMULATOR\n";
        cout << "====================================\n";
        cout << "1. FCFS Scheduling\n";
        cout << "2. Priority Scheduling\n";
        cout << "3. SJF Scheduling\n";
        cout << "4. SRTF Scheduling\n";
        cout << "5. Round Robin Scheduling\n";
        cout << "6. Multilevel Queue Scheduling\n";
        cout << "0. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                fcfs_main();
                break;

            case 2:
                priority_main();
                break;

            case 3:
                sjf_main();
                break;

            case 4:
                srtf_main();
                break;

            case 5:
                rr_main();
                break;

            case 6:
                multilevel_main();
                break;

            case 0:
                cout << "Exiting simulator. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Select 0-6.\n";
        }

    } while (choice != 0);

    return 0;
}
