/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"



PCB Dispatcher::get_from_CPU() {
	return PCB();
}

void Dispatcher::put_on_CPU(PCB &process) {

}

bool Dispatcher::isValidJobOnCPU() {
	return false;
}
