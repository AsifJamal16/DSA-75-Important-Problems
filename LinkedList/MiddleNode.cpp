//Find the middle node of the linked list 
#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node*next;
    Node(int value){
        next=nullptr;
        this->value=value;
    }
};
void insertAtlast(Node*&head,int value){
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
void middleOfList(Node*&head){
    Node*slow=head;
    Node*fast=head;
    if(head==nullptr){
        return ;
    }
    if(head->next==nullptr){
        cout<<slow->value;
        return ;
    }
    if(slow->next->next==nullptr){
        cout<<slow->value<<" "<<slow->next->value;
        return ;
    }
    while(fast!=nullptr &&fast->next!=nullptr){
        fast=fast->next->next;
        if(fast!=nullptr){
            slow=slow->next;
        }
        
    }
    if(fast==nullptr){
        cout<<slow->value<<" "<<slow->next->value;
    }
    else{
        cout<<slow->value;
    }
}
void display(Node*&head){
    if(head==nullptr){
        return ;
    }
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"nullptr";

}
int main(){
    int n;
    cin>>n;
    Node*newnode=nullptr;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        insertAtlast(newnode,input);
    }
    cout<<"list:";
    display(newnode);
    cout<<endl;
    middleOfList(newnode);
    return 0;
}

