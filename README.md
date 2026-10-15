# CPU Process Scheduling Simulator

A terminal-based **CPU Process Scheduling Simulator written in C++** that demonstrates six fundamental CPU scheduling algorithms studied in Operating Systems. The project calculates scheduling metrics, displays process execution details, and generates Gantt charts where supported.

🚀 **Status:** Active Development

## 📂 Repository Structure

```text
Process-Scheduling-Simulator/
├── FCFS.cpp
├── SJF.cpp
├── SRTF.cpp
├── Priority.cpp
├── RoundRobin.cpp
├── Multilevel_Queue.cpp
├── main.cpp
└── README.md
```

## ✅ Implemented Algorithms

### 1. First Come First Serve (FCFS)

**File:** `FCFS.cpp`

- Executes processes in order of arrival time.
- Calculates Start Time (ST), Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT).
- Handles CPU idle periods.
- Displays average waiting and turnaround times.
- Generates a Gantt chart.

### 2. Shortest Job First (SJF) — Non-Preemptive

**File:** `SJF.cpp`

- Selects the shortest available process.
- Once started, a process executes until completion.
- Considers process arrival times.
- Calculates ST, CT, TAT, and WT.
- Displays average waiting and turnaround times.

### 3. Shortest Remaining Time First (SRTF)

**File:** `SRTF.cpp`

- Preemptive version of SJF.
- Selects the ready process with the shortest remaining execution time.
- Supports process preemption.
- Calculates completion, turnaround, and waiting times.
- Displays average waiting and turnaround times.

### 4. Priority Scheduling

**File:** `Priority.cpp`

- Implements non-preemptive priority scheduling.
- Selects the highest-priority process among the available processes.
- Uses a smaller priority number to represent higher priority.
- Calculates ST, CT, TAT, and WT.
- Displays average waiting and turnaround times.

### 5. Round Robin (RR)

**File:** `RoundRobin.cpp`

- Uses a user-defined time quantum.
- Allocates CPU time slices to processes in cyclic order.
- Calculates completion, turnaround, and waiting times.
- Displays average waiting and turnaround times.
- Produces a Gantt chart.

### 6. Multilevel Queue Scheduling

**File:** `Multilevel_Queue.cpp`

- Divides processes into two separate queues.
- **Queue 1:** Higher-priority queue using Round Robin scheduling.
- **Queue 2:** Lower-priority queue using FCFS scheduling.
- Uses a configurable time quantum for Queue 1.
- Displays queue assignments and scheduling metrics.
- Generates an execution timeline.

The Multilevel Queue implementation uses a simplified policy in which all processes arrive at time zero and Queue 1 executes before Queue 2.

## 🖥️ Integrated Terminal Simulator

**File:** `main.cpp`

The integrated simulator provides an interactive menu for selecting any of the six scheduling algorithms.

```text
====================================
   CPU PROCESS SCHEDULING SIMULATOR
====================================
1. FCFS Scheduling
2. Priority Scheduling
3. SJF Scheduling
4. SRTF Scheduling
5. Round Robin Scheduling
6. Multilevel Queue Scheduling
0. Exit
------------------------------------
Enter your choice:
```

Users can select an algorithm, provide the required process information, and view the corresponding scheduling results.

## ⚙️ Requirements

- C++ compiler supporting C++17 or later
- GCC / G++ or MinGW
- Terminal or command-line interface

## ▶️ How to Compile and Run

### Run the integrated simulator

Compile the integrated `main.cpp` file:

```bash
g++ -std=c++17 main.cpp -o simulator
```

Run on Linux or macOS:

```bash
./simulator
```

Run on Windows:

```powershell
.\simulator.exe
```

**Note:** The integrated simulator must use compatible algorithm functions and data structures. Do not compile multiple standalone `.cpp` files together when each contains its own `main()` function.

### Run individual algorithms

Compile and execute each algorithm independently.

**FCFS**

```bash
g++ -std=c++17 FCFS.cpp -o fcfs
./fcfs
```

**SJF**

```bash
g++ -std=c++17 SJF.cpp -o sjf
./sjf
```

**SRTF**

```bash
g++ -std=c++17 SRTF.cpp -o srtf
./srtf
```

**Priority Scheduling**

```bash
g++ -std=c++17 Priority.cpp -o priority
./priority
```

**Round Robin**

```bash
g++ -std=c++17 RoundRobin.cpp -o rr
./rr
```

**Multilevel Queue**

```bash
g++ -std=c++17 Multilevel_Queue.cpp -o multilevel_queue
./multilevel_queue
```

On Windows, execute the generated `.exe` files instead.

## 📊 Scheduling Metrics

The simulator uses the following standard Operating Systems metrics:

| Metric | Description |
|---|---|
| AT | Arrival Time |
| BT | Burst Time |
| ST | First Start Time |
| CT | Completion Time |
| TAT | Turnaround Time = CT − AT |
| WT | Waiting Time = TAT − BT |

Average Waiting Time:

```text
Average WT = Sum of Waiting Times / Number of Processes
```

Average Turnaround Time:

```text
Average TAT = Sum of Turnaround Times / Number of Processes
```

## 🎯 Learning Objectives

This project demonstrates:

- CPU scheduling and process execution order.
- Preemptive versus non-preemptive scheduling.
- Process arrival and burst times.
- Waiting time and turnaround time calculations.
- Time quantum and Round Robin scheduling.
- Priority-based scheduling.
- Multilevel Queue scheduling.
- Gantt charts and algorithm performance comparison.

## 🔜 Future Improvements

- Compare all scheduling algorithms using identical input processes.
- Add response time and CPU utilization metrics.
- Improve Gantt chart formatting.
- Support exporting scheduling results to CSV.
- Add additional scheduling algorithms.
- Introduce automated test cases for scheduling calculations.

## 🤝 Contributing

Contributions, bug reports, suggestions, and improvements are welcome. Feel free to fork the repository and submit a pull request.

## 📄 License

This project is intended for educational purposes and Operating Systems practice. Add a `LICENSE` file if you wish to distribute it under a specific open-source license.
