#include "Header.h"

int main() {
	node phead = NULL, ptail = NULL;
	string cmd;
	ReadFile(phead, ptail);
	Output_List(phead);
	while (true) {
		cout << "Command > ";
		getline(cin,cmd);
		while(cmd == "delete") {
			cout << "command is *delete position*\n";
			cout << "Command > ";
			getline(cin, cmd);
		}
		if (cmd.substr(0, 6) == "delete") {
			string s1 = cmd.substr(7);
			int x = stoi(s1);
			deleteAt(phead, ptail, x);
			Output_List(phead);
		}

		if(cmd=="sort") {
			Sort(phead);
			Output_List(phead);
		}
		if(cmd=="reverse") {
			Reverse(phead,ptail);
			Output_List(phead);
		}
		if(cmd=="remove duplicates") {
			RemoveDuplicates(phead);
			Output_List(phead);
		}
				while (cmd == "insert") {
			cout << "command is *insert position value*\n";
			cout << "Command > ";
			getline(cin, cmd);
		}

		if (cmd.substr(0, 6) == "insert") {
			int dodai1 = 0;
			for (int i = 7; i <cmd.length(); i++) {
				if (cmd[i] == ' ') {
					dodai1 = i - 7;
					break;
				}
			}
			string s1 = cmd.substr(7, dodai1);
			int x = stoi(s1);
			int dodai2 = 0;
			dodai2 = cmd.size() - 9;
			string s2 = cmd.substr(9, dodai2);
			int y = stoi(s2);
			insertAt(phead, ptail, y, x-1);
			Output_List(phead);
		}
		if (cmd == "save") {
			Save_List(phead);
			cout << "Numbers have been stored." << endl;
		}
		if (cmd == "quit") {
			break;
		}

		/*int chose;
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
		if (chose == 3) {
			Reverse(phead,ptail);
			Output_List(phead);
		}
		if (chose == 4) {
			Sort(phead);
			Output_List(phead);
		}
		if (chose == 5) {
			RemoveDuplicates(phead);
			Output_List(phead);
		}*/

	}
	return 0;
}
