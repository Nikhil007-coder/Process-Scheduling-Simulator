
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process {
    int pid, bt, rt, wt = 0, tat = 0;
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

        p[i].rt = p[i].bt;
    }

    cout << "Enter Time Quantum: ";

    if (!(cin >> quantum) || quantum <= 0)
        return 1;

    int time = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n";

    while (completed < n) {
        for (auto& x : p) {
            if (x.rt == 0)
                continue;

            int run = min(quantum, x.rt);
            int start = time;

            time += run;
            x.rt -= run;

            cout << "| P" << x.pid
                 << " [" << start << "-" << time << "] ";

            if (x.rt == 0) {
                x.tat = time;
                x.wt = x.tat - x.bt;
                completed++;
            }
        }
    }

    cout << "|\n\nPID\tBT\tWT\tTAT\n";

    for (const auto& x : p) {
        cout << "P" << x.pid << "\t"
             << x.bt << "\t" << x.wt << "\t"
             << x.tat << "\n";

        totalWT += x.wt;
        totalTAT += x.tat;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
