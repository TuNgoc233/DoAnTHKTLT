#include "Header.h"

int main() {
	string cmd;
	node phead = NULL, ptail = NULL;
	stack<string> command_history;
	Output_Command(phead, ptail, cmd, command_history);
	return 0;
}
