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

	return Scheduler::time_to_switch_processes;
}

void Scheduler_SRTF::sort() {

}


