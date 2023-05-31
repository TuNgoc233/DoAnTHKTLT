#include "Header.h"


//Khoi tao
void Init(node& head, node& tail) {
	head = tail = NULL;
}

//Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;//nullptr
	return tmp;
}

//Kiem tra rong
bool IsEmpty(node head) {
	return head == NULL;
}

//Dem so luong node trong danh sach
int Size(node head) {
	int cnt = 0;
	while (head != NULL)
	{
		++cnt;
		head = head->next;//gan dia chi cua node tiep theo cho node hien tai
		//cho node hien tai nhay toi node phia sau
	}
	return cnt;
}

//Duyet danh sach
void Output_List(node head) {
	node p = head;
	if (p == NULL)
		cout << "\nDanh sach bi rong\n";
	cout << "LIST PROCESSING: ";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//Them 1 phan tu vao cuoi danh sach
void insertLast(node& head, node& tail, int x) {
	node tmp = makeNode(x);
	if (head == NULL) {
		head = tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
}

//Doc file input.txt
void ReadFile(node& head, node& tail) {
	fstream input("input.txt", ios::in);
	if (input.fail()) {
		cout << "Doc input.txt khong thanh cong" << endl;
		return;
	}
	head = NULL;
	int x;
	while (input >> x) {
		insertLast(head, tail, x);
	}
	input.close();
}

//Xoa phan tu o dau
void deleteFirst(node& head, node& tail) {
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		node q = head;
		head = head->next;
		free(q);
	}
}

//Xoa phan tu o cuoi
void deleteLast(node& head, node& tail) {
	node q;
	if (head == tail) {
		free(head);
		head = tail = NULL;
	}
	else {
		for (q = head; q->next != tail; q = q->next);
		free(tail);
		tail = q;
		q->next = NULL;
	}
}

//Xoa o giua
void deleteMid(node& head, node q) {
	node r = q->next;
	*q = *r;
	free(r);
}

//Xoa phan tu tai 1 vi tri xac dinh
void deleteAt(node& head, node& tail, int pos, string command, stack<string>& command_history) {
	int i;
	node q;
	for (i = 1, q = head; i <= pos; i++, q = q->next);
	int val = q->data;
	string str = "delete " + to_string(pos+1) + " " + to_string(val);
	command_history.push(str);
	int n = 0;
	n = Size(head);
	if ((pos < 0) || (pos >= n)) {
		cout << "Vi tri xoa khong phu hop\n";
		return;
	}
	if (pos == 0)
		deleteFirst(head, tail);
	else if (pos == n - 1) {
		deleteLast(head, tail);
	}
	else {
		node q;
		int i;
		for (i = 0, q = head; i < pos; i++, q = q->next);
		if (q->next == tail)
			tail = q;
		deleteMid(head, q);
	}
}

void Save_List(node head) {
	fstream output;
	output.open("output.txt", ios::out);
	if (output.fail()) {
		cout << "Mo output.txt khong thanh cong\n";
		return;
	}
	node p = head;
	if (p == NULL)
		return;
	while (p != NULL)
	{
		output << p->data << " ";
		p = p->next;
	}
}

//Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node& head, node& tail, int x) {
	node tmp = makeNode(x);
	if (head == NULL) {
		head = tail = tmp;
	}
	else {
		tmp->next = head;
		head = tmp;
	}
}

//Them phan tu vao sau 1 phan tu nao do trong danh sach
void insertAfter(node q, int k) {
	node p = makeNode(k);
	p->next = q->next;
	q->next = p;
}

//Them phan tu vao truoc mot phan tu nao do trong danh sach 
void insertBefore(node q, int k) {
	node p = new Node;
	*p = *q;
	q->next = p;
	q->data = k;
}

//Chen 1 node co gia tri x tai mot vi tri xac dinh trong danh sach
void insertAt(node& head, node& tail, int x, int pos, string command, stack<string>& command_history) {
	string s = "insert " + to_string(pos+1) + " " + to_string(x);
	command_history.push(s);
	int n = Size(head);
	if (pos < 0 || pos > n) {
		cout << "Vi tri chen khong hop le!" << endl;
		return;
	}
	if (pos == 0) {
		insertFirst(head, tail, x); return;
	}
	else if (n == pos) {
		insertLast(head, tail, x); return;
	}
	else {
		node q;
		int i;
		for (i = 0, q = head; i < pos; i++, q = q->next);
		insertBefore(q, x);
		if (tail->next)
			tail = tail->next;
	}
}

//Dao nguoc danh sach
void Reverse(node& head, string command, stack<string>& command_history)
{
	node p1 = head;
	string str1 = "reverse";
	while (p1 != NULL)
	{
		str1 += " " + to_string(p1->data);
		p1 = p1->next;
	}
	command_history.push(str1);
	if (head == NULL || head->next == NULL) {
		return; // danh sach da duoc sort san chi co 1 phan tu duy nhat
	}
	node p, q, prev_p = NULL;

	// sap xep danh sach bang thuat toan sap xep 
	for (p = head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; prev_p = q, q = q->next) {
			int tmp = p->data;
			p->data = q->data;
			q->data = tmp;
		}
	}
} 


//Sap xep danh sach theo thu tu tang dan
void Sort(node& head, string command, stack<string>& command_history)
{
	node p1 = head;
	string str1 = "sort";
	while (p1 != NULL)
	{
		str1 += " " + to_string(p1->data);
		p1 = p1->next;
	}
	command_history.push(str1);
	if (head == NULL || head->next == NULL) {
		return; // danh sach da duoc sort san chi co 1 phan tu duy nhat
	}
	node p, q, prev_p = NULL;

	// sap xep danh sach bang thuat toan sap xep 
	for (p = head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; prev_p = q, q = q->next) {
			if (p->data > q->data) {
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}

// Hàm thực hiện lệnh undo
void undo(node&head, node&tail, stack<string>& command_history,stack<string>& undo_history) {
	if (!command_history.empty()) {
		string command = command_history.top(); // Lấy lệnh cuối cùng từ stack command_history
		command_history.pop(); // Xóa lệnh đã lấy ra
		undo_history.push(command); // Di chuyển lệnh vào stack undo_history
		execute_reverse_command(command, head, tail); // Thực hiện lệnh đảo ngược
	}
}

// Hàm thực hiện lệnh redo
void redo(node&head, node&tail, stack<string>& command_history, stack<string>& undo_history) {
	if (!undo_history.empty()) {
		string command = undo_history.top(); // Lấy lệnh cuối cùng từ stack undo_history
		undo_history.pop(); // Xóa lệnh đã lấy ra
		command_history.push(command); // Di chuyển lệnh vào stack command_history
		execute_command(command, head, tail); // Thực hiện lệnh
	}
} 

// Hàm thực hiện lệnh
void execute_command(string command, node&head, node&tail) {
	stack<string>command_history;
    stringstream ss(command);
    string operation;
    ss >> operation;
    if (operation == "delete") {
        int pos;
        ss >> pos;
		deleteAt(head, tail, pos-1, command, command_history);
    } else if (operation == "insert") {
        int pos, val;
        ss >> pos >> val;
		insertAt(head, tail, val, pos-1, command, command_history);
    } 
	else if (operation == "sort") {
		Sort(head, command, command_history);
	}
	else if (operation == "reverse") {

		Reverse(head, command,command_history);
	}
	else {
        cout << "Invalid command.\n";
    }
}

// Hàm thực hiện lệnh đảo ngược
void execute_reverse_command(string command, node&head, node&tail) {
	stack<string>command_history;
    stringstream ss(command);
    string operation;
    ss >> operation;
    if (operation == "delete") {
        int pos, val;
        ss >> pos >> val;
		insertAt(head, tail, val, pos-1, command, command_history);
    } else if (operation == "insert") {
        int pos;
        ss >> pos;
		deleteAt(head, tail, pos-1, command, command_history);
    }
	else if (operation == "sort") {
		node p = head;			
		while (p != NULL) {
			while (ss >> operation) {
				p->data = stoi(operation);
				p = p->next;
			}
		}
	}
	else if (operation == "reverse") {
		node p = head;
		while (p != NULL) {
			while (ss >> operation) {
				p->data = stoi(operation);
				p = p->next;
			}
		}
	}
	else {
        cout << "Invalid command.\n";
    }
} 

