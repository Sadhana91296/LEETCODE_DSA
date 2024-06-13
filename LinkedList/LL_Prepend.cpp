#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int value){
        this->value=value;
        next=nullptr;
    }
};
class LinkedList{
    private:
    Node* head;
    Node* tail;
    int length;
    public:
    LinkedList(int value){
        Node* newNode=new Node(value);
        head=newNode;
        tail=newNode;
        length=1;
    } 
    ~LinkedList(){
        Node* temp=head;
        while(head)
        {
            head=head->next;
            delete temp;
            temp=head;
        }
    }
    void printList()
    {
        Node* temp=head;
        if(temp==nullptr)
         cout<<"Empty LinkedList"<<endl;
        else
        {
            while(temp!=nullptr)
            {
                cout<<temp->value<<endl;
                temp=temp->next;
            }
        }
    }
    Node* getHead()
    {
        return head;
    }
    Node* getTail()
    {
        return tail;
    }
    int getLength()
    {
        return length;
    }

    void append(int value)
    {
        Node* newNode=new Node(value);
        if(length==0)
        {
            tail=newNode;
            head=newNode;
        }
        else{
        tail->next=newNode;
        tail=newNode; 
        }
        length++;
    }
    void prepend(int value)
        {
            Node* newNode=new Node(value);
            if(length==0)
            {
                head=tail=newNode;
            }
            else
            {
                newNode->next=head;
                head=newNode;
            }
            length++;
        }
    
};
int main()
{
    LinkedList* obj1=new LinkedList(5);
    obj1->append(8);
    obj1->printList();
    cout<<"-----------------"<<endl;
    obj1->prepend(10);
    obj1->printList();
    return 0;
}