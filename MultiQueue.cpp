
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt, rt, queue;
    int wt = 0, tat = 0;
};

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";

    if (!(cin >> n) || n <= 0 || n > 100)
        return 1;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        cout << "Enter Burst Time of P" << i + 1 << ": ";
        if (!(cin >> p[i].bt) || p[i].bt <= 0)
            return 1;

        cout << "Enter Queue (1 = High, 2 = Low): ";
        if (!(cin >> p[i].queue) ||
            (p[i].queue != 1 && p[i].queue != 2))
            return 1;

        p[i].rt = p[i].bt;
    }

    cout << "Enter Queue 1 Time Quantum: ";

    if (!(cin >> quantum) || quantum <= 0)
        return 1;

    int time = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n";

    // Queue 1: Round Robin.
    while (true) {
        bool unfinished = false;

        for (auto& x : p) {
            if (x.queue != 1 || x.rt == 0)
                continue;

            unfinished = true;

            int start = time;
            int run = min(quantum, x.rt);

            time += run;
            x.rt -= run;

            cout << "| P" << x.pid
                 << " [Q1: " << start << "-" << time << "] ";

            if (x.rt == 0) {
                x.tat = time;
                x.wt = x.tat - x.bt;
                completed++;
            }
        }

        if (!unfinished)
            break;
    }

    // Queue 2: FCFS, preserving input order.
    for (auto& x : p) {
        if (x.queue != 2)
            continue;

        int start = time;

        time += x.bt;
        x.rt = 0;
        x.tat = time;
        x.wt = x.tat - x.bt;
        completed++;

        cout << "| P" << x.pid
             << " [Q2: " << start << "-" << time << "] ";
    }

    cout << "|\n\nPID\tBT\tQueue\tWT\tTAT\n";

    for (const auto& x : p) {
        cout << "P" << x.pid << "\t"
             << x.bt << "\t" << x.queue << "\t"
             << x.wt << "\t" << x.tat << "\n";

        totalWT += x.wt;
        totalTAT += x.tat;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
