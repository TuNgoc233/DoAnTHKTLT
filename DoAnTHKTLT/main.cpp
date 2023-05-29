#include "Header.h"

int main() {
	node phead = NULL, ptail = NULL;
	ReadFile(phead, ptail);
	Output_List(phead);
	while (true) {
		int chose;
		cin >> chose;
		if (chose == 1) {
			int pos;
			cin >> pos;
			deleteAt(phead, ptail, pos);
			Output_List(phead);
		}
		else if (chose == 2) {
			int pos, x;
			cin >> pos;
			cin >> x;
			insertAt(phead, ptail, x, pos);
			Output_List(phead);
		}
		else if (chose == 3) {
			undo();
		}

	}
	return 0;
}