/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"
using namespace std;

Stats::Stats(vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time=0.2;
	av_turnaround_time=0.4;
	av_response_time=0.6;
}

void Stats::showAllProcessInfo() {
	for (PCB p : *vec) {
		cout<<"Process "<<p.process_number
				<<"  Required CPU Time: "<<p.required_cpu_time
				<<"  Arrival Time: "<<p.arrival_time
				<<"  Start Time: "<<p.start_time
				<<"  Finish Time: "<<p.finish_time<<endl;
	}
}

float Stats::get_av_response_time() {
	float num = 0;

	for (PCB p : *vec) {
		num += p.start_time - p.arrival_time;
	}

	float av_response_time = num/vec->size();
	return av_response_time;
}

float Stats::get_av_turnaround_time() {
	float num = 0;

	for (PCB p : *vec) {
		num += p.finish_time - p.arrival_time;
	}

	float av_turnaround_time = num/vec->size();
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	float num = 0;

	for (PCB p : *vec) {
		num += p.finish_time - p.arrival_time - p.required_cpu_time;
	}

	float av_wait_time = num/vec->size();
	return av_wait_time;
}
