#pragma once
#include<iostream>
class AVL
{
	struct node
	{
		int num,h;
		node *L, *R;
	};
	int num;
	node *root;
	void in(node*, node*);
	void in(node*);
	void checkHight(node*);
	int max(int a, int b);
	int height(node *ptr);

	node* rotateRight(node *K2)
	{
		node *K1=new node;
		K1 = K2->L;
		K2->L = K1->R;	 
		K1->R = K2;
		K2->h = max(height(K2->L), height(K2->R)) + 1;
		K1->h = max(height(K1->L), K2->h) + 1;
		return K1;
	}

	node *rotataLeft(node *K2)
	{
		node *K1;
		K2 = K1->R;
		K1->R = K2->L;
		K2->L = K1;
		K1->h = max(height(K1->L), height(K1->R)) + 1;
		K2->h = max(height(K2->R), K1->h) + 1;
		return K2;
	}
	void checkCase(node*,int n);
public:
	AVL();
	void insert();
	void inOrder();
	//~AVL();
};