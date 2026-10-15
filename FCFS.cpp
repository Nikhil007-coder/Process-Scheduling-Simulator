
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid, at, bt, st, ct, tat, wt;
};

bool compare(Process a, Process b) {
    if (a.at == b.at)
        return a.pid < b.pid;
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    if (!(cin >> n) || n <= 0 || n > 100) {
        cout << "Invalid process count.\n";
        return 1;
    }

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time of P"
             << p[i].pid << ": ";

        if (!(cin >> p[i].at >> p[i].bt) ||
            p[i].at < 0 || p[i].bt <= 0) {
            cout << "Invalid input.\n";
            return 1;
        }
    }

    sort(p.begin(), p.end(), compare);

    int time = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nGantt Chart:\n|";

    for (auto& x : p) {
        if (time < x.at) {
            cout << " IDLE |";
            time = x.at;
        }

        x.st = time;
        x.ct = time + x.bt;
        x.tat = x.ct - x.at;
        x.wt = x.tat - x.bt;
        time = x.ct;

        cout << " P" << x.pid << " |";
    }

    cout << "\n\nPID\tAT\tBT\tST\tCT\tTAT\tWT\n";

    for (const auto& x : p) {
        cout << "P" << x.pid << "\t"
             << x.at << "\t" << x.bt << "\t"
             << x.st << "\t" << x.ct << "\t"
             << x.tat << "\t" << x.wt << "\n";

        totalWT += x.wt;
        totalTAT += x.tat;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
