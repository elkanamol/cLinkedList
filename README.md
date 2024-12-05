# Linked List Implementation in C

A simple interactive console application that implements a singly linked list with basic operations.

## Features

- Add nodes to the beginning of the list
- Remove nodes by value
- Insert nodes at specific positions
- Print the entire list
- Input validation and error handling

## Menu Options

1. Add a node - Adds a new node at the beginning of the list
2. Remove a node - Removes the first occurrence of a specified value
3. Insert a node - Inserts a new node at a specified position
4. Print list - Displays all nodes in the format: `value->value->...->NULL`
5. Quit - Exits the program and frees all allocated memory

## Technical Details

- Written in C
- Uses dynamic memory allocation
- Implements proper memory cleanup
- Includes input validation to handle invalid user input
- Forward declaration of Node structure for better type safety

## Usage Example

```c
// Add nodes
Enter the data you want to add to the list: 5
5->NULL

// Insert at position
Enter the data you want to insert to the list: 10
Enter the location you want to insert the node to: 1
5->10->NULL

// Remove node
Enter the data you want to remove from the list: 5
10->NULL
```
## Memory Management
The program automatically frees all allocated memory when exiting, preventing memory leaks. Each node is properly deallocated when removed from the list.

## Error Handling
- Validates all numeric inputs
- Handles malloc failures
- Checks for invalid list positions during insertion
- Provides feedback for unsuccessful operations

## Building and Running
Compile using a C compiler:

```gcc -o linked_list linked_list.c```



Run the executable:

```./linked_list```

This README provides a comprehensive overview of the implementation, its features, and how to use it. Would you like me to expand on any particular section?
