/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"
using namespace std;


Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time=0.2;
	av_turnaround_time=0.4;
	av_response_time=0.6;
}

void Stats::showAllProcessInfo() {

}

float Stats::get_av_response_time() {
	return -1;
}

float Stats::get_av_turnaround_time() {
	return -1;
}

float Stats::get_av_wait_time() {
	return -1;
}
