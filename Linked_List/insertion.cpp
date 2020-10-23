#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* insertNodeAtBack(int val){
	node* temp = new node();
	temp->data = val;
	temp->next = NULL;
	return temp;
}

node* insertNodeAtFront(node* head, int val){
	node* temp = new node();
	temp->data = val;
	temp->next = head;
	head = temp;
	return head;
}

void insertNodeAfter(node* head, int target, int val){
	node* prev = NULL;
	node* temp = new node();
	temp->data = val;
	if(head == NULL){
		temp->next = NULL;
		return;	
	}
	while(head != NULL){
		if(head->data == target){
			prev = head->next;
			head->next = temp;
			temp->next = prev;
			break;
		}
		head = head->next;
	}
	if(prev == NULL){
		cout<<"Targer is invalid"<<endl;
		return;
	}
}

void print(node* temp){
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("/home/shubham/Desktop/codes/input.txt", "r", stdin);
    freopen("/home/shubham/Desktop/codes/output.txt", "w", stdout);
    #endif
	//Input number of nodes in linked list
	int nodes;
	cin>>nodes;
	//Taking Input
	node* temp = NULL;
	node* head = NULL;
	while(nodes--){
		int num;	
		cin>>num;
		if(temp == NULL){
			temp = insertNodeAtBack(num);
			head = temp;
		}
		else{
			temp->next = insertNodeAtBack(num);
			temp = temp->next;
		}
	}
	insertNodeAfter(head, 2, 8);
	print(head);

	return 0;
}