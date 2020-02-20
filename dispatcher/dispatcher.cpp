/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"


PCB Dispatcher::get_from_CPU() {
	if (!isValidJobOnCPU())
		return PCB();

	return cpu->get_process_off_core();
}

void Dispatcher::put_on_CPU(PCB &process) {
	if(!isValidJobOnCPU())
		cpu->put_process_on_core(process);
}

bool Dispatcher::isValidJobOnCPU() {
	is_valid_job_on_cpu = !cpu->get_COPY_of_Current_Process().isEmpty();
	return is_valid_job_on_cpu;
}
