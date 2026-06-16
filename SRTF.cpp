#include <iostream>
using namespace std;

struct Process {
    int id, bt, art, rt, wt, tat;
};

int main() {
    int n, completed = 0, currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    Process p[20];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << p[i].id << ": ";
        cin >> p[i].art >> p[i].bt;
        p[i].rt = p[i].bt; 
    }

    while (completed != n) {
        int shortest = -1;
        int minRT = 9999; // Using a large number instead of INT_MAX

        // Find process with shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].art <= currentTime && p[i].rt > 0 && p[i].rt < minRT) {
                minRT = p[i].rt;
                shortest = i;
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        // Execute for 1 unit of time
        p[shortest].rt--;

        // If process finished
        if (p[shortest].rt == 0) {
            completed++;
            int finishTime = currentTime + 1;
            p[shortest].tat = finishTime - p[shortest].art;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            
            totalWT += p[shortest].wt;
            totalTAT += p[shortest].tat;
        }
        currentTime++;
    }

    cout << "\nPID\tArrival\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t" << p[i].art << "\t" << p[i].bt 
             << "\t" << p[i].wt << "\t" << p[i].tat << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}