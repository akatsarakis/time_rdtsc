#include "time_rdtsc.h"
#define LATENCY_IN_MS 1000
//Latency enhancement

int main(int argc, char *argv[])
{
	// Call init_rdtsc for initialization 
	init_rdtsc(1, 0);  // either auto calibration 
	init_rdtsc(0, RDTSC_TYPICAL_TICKS_PER_NS); // or by passing TYPICAL TICKS OF PROC PER NS

	struct timespec timer;
	get_rdtsc_timespec(&timer); //Initialize with current time
	
	for(;;)
		if(time_elapsed_in_ms(timer) > LATENCY_IN_MS) // Note: _ns & _sec functions are similarly
		{
			get_rdtsc_timespec(&timer); // Reset timer
			printf("Atleast %d ms have passed!\n", LATENCY_IN_MS);
		}
}
