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
    bool insert(int index, int value)
        {
            if(index<0||index>length)
            return false;
            if(index==0)
            {
                prepend(value);
                return true;;
            }
            if(index==length)
            {
                append(value);
                return true;
            }
            Node* newNode=new Node(value);
            Node* temp=get(index-1);
            newNode->next=temp->next;
            temp->next=newNode;
            length++;
            return true;
        } 
         void deleteFirst()
        {
            Node* temp=head;
            if(length==0)
            {
               return;
            }
            if(length==1)
            {
                head=tail=nullptr;
            }
            else
            {
                head=head->next;
            }
            delete temp;
            length--;
        }
        void deleteLast()
        {
            if(length==0)
            {
                return;
            }
            
            Node* temp=head;
            if(length==1)
            {
                head=nullptr;
                tail=nullptr;
            }
            else
            {
                Node* pre=head;
                while(temp->next)
                {
                    pre=temp;
                    temp=temp->next;
                    
                }
                tail=pre;
                tail->next=nullptr;
                delete temp;
               
            }
             length--;
        }
        void deleteNode(int index)
        {
            if(index<0||index>=length)
            return;
            if(index==0){
             deleteFirst();
             return;
            }
            if(index==(length-1)){
             deleteLast();
             return;
            }
            Node* pre=get(index-1);
            Node* temp=pre->next;
            pre->next=temp->next;
            delete temp;
            length--;
            
        }
};
 
int main()
{
    LinkedList* obj1=new LinkedList(5);
    obj1->append(8);
    obj1->printList();
    cout<<"-----------------"<<endl;
    obj1->deleteNode(1);
    obj1->printList();
    return 0;
}