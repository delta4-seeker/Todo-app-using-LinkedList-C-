#include <iostream>
#include <string>
#include <conio.h>


using namespace std;
// function declaration
void Menu() ; // user interface to access function efficiently
void Display() ; // display all the list of TODO and list of task in Todo
void Termination() ; // exit the application
void Edit() ; // Add task , remove task from selected Todo list
void Create() ; // create todo Node in Linkedlist storing todos. 
void Delete() ; // delete the Todo list along with the task in it.

// node of linkedlist specific to store task(string)

 void clearscreen(string os){
 	if(os == "others"){
 		system("cls");
	 }
	 else{
	 	system("clear");
	 }
 }
class Node {
	public:
		Node* next; 
		string task; //data
			
		Node(string input){
		task = input;
		next = NULL ; 		
}
};

//linkedlist of nodes storing task(string)
class LinkedList{

public:
	Node* head ; 
	string name;

	LinkedList(){
		head = NULL; 	
	}
	
	int LengthOfList(){
		int ListLen = 0 ; 
		Node *temp1 = head; 
		// Find length of the linked-list.
		while (temp1 != NULL) {
			temp1 = temp1->next;
			ListLen++;
		}
		return ListLen ; 
	}
	
	bool isListEmpty(){
		if (head == NULL) {
			return true;
		}
		else{
			return false ; 
		}
	} 
	
	void InsertNodeAtBeginning(string name){
		Node* newNode = new Node(name);

		if (head == NULL) {
			head = newNode;
			return;
		}
		else{	
			newNode->next = head ;
			head = newNode ;  
			
		}
		
	
	}
	
	void InsertNodeAtEnd(string name){
		Node* newNode = new Node(name);
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		}
	
	void InsertNodeAtSpecificPosition(int position , string name){
		Node *temp = head ; 
		Node *newNode = new Node(name);
		
		int lengthoflist = LengthOfList();
		if(position < 1 || position > lengthoflist){
			cout << "Invalid position";
			return ; 
		}
		for(int i = 1 ; i < position-1 ; i ++){	
			temp = temp->next ;
		}
		newNode->next = temp->next ; 
		temp->next = newNode ; 
	}
	
	void DeleteNodeAtBeginning(){
		int listlen = LengthOfList();
		Node *temp = head ;
		head = head->next;
		delete temp;
		return;
	}
		
	void DeleteNodeAtEnd(){
		Node *temp = head ; 
		Node *temp2 = NULL;
		while(temp->next != NULL){
			temp2 = temp ; 
			temp = temp->next ; 
		}
		temp2->next = NULL ; 
	}
	
	void DeleteNodeAtSpecificPosition(int position){
		Node *temp = head ; 
		if(position == 1){
			DeleteNodeAtBeginning();
			return ; 	
		}
		int lengthoflist = LengthOfList();
		if(position < 1 || position > lengthoflist){
			cout << "Invalid position";
			return ; 
		}
		Node *temp2 = NULL ; 
		while (position-- > 1) {
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next ; 
		delete temp ; 
	}
	
	
	void DisplayLinkedList(){
		Node *temp = head ; 
			int i = 1 ; 
			cout << endl << "To-Do list name : " << name << endl << endl  ; 
		while(temp != NULL){
			cout << "	" << i << " 			 " ; 
			cout << temp->task << endl; 
			temp = temp->next ; 
			i++ ; 
		}
	}	
};

//node for linkedlist specific to store linkedlist(of string) object.
// this node  stores instances of Linkedlist as data
class Node_for_todo_list{
	public :
	Node_for_todo_list* next ; 
	LinkedList task_list ; // linkedlist instance as data of node
	
	Node_for_todo_list(LinkedList tasklist){ // constructor
		task_list = tasklist;
		next = NULL ; 		
	}
};

// this is a nested linkedlist where there is a linkedlist in the data field of another linkedlist.

//here one linkedlist is used to store the chain of task and another linkedlist is used to store the chain of TODO list
//every task is associated to a todo list uniquely.
class LinkedList_for_todo_list{
public:
	Node_for_todo_list* head ; 

	LinkedList_for_todo_list(){
		head = NULL; 	
	}

	
	int LengthOfList(){
		int ListLen = 0 ; 
		Node_for_todo_list *temp1 = head; 
		// Find length of the linked-list.
		while (temp1 != NULL) {
			temp1 = temp1->next;
			ListLen++;
		}
		return ListLen ; 
	}
	
	bool isListEmpty(){
		if (head == NULL) {
			return true;
		}
		else{
			return false ; 
		}
	} 
	
	void InsertNodeAtBeginning(LinkedList todo){
		Node_for_todo_list* newNode = new Node_for_todo_list(todo);

		if (head == NULL) {
			head = newNode;
			return;
		}
		else{	
			newNode->next = head ;
			head = newNode ;  
			
		}
		
	
	}
	
		void DeleteNodeAtBeginning(){
		int listlen = LengthOfList();
		Node_for_todo_list *temp = head ; 
		head = head->next;
		delete temp;
		return;
	}
	
		void DeleteNodeAtSpecificPosition(int position){
		Node_for_todo_list *temp = head ; 
		if(position == 1){
			DeleteNodeAtBeginning();
			return ; 	
		}
		int lengthoflist = LengthOfList();
		if(position < 1 || position > lengthoflist){
			cout << "Invalid position";
			return ; 
		}
		Node_for_todo_list *temp2 = NULL ; 
		while (position-- > 1) {
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next ; 
		delete temp ; 
	}	
};

LinkedList_for_todo_list Todo_List ; // a global scoped instance which store todos and within in todos, there are corresponding task.


void Create(){
		clearscreen("others"); // replace WINDOWS with OTHERS if you see clear screen problem. it is because of different command used in different OS.
        // system("clear") for Windows and system("cls") for linux
	
	cout << "To-Do list names : " << endl << endl ; 
	Node_for_todo_list* temp = Todo_List.head ; 
	// this while loop is use to display name of saved todo lists
	while(temp != NULL){
		Node* temp2 =  temp->task_list.head ; 
		cout << "	" << temp->task_list.name << " 			   " ;
		//this while loop is used to display the name of task with in a todo instance.
		while(temp2 != NULL){
			cout << temp2->task << ", " ; 
			temp2 = temp2->next ; 
		}
		temp = temp->next ;
			cout << endl << endl ; 
		delete temp2 ; // deleting pointer to avoid the application from crashing deu to memory overflow.	

	} 
	
	cout << "Repeated name not allowed. " <<endl ;
	cout << "Enter name of new Todo list : " ;
	string input ; 

cin >> input ;
cin.clear();
fflush(stdin);
 
	
	 temp = Todo_List.head ; 
	 // this while loop is used to check for repeatation of todo list name
	while(temp != NULL){
		Node* temp2 =  temp->task_list.head ; 
		if(temp->task_list.name == input){
			cout << "Repeated name not allowed." <<endl ;
				cout << endl <<  "Todo list NOT Created. Enter any key to return to menu : " ;

			return; 
		}
		temp = temp->next ;

	} 
	delete temp ; 
	
	LinkedList* tasklist = new LinkedList(); // creating a new instance of todo list
	tasklist->name = input  ; // setting name of todo list
	Todo_List.InsertNodeAtBeginning(*tasklist); // adding the new todo list to the global list of Todo-lists.
	delete tasklist ; 
	cout << endl <<  "Todo list Created. Enter any key to return to menu : " ;


}

void Display(){
		clearscreen("others");
	cout << "To-Do list names : " << endl << endl ; 
	int i = 1 ; 
	cout << "	Name	" << "		Task" << endl ; 
	Node_for_todo_list* temp = Todo_List.head ; // this instance points to the first todo-list in the list of Todo-lists.
	//this while is used to display todo name and their corresponding task in tabulated form.
	while(temp != NULL){
		Node* temp2 =  temp->task_list.head ; 
		cout << "	" << temp->task_list.name << " 			   " ;
		while(temp2 != NULL){
			cout << temp2->task << ", " ; 
			temp2 = temp2->next ; 
		}
		temp = temp->next ;
			cout << endl << endl ; 
		delete temp2 ;	

	} 
	cout << endl << endl ; 
	delete temp ; 
	
}



void Edit(){
	string id = ""  ;
	
	back : clearscreen("others");
		Node_for_todo_list* temp_new = Todo_List.head ; 
	if(temp_new == NULL){ // if there is not todo-list. operation cannot be person so return to menu.
		clearscreen("others");
	 	cout << "The todo list is empty. Enter any key to return to menu. " ;
	 				getch();

	 	delete temp_new ; 
	 
	 	return;
	}
	Display();
	cout << endl << "Type above TO-DO list name to edit(Enter 0 to return back): " ; // enter the list name to perform operation in that todo-list
	cin >> id ;
	cin.clear();
fflush(stdin);
	if(id == "0"){ // user choose to return to menu
		return ;
	} 

	Node_for_todo_list* selected_todo_list = NULL;
	while( temp_new != NULL ){ // if list of todo-list is not empty. compare the input with list of TODO-LIST.
	// AND get the instance of selected todo-list to perform operation.
		if(temp_new->task_list.name == id){ 
					clearscreen("others");

			selected_todo_list = temp_new ; 
			break ;
			
		}
				
			temp_new = temp_new->next ;
	}
	
		if(selected_todo_list == NULL){ // if the input name is not in the list of stored todo-list. return to menu
			clearscreen("others");
			cout << "list doesnt exist. Enter any key to return to menu" ; 
			delete selected_todo_list;
			getch();
			return ;
		}
	
	
	
	Node* temp = selected_todo_list->task_list.head ; 	
//provide list of task in the selected todo and take used choice to perform operation.
	int option = 0   ; 
	reset :	
	cout << "	Selected To-Do list :	" << selected_todo_list->task_list.name << "		" << endl << endl ; 
	 temp = selected_todo_list->task_list.head ; 	
	int i = 1 ; 
	cout << "	S.N	" << "	Task Name" << endl ; 
	while(temp != NULL){
		cout << "	" << i << "		" << temp->task << endl ; 	
		temp = temp->next ;
		i++ ; 
	
	}
	delete temp ;
 // list of operation that can be performed
   	cout << " " << endl << endl << endl ;
	cout << "1) Insert a new task at begining." << endl ; 
	cout << "2) Insert a new task at end." << endl ; 
	cout << "3) Insert a new task at specific position." << endl ; 
	cout << "4) Delete a task at beginning" << endl ; 
	cout << "5) Delete a task at end" << endl ; 
	cout << "6) Delete a task at specific location" << endl ; 
	cout << "7) Go back to To-Do lists" << endl << endl; 
	
	cout << "Enter operation number[1,2,3,4,5,6,7] : "  ; 
	cin >> option ; 
	clearscreen("others");
	switch (option){
	
		case 1:
			{
			cout << "Enter the Task : " ;
			string task ; 
			cin >> task ; 
			cin.clear();
			fflush(stdin);
			selected_todo_list->task_list.InsertNodeAtBeginning(task);

			option = 0 ; 
			clearscreen("others");
			goto reset ; 
			}
	
		case 2:
			{
			cout << "Enter the Task : " ;
			string task ; 
			cin >> task ; 
			cin.clear();
fflush(stdin);
			selected_todo_list->task_list.InsertNodeAtEnd(task);

			option = 0 ; 
			clearscreen("others");
			goto reset ; 
			}
	
		case 3:
			{
			cout << "Enter the Task : " ;
			string task ; 
			cin >> task ; 
			cin.clear();
fflush(stdin);
			cout << "Enter the position : " ;
			int position ; 
			cin >> position ; 
			selected_todo_list->task_list.InsertNodeAtSpecificPosition(position , task);

			option = 0 ; 
			goto reset ; 
			}
	
		case 4:
			{
			selected_todo_list->task_list.DeleteNodeAtBeginning();

			option = 0 ; 
			goto reset ; 
			}
	
		case 5:
			{
			selected_todo_list->task_list.DeleteNodeAtEnd();

			option = 0 ; 
			goto reset ; 
			}
	
		case 6:
			{
			cout << "Enter the position : " ;
			int position ; 
			cin >> position ; 
			
			selected_todo_list->task_list.DeleteNodeAtSpecificPosition(position);

			option = 0 ; 
			goto reset ; 
			}
	
		case 7:
			{

				option = 0 ;
				goto back ; 
			}
	}	
}
	
void Delete(){
		string id ;

	Node_for_todo_list* temp_new = Todo_List.head ; 
	if(temp_new == NULL){
		clearscreen("others");
	 	cout << "The is no lists. Enter any key to return to menu. " ;
	 
	 	return;
	}
	clearscreen("others");
	Display();
	cout << endl << "Type above TO-DO list name to remove(Enter 0 to return back): " ; 
	cin >> id ;
	cin.clear();
fflush(stdin);

	if(id == "0"){
		return ;
	} 

	Node_for_todo_list* selected_todo_list = NULL;
	int position = 1 ; 
	//find the instance of todo-list from the global list of todo-list and calculated its position.
	while( temp_new != NULL ){
		if(temp_new->task_list.name == id){
					clearscreen("others");

			selected_todo_list = temp_new ; 
			break ;
			
		}
				position++ ; 
			temp_new = temp_new->next ;
	}
	
		if(selected_todo_list == NULL){
			clearscreen("others");
			cout << "List doesnt exist. Enter any key to return to menu" ; 
			return ;
		}
		else {
			// delete the node at the calculated position to delete the todo-list frm global lists of todo list.
			Todo_List.DeleteNodeAtSpecificPosition(position);
				cout << endl <<  "Todo list Removed. Enter any key to return to menu : " ;
		}
	
	
	
	Node* temp = selected_todo_list->task_list.head ; 	
	
}

void EndOfProgram(){
	clearscreen("others");
	cout << endl << "Program terminated" << endl ; 
	return ; 
}

void menu(){
	
	// main menu to provide option to user.
repeate : clearscreen("others");
	int choice = 0 ; 
	cout << "******  TO-DO application in c++  *******" << endl << endl ; 
	cout << "1) Create a TO-DO list." << endl ; 
	cout << "2) Display all TO-DO list." << endl ; 
	cout << "3) Edit tasks in TO-DO list." << endl ; 
	cout << "4) Delete a TO-DO list." << endl ; 
	cout << "5) Exit program" << endl <<endl ; 
	cout << "Enter operation number[1,2,3,4,5] : "  ; 
	cin >> choice ; 

	
 switch (choice){
		case 1 : Create();
						getch();
 
			choice = 0 ; 
			goto repeate ; 
			break ; 
		case 2 : Display();
	
			 
			cout << endl <<  "Enter any key to return to menu : " ;
			getch();
			choice = 0 ; 
			goto repeate ; 
		case 3 : Edit();
			choice = 0 ;
			goto repeate ; 
		case 5: EndOfProgram();
			break ; 
			
		case 4 : Delete();
		
			getch();
			choice = 0 ; 
			goto repeate ; 
			break ; 
	}
}

int main(){
	menu();
	return 0 ; 
}
