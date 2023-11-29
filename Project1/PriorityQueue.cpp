#include "PriorityQueue.h"

int PriorityQueue::GetChildIndex(int selfIndex)
{
	int LC_Index = GetLeftChildIndex(selfIndex);
	int RC_Index = GetRightChildIndex(selfIndex);

	int LeftChildPriority = heap[LC_Index].f;
	int RightChildPriority = heap[RC_Index].f;
	
	if (LeftChildPriority != RightChildPriority)
	{
		return LeftChildPriority < RightChildPriority ? LC_Index : RC_Index;
	}
	else
	{
		return heap[LC_Index].h < heap[RC_Index].h ? LC_Index : RC_Index;
	}
	
}

int PriorityQueue::GetParentIndex(int selfIndex)
{
	return selfIndex / 2;
}

int PriorityQueue::GetLeftChildIndex(int selfIndex)
{
	return selfIndex * 2;
}

int PriorityQueue::GetRightChildIndex(int selfIndex)
{
	return selfIndex * 2 + 1;
}

void PriorityQueue::Swap(int firstIndex, int secondIndex)
{
	Node temp = heap[firstIndex];
	heap[firstIndex] = heap[secondIndex];
	heap[secondIndex] = temp;
}

PriorityQueue::PriorityQueue()
{
	for (int i = 0; i < MaxCount; i++)
	{
		heap[i].f = 99999999999999999;
	}
	count = 0;
}

PriorityQueue::~PriorityQueue()
{
}

bool PriorityQueue::IsEmpty()
{
	return count == 0 ? true : false;
}

void PriorityQueue::Push(int x, int y,int h, int g)
{
	for (int i = 0; i < count; i++)
	{
		if (heap[i].x == x && heap[i].y == y)
		{
			if (heap[i].f < h + g)
			{
				return;
			}
			else
			{
				heap[i].h = h;
				heap[i].g = g;
				heap[i].f = h + g;
				return;
			}
		}
	}
	count++;
	heap[count].x = x;
	heap[count].y = y;
	heap[count].f = h+g;
	heap[count].h = h;
	heap[count].g = g;
}

Node PriorityQueue::Pop()
{
	int Idx = count;
	if (count > 0)
	{
		while (Idx != 1)
		{
			int parent = GetParentIndex(Idx);
			int child = GetChildIndex(parent);
			if (heap[parent].f > heap[child].f)
			{
				Swap(parent, child);
			}
			if (heap[parent].f == heap[child].f && heap[parent].h > heap[child].h)
			{
				Swap(parent, child);
			}
			Idx--;
		}
		if (heap[1].f > heap[2].f)
		{
			Swap(1, 2);
		}
		else if (heap[1].f == heap[2].f && heap[1].h > heap[2].h)
		{
			Swap(1, 2);
		}
		Node result = heap[1];

		Swap(1, count);
		heap[count].h = 0;
		heap[count].f = MaxCount + 1;
		count--;

		return result;
	}
	else
	{
		cout << "Pop할수있는 Node가 없습니다." << endl;
		Node result = { 0,0 };
		return result;
	}

}

int PriorityQueue::Count()
{
	return count;
}