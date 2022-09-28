#include <iostream>
#include<cstring>
using namespace std;
//linked list
class Node{
public:
int data;
Node* next;
//constructor
Node(int data){
  this->data=data;
  this->next = NULL;
}
};
void insertAtHead(Node* &head,int d){
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}
void insertAtTail(Node* &tail,int d){
  Node* temp= new Node(d);
  tail->next=temp;
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
// void deleteval(Node* &head,int n){
//   Node* temp=head;
//   if(temp->data==n){
//     head=temp->next;
//     temp=head;
//   }
//    Node* newtemp = head;
  
//   while(newtemp->next!=NULL || newtemp->data==n){
//    temp=newtemp->next;
//     if(temp->data==n){
//       newtemp->next=temp->next;  
//     }
//     newtemp=newtemp->next;
    
//   }
//  // newtemp->data=0;
  
// }
void deleteVal(Node* &head,Node* &tail,int pos,int &allCount){
  Node* temp=head;
  Node* newtemp;
  if(pos==1){
  head=head->next;
    return;
  }
 
  int newCount=1;
  while(temp->next!=NULL && newCount!=pos){
    newtemp=temp;
    temp=temp->next;
    newCount++; 
  }
  if(newCount==allCount){
    newtemp->next=NULL;
    tail=newtemp;
  }else{
    newtemp->next=temp->next;
  }
  
  
  
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
    cout<<"came here"<<endl;
    insertAtHead(head,d);
    return;
  }
  Node* newnode = new Node(d);
  Node* temp=head;
  while(newcount!=(count-1)){
    temp=temp->next;
    newcount++;
  }
  Node* newtemp = temp->next;
  temp->next=newnode;
  newnode->next=newtemp;
  if(count==allcount){
    tail=tail->next;
  }
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
 insertAtPos(head,tail,3,60,allcount);
  print(head);
  cout<<endl;
  cout<<"head"<<head->data<<endl;
  cout<<"tail"<<tail->data<<endl;
  
  //deleteElementatpos
  deleteVal(head,tail,6,allcount);
  print(head);
  cout<<"head"<<head->data<<endl;
  cout<<"tail"<<tail->data<<endl;
 

}
