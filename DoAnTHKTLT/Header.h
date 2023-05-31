#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
typedef struct Node* node;

//Khoi tao
void Init(node& head, node& tail);
//Cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x);
//Doc file input.txt
void ReadFile(node& head, node& tail);
//Kiem tra rong
bool IsEmpty(node head);
//Duyet danh sach
void Output_List(node head);
//Them 1 phan tu vao cuoi danh sach
void insertLast(node& head, node& tail, int x);
//Them 1 phan tu vao dau danh sach lien ket
void insertFirst(node& head, node& tail, int x);
//Xoa phan tu o dau
void deleteFirst(node& head, node& tail);
//Xoa phan tu o cuoi
void deleteLast(node& head, node& tail);
//Xoa o giua
void deleteMid(node& head, node q);
//Xoa phan tu tai 1 vi tri xac dinh
void deleteAt(node& head, node& tail, int pos,string command, stack<string>& command_history);
//Them phan tu vao sau 1 phan tu nao do trong danh sach
void insertAfter(node q, int k);
//Them phan tu vao truoc mot phan tu nao do trong danh sach 
void insertBefore(node q, int k);
//Chen 1 node co gia tri x tai mot vi tri xac dinh trong danh sach
void insertAt(node& head, node& tail, int x, int pos, string command, stack<string>& command_history);
//Dao nguoc danh sach
void Reverse(node& head, string command, stack<string>& command_history);
//Sap xep danh sach theo thu tu tang dan
void Sort(node& head, string command, stack<string>& command_history);
//Xoa cac phan tu trung nhau trong danh sach
void RemoveDuplicates(node& head);
//Luu danh sach vao file output.txt
void Save_List(node head);
// Hàm thực hiện lệnh redo
void redo(node& head, node& tail, stack<string>& command_history, stack<string>& undo_history);
// Hàm thực hiện lệnh undo
void undo(node & head, node & tail, stack<string>& command_history, stack<string>& undo_history);
// Hàm thực hiện lệnh
void execute_command(string command, node&head, node&tail);
// Hàm thực hiện lệnh đảo ngược
void execute_reverse_command(string command, node&head, node&tail);
// Huy danh sach lien ket
void DestroyList(node& head);
// Hàm thực hiện lệnh reset
void Reset(node& head, node& tail, stack<string>& command_history, stack<string>& undo_history);
// Hàm thực hiện lệnh quit
void Quit(node& head, node& tail, stack<string>& command_history, stack<string>& undo_history);
