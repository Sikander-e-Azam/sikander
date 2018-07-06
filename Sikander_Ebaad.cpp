
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



struct Node
{
	int data;
	string name;
	struct Node *next;
};

//circular node
 
Node *newNode(int data)
{
	
	Node *temp = new Node;
	temp->next = temp;
	
	temp->data = data;
	return temp;

}


void getJosephusPosition(int m, int n)
{
	
	Node *head = newNode(1);
	Node *prev = head;
	for (int i = 2; i <= n; i++)
	{
		prev->next = newNode(i);
		prev = prev->next;

	}
	prev->next = head; // Connect last node to first
	


	Node *ptr1 = head, *ptr2 = head;
	while (ptr1->next != ptr1)
	{
		// Find m-th node
		int count = 1;
		while (count != m)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			count++;
		}

		/* Remove the m-th node */
		ptr2->next = ptr1->next;
		ptr1 = ptr2->next;
		

	}
	
	printf("According to this data, if we stand on position %d \n"
		"We Survive\n",ptr1->data);

	ofstream myfile;
	myfile.open("first.txt");
	myfile << "There are " << n << " people in the circle" << endl;
	myfile << "The no of people skipped every time is " << m << endl;
	myfile << "According to this data, if we stand on position  " << ptr1->data << " we survive \n" << endl;
	myfile.close();

}


int main()
{	
	int i;
	int m;
	int n;
	
	string line;
	ifstream myfile("first.txt", std::ios_base::in);
	if (myfile.is_open())
	{
		
		myfile >> n;
		cout << "There are ";
		cout << n;
		cout << " people in the circle\n";


		for (i = 0; i < n; i++)
		{
			
			
			myfile >> line;

			cout << line << endl;
			
		}
		myfile >> m;
		cout <<"The no of people skipped every time is " << m << endl;
		myfile.close();
	}

	else cout << "Unable to open file";

	

	getJosephusPosition(m, n);



	return 0;
}