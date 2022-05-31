#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct node{
	int data;
	node *next;
	// Constructor.............
	node(int d){
		data = d;
		next = NULL;
	}
};

// ................................ DOUBLY LINKED LIST ..............................................
// head->prev = newnode;
// newnode->next=head;
// head=newnode;
// ..................................................................................................

class linkedlist{
	
		node *head,*tail;
		public:
		linkedlist(){
			head = NULL;
			tail = NULL;
		}
		
		void insertAtEnd(int dt){
			node *newnode = new node(dt);
			if(head == NULL){
				head = newnode;
				tail = newnode;
			}
			else{
				tail->next = newnode;
				tail = tail->next;
			}
		}
		
		void insertAtBegin(int dt){
			node *newnode = new node(dt);
			if(head == NULL){
				head = newnode;
				tail= newnode;
			}
			else{
				newnode->next = head;
				head = newnode;
			}
		}
		
		void print(){
			if(head==NULL){
				cout<<"List is empty"<<endl;
			}
			else{
				node *current = head;
				
				while(current!=NULL){
					cout<<current->data<<"->";
					current = current->next;
				}
				cout<<"NULL";
				cout<<endl;
			}
		}
		
		void deleted(int dt){
			node *newnode = new node(dt);
			if(head==NULL){
				cout<<"List is empty"<<endl;
			}
			else{
				node *current = head;
				while(current->next!=NULL and current->next->data!=dt){
					current = current->next;
				}
				
				if(current->next==NULL){
					cout<<"didn't find"<<endl;
				}
				else{
					current->next = current->next->next;
					free(current->next);
				}
			}
		}
		
		void insertAtKth(int k,int dt){
			
			if(head==NULL){
				cout<<"List is empty"<<endl;
			}
			else if(k==0){
				node *newnode = new node(dt);
				
				newnode->next = head;
				head = newnode;
			}	
			else{
				node *current = head;
				node *newnode = new node(dt);
				while(current!=NULL and --k){
					current = current->next;
				}
				if(current==NULL){
					cout<<"Doesn't Exist"<<endl;
					return;
				}
				else{
					newnode->next = current->next;
					current->next = newnode;
				}
			}
		}
		
		void reverseLLIterative(){
			// Three Pointers;
			node *prev=NULL; node *current=head;
			node *nxt=NULL;
			
				while(current!=NULL){
					nxt=current->next;
					current->next=prev;
					prev=current;
					current=nxt;
				}
				head=prev;
		}
		
		// Slow-Fast Method;
		node *middleElement(){
			node *slow=head;
			node *fast=head;
			
			while(fast!=NULL and fast->next!=NULL){
				slow=slow->next;
				fast=fast->next->next;
			}
			
			return slow;
		}
		
		int SizeOfLL(){
			int ans=0;
			node *current=head;
			while(current!=NULL){
				current=current->next;
				ans++;
			}
			return ans;
		}
		
		node *MiddleElement(int sz){
			node *current = head;
			while(sz--){
				current=current->next;
			}
			
			return current;
		}
		
		
		int kthFromLast(int k){
			node *slow=head, *fast=head;
			
			while(fast!=NULL and k--){
				fast=fast->next;
			}
			
			if(fast!=NULL){
				while(fast!=NULL){
					slow=slow->next;
					fast=fast->next;
				}
				
				return slow->data;
			}
			else{
				return 0;
			}
		}
		
		
};


int32_t main(){
	
	linkedlist lk = linkedlist();
	
	// node *head=NULL;
	lk.insertAtEnd(10);
	lk.insertAtBegin(20);
	lk.insertAtEnd(100);
	
	lk.insertAtEnd(34);
	lk.insertAtEnd(44);
	lk.insertAtEnd(78);
	lk.insertAtEnd(76);
	lk.insertAtKth(0,108);
	
	lk.print();
	
	lk.reverseLLIterative();
	lk.print();
	
	node *middle=lk.middleElement();
	
	
	cout<<middle->data<<endl;
	
	int sz=lk.SizeOfLL();
	cout<<sz<<endl;
	
	node *Middle=lk.MiddleElement(sz/2);
	
	cout<<Middle->data<<endl;
	
	int fromlast=lk.kthFromLast(2);
	
	cout<<fromlast<<endl;
	
}
