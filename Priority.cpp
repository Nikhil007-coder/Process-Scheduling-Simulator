#include <iostream>
using namespace std;

struct Process {
    int id,bt,pr,wt,tat;
};

int main() {
    int n;
    Process p[20], temp;
    float avg_wt = 0, avg_tat = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Burst Time and Priority for P" << p[i].id << ": ";
        cin >> p[i].bt >> p[i].pr;
    }

    // Sort processes based on Priority (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].pr > p[j + 1].pr) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculation
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Output Table
    cout << "\nPID\tBT\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
        cout << "P" << p[i].id << "\t" << p[i].bt << "\t" << p[i].pr 
             << "\t\t" << p[i].wt << "\t" << p[i].tat << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_wt / n;
    cout << "\nAverage Turnaround Time: " << avg_tat / n << endl;

    return 0;
}