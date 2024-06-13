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
     Node* get(int index)
        {
            if(index<0||index>=length)
             return nullptr;
            Node* temp=head;
            for(int i=0;i<index;i++)
            {
                temp=temp->next;
            }
            return temp;
            length--;
            
        }
         bool set(int index, int value)
        {
            Node* temp=get(index);
            if(temp)
            {
                temp->value=value;
                return true;
            }
            else
            return false;
        }
};
int main()
{
    LinkedList* obj1=new LinkedList(5);
    obj1->append(8);
    obj1->printList();
    cout<<"-----------------"<<endl;
    cout<<obj1->get(1)->value<<endl;
    cout<<"-----------------"<<endl;
    obj1->set(1,9);
    obj1->printList();
    return 0;
}