//merge two sorted list 
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
void insertAtLast(Node*&head,int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        newNode->next=head;
        head=newNode;
        return ;
    }
    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=nullptr;
}
Node*mergeList(Node*&head1,Node*&head2){
    Node*merge=nullptr;
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    Node*temp1=head1;
    Node*temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->value>temp2->value){
            insertAtLast(merge,temp2->value);
            temp2=temp2->next;
        }
        else{
            insertAtLast(merge,temp1->value);
            temp1=temp1->next;
        }
    }
    while(temp1!=nullptr){
        insertAtLast(merge,temp1->value);
        temp1=temp1->next;
    }
    while(temp2!=nullptr){
        insertAtLast(merge,temp2->value);
        temp2=temp2->next;
    }
    return merge;
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
    int n1;
    cout<<"size of list1:";
    cin>>n1;
    Node*list1=nullptr;
    cout<<"enter elements in list1:";
    for(int i=0;i<n1;i++){
        int input;
        cin>>input;
        insertAtLast(list1,input);
    }
    int n2;
    cout<<"size of list2:";
    cin>>n2;
    Node*list2=nullptr;
    cout<<"enter elements in list2:";
    for(int i=0;i<n1;i++){
        int input;
        cin>>input;
        insertAtLast(list2,input);
    }
    cout<<"list1:";
    display(list1);
    cout<<endl;
    cout<<"list2:";
    display(list2);
    cout<<endl;
    Node*res=mergeList(list1,list2);
    cout<<"merged list:";
    display(res);
    return 0;
}
