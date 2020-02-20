/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"


void Scheduler::add(PCB p) {
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	if (ready_q-> empty())
		return PCB();

	PCB p = ready_q->front();
	ready_q->pop();

	return p;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

//tick_count necessary?
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	return (p.remaining_cpu_time <= 0);
}
