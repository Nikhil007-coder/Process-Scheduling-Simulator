#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Burst Time of each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;

        cout << "P" << i + 1 << ": ";
        cin >> processes[i].burstTime;

        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int currentTime = 0;
    bool done;

    do {
        done = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                done = false;

                if (processes[i].remainingTime > quantum) {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    currentTime += processes[i].remainingTime;

                    processes[i].turnaroundTime = currentTime;
                    processes[i].waitingTime =
                        processes[i].turnaroundTime - processes[i].burstTime;

                    processes[i].remainingTime = 0;
                }
            }
        }

    } while (!done);

    double avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].pid << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].waitingTime << "\t"
             << processes[i].turnaroundTime << endl;

        avgWT += processes[i].waitingTime;
        avgTAT += processes[i].turnaroundTime;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n << endl;
    cout << "Average Turnaround Time = " << avgTAT / n << endl;

    return 0;
}