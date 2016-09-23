#include <iostream>

/*
	Reference: http://codereview.stackexchange.com/questions/85313/implementing-a-linked-list-using-c?newsletter=1&nlcode=596280%7cf823
	Dont add using namespace std
	Initalizer list syntax
	Initialize all variables in Constructor
	Delete all references to new in Destructor
*/
class node {
	friend class linked;
	private:
		int data;

	public:
		node *link;
		node(){
			data = 0;
			link = NULL;
		}
}; // End class node

class linked {
	struct Node{
		int data;
		Node * next;
		Node( int data, Node* next )
			: data(data)
			, next(next)
		{}
	};

	Node* head;
	Linked(): head (nullptr) {}
	~Lined(){
		Node *temp;
		for (;head;head = tmp){
			tmp =head -> next;
			delete head;
		}
	public: 
		node *head = NULL; // Rename start to head
		//node *start = NULL;
		node *ptr = NULL;
		node *temp = NULL;

		void append( int item );
		void traverse();
}; //End class linked

void linked::append( int item ){
	ptr = new node(); // Must be acall to delete
	ptr->data = item;
	if ( start == NULL ){
		start = ptr;
		ptr->link = NULL;
		temp = start;
	}

	else {
		while ( temp->link != NULL ) {temp = temp->link;}
		temp->link = ptr;
		ptr->link = NULL;
	}
}

void linked::traverse() {
	node *traverse = start;
	while ( traverse != NULL ){
		std::cout << traverse->data << std::endl;
		std::cout << traverse->link << std::endl;
		traverse = traverse->link;
	}
}


int main(){
	int i;
	linked box;
	for ( i=0; i < 10; i++){
		box.append( i );
	}
	box.traverse();
	return 0;
}

