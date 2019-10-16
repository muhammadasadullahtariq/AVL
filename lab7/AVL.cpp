#include<iostream>
#include"AVL.h"
using namespace std;

AVL::AVL()
{
	num = 0;
}

void AVL::insert()
{
	node *ptr = new node;
	cout << "Enter number:";
	cin >> num;
	ptr->num=num;
	ptr->L = NULL;
	ptr->R = NULL;
	ptr->h = 0;
	if (root == NULL)
	{
		root = ptr;
	}
	else
	{
		in(root, ptr);
	}
}

void AVL::in(node *ptr, node*tem)
{
	if (tem->num < ptr->num)
	{
		if (ptr->L == NULL)
		{
			ptr->L = tem;
			ptr->h = 1;
			return;
		}
		else
		{
			(ptr->L, tem);
			if (ptr->R == NULL)
			{
				ptr->h = ptr->L->h + 1;
			}
			else if (ptr->L->h >= ptr->R->h)
			{
				ptr->h = ptr->L->h + 1;
			}
			else
			{
				ptr->h = ptr->R->h + 1;
			}
		}
	}
	else if (tem->num >= ptr->num)
	{
		if (ptr->R == NULL)
		{
			ptr->R = tem;
			ptr->h = 1;
			return;
		}
		else
		{
			in(ptr->R, tem);
			if (ptr->L == NULL)
			{
				ptr->h = ptr->R->h + 1;
			}
			else if (ptr->L->h >= ptr->R->h)
			{
				ptr->h = ptr->L->h + 1;
			}
			else
			{
				ptr->h = ptr->R->h + 1;
			}
		}
	}
}

void AVL::inOrder()
{
	in(root);
}

void AVL::in(node *ptr)
{
	if (ptr == NULL)
		return;
	in(ptr->L);
	cout << ptr->num << "\t" << ptr->h<<endl;
	in(ptr->R);
}

void AVL::checkHight(node *ptr)
{
	int r = 0, l = 0,res=0;
	if (ptr->R == NULL)
	{
		r = -1;
	}
	else
	{
		r = ptr->R->h;
	}
	if (ptr->L == NULL)
	{
		l = -1;
	}
	else
	{
		l = ptr->L->h;
	}
	res = l - r;
	res = abs(res);
	if (res == 2)
	{
		if (l > r)
			checkCase(ptr, 1);
		else
			checkCase(ptr, 0);
	}
}

int AVL::height(node *ptr)
{
	if (ptr == NULL)
		return 0;
	else
		return ptr->h;
}

int AVL::max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

void AVL::checkCase(node *ptr,int n)
{
	if (n == 0)
	{
		if (ptr->R->num >= num)
		{
			rotataLeft(ptr);
		}
		else
		{
			rotateRight(ptr->R);
			rotataLeft(ptr);
		}
	}
	else if (n == 1)
	{
		if (ptr->L->num >= num)
		{
			rotataLeft(ptr->L);
			rotateRight(ptr);
		}
		else
		{
			rotateRight(ptr);
		}
	}
}