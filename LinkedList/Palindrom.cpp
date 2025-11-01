//check if the list is palindrom or not 
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
bool isequal(Node*&list1,Node*&list2){
    Node*temp1=list1;
    Node*temp2=list2;
    while(temp1!=nullptr){
        if(temp1->value!=temp2->value){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}
void insertAtBegin(Node*&head,int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
        newNode->next=nullptr;
    }
    newNode->next=head;
    head=newNode;
}
void insertAtLast(Node*&head,int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
        newNode->next=nullptr;
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=nullptr;
}
bool isPalindrom(Node*&head){
    Node*rev=nullptr;
    Node*temp=head;
    if(head==nullptr){
        return true;
    }
    while(temp!=nullptr){
        insertAtBegin(rev,temp->value);
        temp=temp->next;
    }
    if(isequal(head,rev)){
        return true;
    }
    return false;
}
void display(Node*&head){
    Node*temp=head;
    if(head==nullptr){
        return ;
    }
    while(temp!=nullptr){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"nullptr";
}
int main(){
    int n;
    cin>>n;
    Node*list=nullptr;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        insertAtLast(list,input);
    }
    cout<<"list:";
    display(list);
    cout<<endl;
    cout<<isPalindrom(list);
    return 0;
}
