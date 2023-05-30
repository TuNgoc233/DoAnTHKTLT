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
void deleteAt(node& head, node& tail, int pos) {
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
void insertAt(node& head, node& tail, int x, int pos) {
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
void Reverse(node& head, node& tail)
{
	if (head == NULL) return;
	if (head == tail) return;
	node previous = NULL;
	node current = head;
	node next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

//Sap xep danh sach theo thu tu tang dan
void Sort(node& head)
{
	node i;
	for (i = head;i;i = i->next)
	{
		node min = i;
		for (node j = i->next;j;j = j->next)
			if (min->data > j->data)
				min = j;
		int temp = min->data;
		min->data = i->data;
		i->data = temp;
	}
}

//Xoa cac phan tu trung nhau trong danh sach
void RemoveDuplicates(node head)
{
	node i = head;
	node j, q;
	while (i != NULL && i->next != NULL)
	{
		j = i;
		while (j->next != NULL)
		{
			if (i->data == j->next->data)
			{
				q = j->next;
				j->next = j->next->next;
				delete q;
			}
			else j = j->next;
		}
		i = i->next;
	}
}

// Hàm thực hiện lệnh undo
void undo() {
	if (!command_history.empty()) {
		vector<int> sequence;
		string command = command_history.top(); // Lấy lệnh cuối cùng từ stack command_history
		command_history.pop(); // Xóa lệnh đã lấy ra
		undo_history.push(command); // Di chuyển lệnh vào stack undo_history
		execute_reverse_command(command, sequence); // Thực hiện lệnh đảo ngược
	}
}

// Hàm thực hiện lệnh redo
void redo() {
	if (!undo_history.empty()) {
		vector<int> sequence;
		string command = undo_history.top(); // Lấy lệnh cuối cùng từ stack undo_history
		undo_history.pop(); // Xóa lệnh đã lấy ra
		command_history.push(command); // Di chuyển lệnh vào stack command_history
		execute_command(command, sequence); // Thực hiện lệnh
	}
} 

// Hàm thực hiện lệnh
void execute_command(string command, vector<int>& sequence) {
    stringstream ss(command);
    string operation;
    ss >> operation;

    if (operation == "delete") {
        int pos;
        ss >> pos;
        if (pos >= 1 && pos <= sequence.size()) {
            sequence.erase(sequence.begin() + pos - 1); // Xóa node tại vị trí pos trong danh sách
        } else {
            cout << "Invalid position.\n";
        }
    } else if (operation == "insert") {
        int pos, val;
        ss >> pos >> val;
        if (pos >= 1 && pos <= sequence.size() + 1) {
            sequence.insert(sequence.begin() + pos - 1, val); // Chèn node có giá trị val vào vị trí pos trong danh sách
        } else {
            cout << "Invalid position.\n";
        }
    } else {
        cout << "Invalid command.\n";
    }
}

// Hàm thực hiện lệnh đảo ngược
void execute_reverse_command(string command, vector<int>& sequence) {
    stringstream ss(command);
    string operation;
    ss >> operation;

    if (operation == "delete") {
        int pos, val;
        ss >> pos >> val;
        if (pos >= 1 && pos <= sequence.size() + 1) {
            sequence.insert(sequence.begin() + pos - 1, val); // Chèn node có giá trị val vào vị trí pos trong danh sách
        } else {
            cout << "Invalid position.\n";
        }
    } else if (operation == "insert") {
        int pos;
        ss >> pos;
        if (pos >= 1 && pos <= sequence.size()) {
            sequence.erase(sequence.begin() + pos - 1); // Xóa node tại vị trí pos trong danh sách
        } else {
            cout << "Invalid position.\n";
        }
    } else {
        cout << "Invalid command.\n";
    }
}

