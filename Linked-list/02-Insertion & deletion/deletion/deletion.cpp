// A complete working C++ program to
// demonstrate deletion in singly
// linked list with class
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node{
public:
	int data;
	Node* next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the
// list.
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteNodeatPosition(Node** head_ref, int position)
{
 
    // If linked list is empty
    if (*head_ref == NULL)
        return;
 
    // Store head node
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0) {
 
        // Change head
        *head_ref = temp->next;
 
        // Free old head
        free(temp);
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
 
    // Unlink the deleted node from list
    temp->next = next;
}
 
// // This function prints contents of linked
// // list starting from the given node
// void printList(Node* node)
// {
//     while (node != NULL) {
//         cout << node->data << " ";
//         node = node->next;
//     }
// }
 
// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
	
	// Store head node
	Node* temp = *head_ref;
	Node* prev = NULL;
	
	// If head node itself holds
	// the key to be deleted
	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next; // Changed head
		delete temp;		 // free old head
		return;
	}

	// Else Search for the key to be deleted,
	// keep track of the previous node as we
	// need to change 'prev->next' */
	else
	{
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return;

	// Unlink the node from linked list
	prev->next = temp->next;

	// Free memory
	delete temp;
	}
}

// This function prints contents of
// linked list starting from the
// given node
void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

// Driver code
int main()
{
	
	// Start with the empty list
	Node* head = NULL;

	// Add elements in linked list
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List: ");
	printList(head);

	deleteNode(&head, 1);
	deleteNodeatPosition(&head, 2);
	puts("\nLinked List after Deletion of 1: ");
	
	printList(head);
	
	return 0;
}

// This code is contributed by ac121102
