//#include<iostream>
//#include<math.h>
//using namespace std;
//class bst
//{
//	int dif, nu;
//	struct node
//	{
//		int num;
//		node *l, *r;
//	};
//	node *root;
//	int count(node *temp)
//	{
//		static int a = 0;
//		static int b = 0;
//		if (temp == NULL)
//		{
//			return a;
//
//		}
//		if (temp->l == NULL && temp->r == NULL)
//		{
//			b++;
//			return a;
//		}
//		count(temp->l);
//		a++;
//		count(temp->r);
//		a++;
//	}
//	int count1(node *temp)
//	{
//		static int b = 0;
//		if (temp == NULL)
//		{
//			return b;
//		}
//		if (temp->l == NULL && temp->r == NULL)
//		{
//			b++;
//			return b;
//		}
//		count1(temp->l);
//		count1(temp->r);
//	}
//	void searchn(int num, node *&ptr)
//	{
//		if (ptr == NULL)
//		{
//			cout << "Number Not Found:\n";
//			return;
//		}
//		else if (ptr->num == num)
//		{
//			dele(ptr);
//			return;
//		}
//		else if (num > ptr->num)
//		{
//			searchn(num, ptr->r);
//		}
//		else if (num < ptr->num)
//		{
//			searchn(num, ptr->l);
//		}
//	}
//	void dele(node *&temp)
//	{
//		if (temp->l == NULL)
//		{
//			node *ptr = temp;
//			temp = temp->r;
//			delete ptr;
//			return;
//		}
//		else if (temp->r == NULL)
//		{
//			node *ptr = temp;
//			temp = temp->l;
//			delete ptr;
//			return;
//		}
//		else
//		{
//			node *ptr = temp->r;
//			while (ptr->l!=NULL)
//			{
//				ptr = ptr->l;
//			}
//			ptr->l = temp->l;
//			ptr = temp;
//			temp = temp->r;
//			delete ptr;
//		}
//	}
//	void clos(int num, node *ptr)
//	{
//		static int flag = 0;
//		if (ptr == NULL)
//			return;
//		if (flag == 0)
//		{
//			dif = num - ptr->num, nu = ptr->num;
//			dif = abs(dif);
//			flag = 1;
//		}
//		clos(num,ptr->l);
//		int n = num - ptr->num;
//		n = abs(n);
//		if (n < dif)
//		{
//			dif = n;
//			nu = ptr->num;
//		}
//		clos(num,ptr->r);
//	}
//public:
//	bst()
//	{
//		root = NULL;
//	}
//	void insert(int num)
//	{
//		node *ptr = new node;
//		ptr->num = num;
//		ptr->l = ptr->r = NULL;
//		if (root == NULL)
//		{
//			root = ptr;
//		}
//		else
//		{
//			node *temp = root;
//			while (temp != NULL)
//			{
//				if (num >= temp->num)
//				{
//					if (temp->r == NULL)
//					{
//						temp->r = ptr;
//						return;
//					}
//					else
//					{
//						temp = temp->r;
//					}
//				}
//				else if(num<temp->num)
//				{
//					if (temp->l == NULL)
//					{
//						temp->l = ptr;
//						return;
//					}
//					else
//					{
//						temp = temp->l;
//					}
//				}
//			}
//		}
//	}
//	void countInternalNode()
//	{
//		cout << "Internal Nodes:\n";
//		cout<<count(root)/2;
//	}	
//	void countLesfNode()
//	{
//		cout << "leaf nodes:\n";
//		cout << count1(root) << endl;
//	}
//	void searchNode(int num)
//	{
//		searchn(num, root);
//	}
//	void deleteNode()
//	{
//		cout << "Enter key to Delete:\n"; int num;
//		cin >> num;
//		searchn(num, root);
//	}
//	void findClosest()
//	{
//		cout << "Enter Number to find:"; int num;
//		cin >> num;
//		clos(num, root);
//		cout << "Closest Number:" << nu << endl;
//	}
//	void search()
//	{
//		cout << "Enter number to search:"; int num;
//		cin >> num;
//		node *ptr = root;
//		while (ptr != NULL)
//		{
//			if (ptr->num == num)
//			{
//				cout << "Number Found:\n";
//				return;
//			}
//			if (num > ptr->num)
//				ptr = ptr->r;
//			else
//				ptr = ptr->l;
//		}
//		cout << "Number Not Found:\n";
//	}
//};
//int main()
//{
//	bst asad;
//	for (int i = 0; i < 11; i++)
//	{
//		cout << "Enter number:"; int k;
//			cin >> k;
//		asad.insert(k);
//	}
//	asad.countInternalNode();
//	cout << "\n";
//	asad.countLesfNode();
//	asad.findClosest();
//	cout << "Delete ka Funcation:\n";
//	asad.deleteNode();
//	cout << "Search ka Funcation:\n";
//	asad.search();
//	system("pause");
//}