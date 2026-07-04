# Process Scheduling Simulator

This repository contains implementations of **CPU Scheduling Algorithms** written in **C++** as part of Operating Systems learning and practice.

🚀 **Status:** Active Development

---

## 📂 Folder Structure

```text
cpu_scheduling/
├── FCFS.cpp
├── SJF.cpp
├── SRTF.cpp
├── Priority.cpp
├── RoundRobin.cpp
└── README.md
```

---

## ✅ Implemented Algorithms

### 1️⃣ First Come First Serve (FCFS)

**File:** `FCFS.cpp`

- Schedules processes based on arrival time
- Calculates Start Time (ST), Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
- Displays Average WT & Average TAT
- Generates Gantt Chart
- Handles CPU Idle Time

---

### 2️⃣ Shortest Job First (SJF) – Non-Preemptive

**File:** `SJF.cpp`

- Selects the process with the shortest burst time
- Non-preemptive execution
- Calculates ST, CT, TAT, and WT
- Displays Average WT & Average TAT
- Generates Gantt Chart

---

### 3️⃣ Shortest Remaining Time First (SRTF)

**File:** `SRTF.cpp`

- Preemptive version of SJF
- Selects the process with the shortest remaining burst time
- Supports process preemption
- Calculates CT, TAT, and WT
- Displays Average WT & Average TAT
- Generates Gantt Chart

---

### 4️⃣ Priority Scheduling

**File:** `Priority.cpp`

- Schedules processes based on priority
- Calculates CT, TAT, and WT
- Displays Average WT & Average TAT
- Generates Gantt Chart

---

### 5️⃣ Round Robin (RR)

**File:** `RoundRobin.cpp`

- Executes processes using a user-defined Time Quantum
- Fair CPU allocation among all processes
- Calculates CT, TAT, and WT
- Displays Average WT & Average TAT
- Generates Gantt Chart

---

## 🔜 Planned Algorithms

- Multilevel Queue Scheduling

---

## ▶️ How to Run

### FCFS

```bash
g++ FCFS.cpp -o fcfs
./fcfs
```

### SJF

```bash
g++ SJF.cpp -o sjf
./sjf
```

### SRTF

```bash
g++ SRTF.cpp -o srtf
./srtf
```

### Priority Scheduling

```bash
g++ Priority.cpp -o priority
./priority
```

### Round Robin

```bash
g++ RoundRobin.cpp -o rr
./rr
```

---

## 📌 Future Improvements

- Interactive menu-driven simulator
- Better Gantt Chart visualization
- Performance comparison between scheduling algorithms
- Export scheduling results

---

## 🤝 Contributing

Contributions, suggestions, and improvements are welcome. Feel free to fork the repository and submit a pull request.
