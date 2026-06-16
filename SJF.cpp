#include <iostream>
#include <climits>
using namespace std;

struct Process {
    int pid, at, bt, st, ct, tat, wt;
    bool done;
};

void input(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].done = false;
        cout << "Enter AT and BT of P" << p[i].pid << ": ";
        cin >> p[i].at >> p[i].bt;
    }
}

void nonPreemptiveSJF(Process p[], int n) {
    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int minBT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time && p[i].bt < minBT) {
                minBT = p[i].bt;
                idx = i;
            }
        }

        
        if (idx == -1) {
            time++;
            continue;
        }

        p[idx].st = time;
        p[idx].ct = p[idx].st + p[idx].bt;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        time = p[idx].ct;
        p[idx].done = true;
        completed++;
    }
}

void sortByStartTime(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].st > p[j].st) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void display(Process p[], int n) {
    float avgWT = 0, avgTAT = 0;

    cout << "\nPID\tAT\tBT\tST\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].st << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n << endl;
}

void printGantt(Process p[], int n) {
    cout << "\nGantt Chart:\n\n|";

    for (int i = 0; i < n; i++)
        cout << "  P" << p[i].pid << "  |";

    cout << "\n";

    cout << p[0].st << "\t";
    for (int i = 0; i < n; i++)
        cout << p[i].ct << "\t";

    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    input(p, n);
    nonPreemptiveSJF(p, n);

    sortByStartTime(p, n);
    display(p, n);
    printGantt(p, n);

    return 0;
}
