//reverse the linked list 
#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node*next;
    Node(int value){
        this->value=value;
        next=nullptr;
    }
};
void insertAtBegin(Node*&head,int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
        head->next=nullptr;
        return ;
    }
    newNode->next=head;
    head=newNode;
}
void insertAtLast(Node*&head,int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
        head->next=nullptr;
        return ;
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=nullptr;
}
Node*reversedList(Node*&head){
    Node*rev=nullptr;
    
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node*temp=head;
    while(temp!=nullptr){
        insertAtBegin(rev,temp->value);
        temp=temp->next;
    }
    return rev;
}
void display(Node*&head){
    if(head==nullptr){
        cout<<"empty linked list";
        return ;
    }
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"nullptr";
    return ;
}
int main(){
    int n;
    cin>>n;
    Node*newNode=nullptr;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        insertAtLast(newNode,input);
    }
    cout<<"original linked list:";
    display(newNode);
    cout<<endl;
    Node*rev=reversedList(newNode);
    cout<<"reversed linked list:";
    display(rev);
    return 0;
}
