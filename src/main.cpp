#include <stdio.h>
#include <stdlib.h>
#include <visa.h>
#include <windows.h>
#include <sigGenClass.h>
//#include <visaInstrument.h>

SignalGenerator gen1;

int initialization(void)
{

	gen1.Initialize("USB0::0x0400::0x09C4::DG1D182403421::INSTR");
	if(gen1.getViStatus() != VI_SUCCESS)
	{
		printf("Initialization failed\n");
		return EXIT_FAILURE;
	}
	else	printf("Opened Signal Generator\n");

	return 0;
}

int setup(void)
{
	gen1.setUnit(0);
	if(gen1.getViStatus() != VI_SUCCESS)
	{
		printf("Invalid unit entry\n");
		return EXIT_FAILURE;
	}
	//gen1.generateSin(20000, 10, 2.5, 0.5);
	gen1.sinSweep(100, 20000, 2);
	if(gen1.getViStatus() != VI_SUCCESS)
	{
		printf("Invalid sine sweep entry\n");
		return EXIT_FAILURE;
	}
	gen1.output(1);
	if(gen1.getViStatus() != VI_SUCCESS)
	{
		printf("Invalid output entry\n");
		return EXIT_FAILURE;
	}

	return 0;
}

int loop(void)
{
	return 0;
}

int main(void)
{
	int r=0;
	r=initialization();
	if(!r) r = setup();
	if(!r) r = loop();
	return(0);
}