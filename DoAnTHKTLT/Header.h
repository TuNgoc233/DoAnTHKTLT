#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

//// Khai báo các stack để lưu trữ lịch sử các lệnh đã thực hiện và đã phục hồi
//std::stack<std::string> command_history;
//std::stack<std::string> undo_history;

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
void deleteAt(node& head, node& tail, int pos);
//Them phan tu vao sau 1 phan tu nao do trong danh sach
void insertAfter(node q, int k);
//Them phan tu vao truoc mot phan tu nao do trong danh sach 
void insertBefore(node q, int k);
//Chen 1 node co gia tri x tai mot vi tri xac dinh trong danh sach
void insertAt(node& head, node& tail, int x, int pos);
//Dao nguoc danh sach
void Reverse(node& head, node& tail);
//Sap xep danh sach theo thu tu tang dan
void Sort(node& head);
//Xoa cac phan tu trung nhau trong danh sach
void RemoveDuplicates(node& head);