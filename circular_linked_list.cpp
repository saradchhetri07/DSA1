#include <iostream>
#include<cstring>
using namespace std;
//linked list
class Node{
public:
int data;
Node* next;
Node* prev;
//constructor
Node(int data){
  this->data=data;
  this->next = NULL;
  this->prev = NULL;
}
~Node(){
  int val = this->data;
  if(next!=NULL){
    delete next;
    next=NULL;
  }
  cout<<"Memory freed for element with the value"<<val<<endl;
}
};
void insertAtHead(Node* &head,int d){
  Node* temp = new Node(d);
  temp->next = head;
  head->prev = temp;
  head = temp;
}
void insertAtTail(Node* &tail,int d){
  Node* temp= new Node(d);
  tail->next=temp;
  temp->prev=tail;
  tail=temp;
  
}
// void insertAtBehind(Node* &head,int d){
//   Node* temp = head;
//   while(temp->next!=NULL){
//     temp= temp->next;
//   }
//   Node* newnode= new Node(d);
//   temp->next=newnode;
// }
void print(Node* &head){
  Node* temp = head;
  while((temp->next)!=NULL){
    cout<<temp->data<<endl;
    temp=temp->next;
  
  }
  cout<<temp->data<<endl;

}

void countElement(int &allcount,Node* head){
  Node* temp=head;
while(temp->next!=NULL){
  temp=temp->next;
  allcount++;
}
  allcount++;
  
}

void insertAtPos(Node* &head,Node* &tail,int count,int d,int &allcount){
int newcount=1;
  if(count==1){
    insertAtHead(head,d);
    return;
  }
Node* temp=head;
while(temp->next!=NULL && newcount!=count){
  newcount++;
  temp=temp->next;
}
  if(newcount==count){
    insertAtTail(tail,d);
    return;
  }
  Node* nodetoinsert= new Node(d);
  Node* previous = temp->prev;
  previous->next = nodetoinsert;
  nodetoinsert->prev = previous;
  nodetoinsert->next=temp;
  temp->prev = nodetoinsert;
  
  
}
//delete from particular position
void deleteVal(Node* &head,Node* &tail,int pos,int &allcount){
  if(pos==1){
     Node* newtemp=head;
    head=newtemp->next;
    head->prev=NULL;
     newtemp->next=NULL;
     newtemp->prev=NULL;
    delete newtemp;
    return;
  }
  int newcount =1;
  Node* temp = head;
  if(pos==allcount){
    tail=tail->prev;
    tail->next=NULL;
    return;
  }
  while(temp->next!=NULL && newcount!= pos){
    newcount++;
    temp=temp->next;
  }
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  temp->next=NULL;
  temp->prev=NULL;
  delete temp;
  
}
int main() {
  Node* node1 = new Node(10);
  Node* head = node1;
  Node* tail = node1;
 
  insertAtHead(head,20);
  insertAtHead(head,30);
  insertAtTail(tail,40);
  insertAtTail(tail,50);
  insertAtTail(tail,5);
 
  int allcount=1;
  countElement(allcount,head);
  // int n;
  // cout<<"Enter the value you want to delete"<<endl;
  // cin>>n;
  print(head);
  insertAtPos(head,tail,6,7,allcount);
  
  cout<<endl;
  cout<<"head"<<head->data<<endl;
  cout<<"tail"<<tail->data<<endl;
  
  //deleteElementatpos
  //deleteVal(head,tail,6,allcount);
  print(head);
  cout<<"head"<<head->data<<endl;
  cout<<"tail"<<tail->data<<endl;
  deleteVal(head,tail,7,allcount);
  print(head);
  cout<<"head"<<head->data<<endl;
  cout<<"tail"<<tail->data<<endl;

}
