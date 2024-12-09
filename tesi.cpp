#include "TestStateMachine.h"
int main() {
	TestStateMachine machine;
	while (true) machine.update();
	return 0;
}