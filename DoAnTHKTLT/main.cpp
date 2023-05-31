#include "Header.h"

int main() {
	stack<string> command_history;
	stack<string> undo_history;
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
			while (cmd.size() == 7) {
				cout << "command is *delete position*\n";
				cout << "Command > ";
				getline(cin, cmd);
			}
			string s1 = cmd.substr(7);
			int x = stoi(s1);
			int i;
			node q;
			for (i = 1, q = phead; i < x; i++, q = q->next);
			int val = q->data;
			string str = "delete " + to_string(x) + " " + to_string(val);
			command_history.push(str);
			deleteAt(phead, ptail, x-1);
			Output_List(phead);
		}
		if(cmd=="sort") {
			node p = phead;
			string str1 = "sort";
			while (p != NULL)
			{
				str1 += " " + to_string(p->data);
				p = p->next;
			}
			command_history.push(str1);
			//undo_history.push(str1);
			Sort(phead);
			Output_List(phead);
			/*p = phead;
			string str2 = "sort";
			while (p != NULL)
			{
				str2 += " " + to_string(p->data);
				p = p->next;
			}*/
		}
		if(cmd=="reverse") {
			node p = phead;
			string str1 = "reverse";
			while (p != NULL)
			{
				str1 += " " + to_string(p->data);
				p = p->next;
			}
			command_history.push(str1);
			Reverse(phead);
			Output_List(phead);
			/*p = phead;
			string str2 = "reverse";
			while (p != NULL)
			{
				str2 += " " + to_string(p->data);
				p = p->next;
			}
			undo_history.push(str2);*/
		}
		if(cmd=="remove duplicates") {
			node p = phead;
			string str1 = "removeduplicates";
			while (p != NULL)
			{
				str1 += " " + to_string(p->data);
				p = p->next;
			}
			command_history.push(str1);
			RemoveDuplicates(phead);
			Output_List(phead);
		}
		while (cmd == "insert") {
			cout << "command is *insert position value*\n";
			cout << "Command > ";
			getline(cin, cmd);
		}
		if (cmd.substr(0, 6) == "insert") {
			while (cmd.size() == 7) {
				cout << "command is *insert position value*\n";
				cout << "Command > ";
				getline(cin, cmd);
			}
			int dodai1 = 0;
			for (int i = 7; i <cmd.length(); i++) {
				if (cmd[i] == ' ') {
					dodai1 = i - 7;
					break;
				}
			}
			while (cmd.size() == 7 + dodai1 + 1) {
				cout << "command is *insert position value*\n";
				cout << "Command > ";
				getline(cin, cmd);
			}
			string s1 = cmd.substr(7, dodai1);
			int x = stoi(s1);
			int dodai2 = 0;
			dodai2 = cmd.size() - 9;
			string s2 = cmd.substr(9, dodai2);
			int y = stoi(s2);
			string s = "insert " + to_string(x) + " " + to_string(y);
			command_history.push(s);
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
		if (cmd == "undo") {
			undo(phead, ptail, command_history,undo_history);
			Output_List(phead);
		}
		if (cmd == "redo") {
			redo(phead, ptail, command_history, undo_history);
			Output_List(phead);
		}
	}
	return 0;
}
