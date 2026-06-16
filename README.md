# Process-Scheduling-Simulator

This directory contains implementations of **CPU scheduling algorithms**
written in **C++** as part of Operating Systems learning and practice.

🚧 **Status:** Work in Progress  
More scheduling algorithms will be added progressively.

---

## 📂 Folder Structure
cpu_scheduling/
├── FCFS.cpp
├── SJF.cpp
├── SRTF.cpp
├── Priority.cpp
└── README.md


---

## ✅ Implemented Algorithms

### 1️⃣ First Come First Serve (FCFS)

* Schedules processes based on arrival time.
* Calculates Start Time (ST), Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT).
* Displays average WT and TAT.
* Generates a Gantt Chart and handles CPU idle time.

### 2️⃣ Shortest Job First (SJF) – Non-Preemptive

* Selects the process with the shortest burst time among available processes.
* Executes processes non-preemptively.
* Calculates CT, TAT, and WT.
* Displays average WT and TAT.
* Generates a Gantt Chart.

### 3️⃣ Shortest Remaining Time First (SRTF)

* Preemptive version of SJF.
* Continuously selects the process with the shortest remaining burst time.
* Supports process preemption on arrival of shorter jobs.
* Calculates CT, TAT, and WT.
* Generates a Gantt Chart and performance statistics.

### 4️⃣ Priority Scheduling

* Schedules processes according to assigned priority levels.
* Higher-priority processes are executed first.
* Calculates CT, TAT, and WT.
* Displays average WT and TAT.
* Generates a Gantt Chart for process execution visualization.


## 🔜 Planned Algorithms

### Round Robin (RR)

### Multilevel Queue Scheduling





### 🚀 How to Run

Compile and execute any scheduling algorithm using g++:

```bash
g++ FCFS.cpp -o fcfs
./fcfs

g++ SJF.cpp -o sjf
./sjf

g++ SRTF.cpp -o srtf
./srtf

g++ Priority.cpp -o priority
./priority
```

### Requirements

* C++ Compiler (g++)
* Terminal or Command Prompt

Each program accepts process details as input and displays the scheduling table, performance metrics, and Gantt Chart.

