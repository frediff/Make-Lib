# Data Structures Implementation

#### This directory contains the implementation of some data structures and the make file to build and install a dynamic library out of it.

- `LLIST`: Data type for a singly linked list of `NODE`s. A `NODE` is a C structure with two fields, `val` (of type `int`) and `next` (of type pointer to `NODE`). The `LLIST` type supports the following functions:
    - `LLIST createList()`: Creates an empty linked list, and returns it
    - `int searchList(LLIST H, int k)`: Searches for the value `k` in the list `H`. Returns `1` if `k` is found, `0` otherwise.
    - `LLIST insertAtFront(LLIST H, int k)`: Inserts the value `k` at the beginning of the list `H`. Returns the new list.
    - `LLIST insertAtEnd(LLIST H, int k)`: Inserts the value `k` at the end of the list `H`. Returns the new list.
    - `LLIST deleteFromFront(LLIST H, int *k)`: Deletes the first element from the list and returns the value stored in that node using the pointer `k`. Returns the new list as the return value.
    - `LLIST deleteFromEnd(LLIST H, int *k)`: Deletes the last element from the list and returns the value stored in that node using the pointer `k`. Returns the new list as the return value.
    - `LLIST deleteList(LLIST H, int k)`: Deletes the value `k` from the list `H` if it is present and returns the new list. If the value `k` occurs multiple times, only its first occurrence in the list is deleted.

*The `LLIST` data structure is implemented in the C file `llist.c`.*

- `STACK`: Data type for a stack implemented using the LLIST data structure. The `STACK` type supports the following functions:
    - `STACK createStack(): Creates an empty stack, and returns it.
    - `int isEmptyStack(STACK S)`: Returns `1` if the stack `S` is empty, `0` otherwise.
    - `STACK push(STACK S, int k)`: Pushes a value `k` in the stack `S`, and returns the new stack.
    - `STACK pop(STACK S, int *k)`: Pops the top element from the stack, and returns that element using the pointer `k`. Returns the new stack as the return value.

*The `STACK` data structure is implemented in the C file `stack.c`.*

- `QUEUE`: Data type for a queue implemented using the `LLIST` data structure. The `QUEUE` type supports the following functions:
    - `QUEUE createQueue()`: Creates an empty queue, and returns it.
    - `int isEmptyQueue(Queue Q)`: Returns `1` if the queue `Q` is empty, `0` otherwise.
    - `QUEUE enqueue(QUEUE Q, int k)`: Adds a value `k` to the back of the queue, and returns the new queue.
    - `QUEUE dequeue(QUEUE Q, int *k)`: Removes the element at the front and returns that element using the pointer `k`. Returns the new queue as the return value.

*The `QUEUE` data structure is be implemented in the C file `queue.c`.*

- `HEAP`: Data type for a min-heap. The `HEAP` type is implemented with an array of size `100` and supports the following functions:
    - `HEAP createHeap()`: Creates an empty heap, and returns it.
    - `int findMin(HEAP H)`: Returns the minimum value in the heap `H`.
    - `HEAP extractMin (HEAP H)`: Deletes the minimum value from the heap and returns the modified heap.
    - `HEAP insertHeap(HEAP H, int k)`: Inserts the value `k` in the heap `H`, and returns the new heap.
    - `int isFullHeap(HEAP H)`: Returns `1` if the heap is full, `0` otherwise.
    - `int isEmptyHeap(HEAP H)`: Returns `1` if the heap is empty, `0` otherwise.

*The `HEAP` data structure is to be implemented in the C file `heap.c`.*

- `UNION_FIND`: Data type that implements a union-find data structure. `NODE_PTR` points to a node in the union-find forest. The union-find data structure is an array of such pointers. The data type supports the following functions:
    - `UNION_FIND createUF(int n)`: Creates a `UNION_FIND` data structure that can store `n` node pointers. Initially, all these pointers are `NULL`.
    - `UNION_FIND makeSetUF(UNION_FIND F, int x, int *i)`: Creates a singleton set (a node) for the element `x`, adds to `F` a pointer to that node, and returns the modified `UNION_FIND` structure. An `int` pointer is passed additionally to return the insertion index.
    - `NODE_PTR findUF(UNION_FIND F, int i)`: Returns the `ID` of the set to which the element pointed to by the `i`-th pointer in `F` belongs. The `ID` is a pointer to the root node of the tree containing that element. Make sure that the index `i` corresponding to the element being searched is known beforehand when this function is called.
    - `void unionUF(UNION_FIND F, int i, int j)`: Merges the sets containing the elements pointed to by the `i`-th and the `j`-th pointers of `F`. Make sure again that the indices `i` and `j` corresponding to the elements are known beforehand when this function is called. The merging heuristic used is: The tree
with the smaller number of nodes is made a subtree of the tree with the larger number of nodes.

*The `UNION_FIND` data structure is to be implemented in the C file `union_find.c`.*

The individual data structures also provide a deallocation routine as follows:
- For linked-list: `LLIST deallocateList(LLIST)`
- For stack: `STACK deallocateStack(STACK)`
- For queue: `QUEUE deallocateQueue(QUEUE)`
- For heap: `HEAP deallocateHeap(HEAP)`
- For union-find: `UNION_FIND deallocateUF(UNION_FIND)`

***The installation dependencies are present in `makefile.basic`.***

***Always make sure that the `makefile` is run with root permission.***
