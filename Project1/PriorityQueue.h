#pragma once
#include <iostream>

using namespace std;

#define MaxCount 9999

struct Node
{
	int f;
	int h;
	int g;
	int x;
	int y;
};

class PriorityQueue
{
private:
public:
	Node heap[MaxCount];
	int count;
public:
	//����ִ��� �˷��ִ� ����
	bool IsEmpty();
	//���� �߰�(�켱����, ��)
	void Push(int x, int y, int h,int g);
	//�켱������ ���� Node ��ȯ
	Node Pop();
	int Count();
private:
public:
	//�켱���� ���� �ڽ��� index�� ��ȯ
	int GetChildIndex(int selfIndex);
	//�θ��� index
	int GetParentIndex(int selfIndex);
	//���� �ڽ��� index
	int GetLeftChildIndex(int selfIndex);
	//������ �ڽ��� index
	int GetRightChildIndex(int selfIndex);
	//�� ���� �ٲ�
	void Swap(int firstIndex, int secondIndex);
public:
	PriorityQueue();
	~PriorityQueue();
};