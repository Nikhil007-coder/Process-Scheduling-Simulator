
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

struct Process {
    int pid, at, bt, rt, st, ct, tat, wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";

    if (!(cin >> n) || n <= 0 || n > 100)
        return 1;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        cout << "Enter AT and BT of P" << i + 1 << ": ";

        if (!(cin >> p[i].at >> p[i].bt) ||
            p[i].at < 0 || p[i].bt <= 0)
            return 1;

        p[i].rt = p[i].bt;
        p[i].st = -1;
    }

    int time = 0, completed = 0;
    double totalWT = 0, totalTAT = 0;

    while (completed < n) {
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at > time || p[i].rt <= 0)
                continue;

            if (idx == -1 ||
                p[i].rt < p[idx].rt ||
                (p[i].rt == p[idx].rt &&
                 p[i].at < p[idx].at) ||
                (p[i].rt == p[idx].rt &&
                 p[i].at == p[idx].at &&
                 p[i].pid < p[idx].pid)) {
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        if (p[idx].st == -1)
            p[idx].st = time;

        p[idx].rt--;
        time++;

        if (p[idx].rt == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        }
    }

    cout << "\nPID\tAT\tBT\tST\tCT\tTAT\tWT\n";

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
