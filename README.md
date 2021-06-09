# CPU-Scheduling
FCFS - First Come First Serve CPU Scheduling

    The process which arrives first in the ready queue is firstly assigned the CPU.
    In case of a tie, process with smaller process id is executed first.
    It is always non-preemptive in nature.
    
SJF | SRTF - Shortest Job First | Shortest Remaining Time First   CPU Scheduling

    Out of all the available processes, CPU is assigned to the process having smallest burst time.
    In case of a tie, it is broken by FCFS Scheduling.
    SJF Scheduling can be used in both preemptive and non-preemptive mode.
    Preemptive mode of Shortest Job First is called as Shortest Remaining Time First (SRTF).

Priority Scheduling- Preemptive and Non-Preemptive

    Out of all the available processes, CPU is assigned to the process having the highest priority.
    In case of a tie, it is broken by FCFS Scheduling
    Priority Scheduling can be used in both preemptive and non-preemptive mode.
 
 Round Robin Scheduling

    CPU is assigned to the process on the basis of FCFS for a fixed amount of time.
    This fixed amount of time is called as time quantum or time slice.
    After the time quantum expires, the running process is preempted and sent to the ready queue.
    Then, the processor is assigned to the next arrived process.
    It is always preemptive in nature.


 

