#include <stdio.h>

int main(int argc, char** argv)
{
	
}

/*As of 20200821 there s nothing here
Reason being memory leakage (not tested but obvious in code) for the polynom tools : a malloc is done to create monoms but no free() is done anywhere
*/