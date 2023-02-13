#include<iostream>
#include<map>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node( int d )
    {
        this -> data = d ;
        this -> next = NULL;
    } 

    //destructor
    ~Node()
    {
        int value = this -> data ;
        if( this -> next != NULL )
        {
            delete next;
            this -> next = NULL;
        }
        cout << " delete value is : "<< value << endl;
    }
};

void insertionAtElement( Node* &head , int element, int data )
{
    // empty list hai mtlb NULL hai to 
    if( head == NULL )
    {
        Node* newNode = new Node(data);
        newNode -> next = newNode;
        head = newNode;
    }
    else
    {
        // ye empty node to nahi hai 
        Node* curr = head;
        while( curr->data != element)
        {
            curr = curr -> next ;
        }

        Node* temp = new Node(data);
        temp -> next = curr -> next ;
        curr -> next = temp ;
    }
}

void printElement( Node* &head )
{
    if (head == NULL )
    {
        cout<< "Bhai kuch daal to head me"<< endl;
    }
    else{
    Node* curr = head;
    do
    {
        cout << curr -> data << " ";
        curr = curr -> next;

    }while (curr -> data != head -> data );
    }
    cout<< endl;
}

bool isCircular( Node* &head )
{
    // head == NULL empty node
    if( head == NULL )
    {
        return true;
    }
    // single node ya multiple node
    else
    {
        Node* curr = head -> next;
        while( head != curr && curr != NULL )
        {
            curr = curr -> next;
        }

        if( curr == head )
        {
            return true;
        }
        
        return false;
        
    }
}

bool loopIsPresent(Node* &head)
{
    // empty node
    if( head == NULL )
    {
        return false;
    }
    // one or more than one element is present in node
    map<Node* , bool > visited;

    Node* temp = head;
    while( temp != NULL )
    {
        if( visited[temp] ==  true )
        {
            return temp ;
        }
        visited[temp] = true;
        temp = temp -> next;
        return false;
    }
}

Node* floydDetectLoop( Node* &head )
{
    //  empty node
    if( head == NULL )
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while( slow != NULL && fast != NULL )
    {
        fast = fast -> next;

        if( fast != NULL )
        {
            fast = fast -> next ;
        }

        slow = slow -> next ;

        if( fast == slow )
        {
            return fast;
        }

    }

    return NULL;
}
int main()
{
    Node* head = NULL;
    insertionAtElement(head,1,2);
    insertionAtElement(head,2,3);
    insertionAtElement(head,3,4);
    insertionAtElement(head,2,5);

    printElement(head);
    
    if(isCircular(head))
    {
        cout << "Its a circular linked list" << endl;
    }
}