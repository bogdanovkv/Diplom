#include "sevenSegmentsTests.h"
#include "keyboardTests.h"

int main() 
{
	initSegmentIndicator();
	initKeyboard();
		clear();

	while(1)
	{
		startKeyboardTracking();
	}
}
