/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();

	int time_remaining = ready_q->front().remaining_cpu_time;

	if (time_remaining < 0 || time_remaining < p.remaining_cpu_time)
		return true;

	return Scheduler::time_to_switch_processes(tick_count, p);
}

struct compare_remaining_time {
	bool operator()(PCB x, PCB y) {
		return x.remaining_cpu_time > y.remaining_cpu_time;
	}
};

void Scheduler_SRTF::sort() {
	std::priority_queue<PCB, std::vector<PCB>, compare_remaining_time> sorted;

	while (!ready_q->empty()) {
		sorted.push(ready_q->front());
		ready_q->pop();
	}

	while (!sorted.empty()) {
		ready_q->push(sorted.top());
		sorted.pop();
	}
}

