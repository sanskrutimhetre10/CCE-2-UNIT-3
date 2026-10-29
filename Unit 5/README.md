 Campus Building Connectivity Using BFS and DFS

1. Problem Statement
Develop a C++ program to represent campus buildings using an adjacency matrix and apply Breadth-First Search (BFS) and Depth-First Search (DFS) to explore building connectivity from a selected starting building.

2. Objectives
- To represent campus buildings as vertices of a graph.
- To represent connections between buildings using an adjacency matrix.
- To implement BFS using a queue.
- To implement DFS using recursion.
- To explore connected buildings from a selected starting building.
- To understand the practical application of graph traversal algorithms.

3. Technologies Used
- Programming Language: C++
- Graph Representation: Adjacency Matrix
- Data Structures: Two-dimensional array and queue
- Algorithms: Breadth-First Search (BFS) and Depth-First Search (DFS)
- Compiler: Dev-C++, Code::Blocks, or GCC

4. Data Structures Used
1. Adjacency Matrix
   A two-dimensional array represents the connections between campus buildings. A value of "1" indicates a direct connection, while "0" indicates no direct connection.

2. Queue
   BFS uses a queue to visit connected buildings level by level

3. Visited Array
   A Boolean array keeps track of visited buildings and prevents revisiting them.

4. Recursion
   DFS uses a recursive function to explore connected buildings before backtracking.

5. Algorithms Used
Breadth-First Search (BFS)
1. Select the starting building.
2. Mark the starting building as visited.
3. Insert it into the queue.
4. Remove a building from the queue and display it.
5. Visit all its adjacent, unvisited buildings and insert them into the queue.
6. Repeat until the queue becomes empty.

Depth-First Search (DFS)
1. Select the starting building.
2. Mark it as visited and display it.
3. Check its adjacent buildings.
4. Recursively visit each adjacent building that has not been visited.
5. Backtrack when no unvisited adjacent buildings remain.

6. Program Features
- Represents campus buildings using an adjacency matrix.
- Allows the user to enter the number of buildings and their connections.
- Displays the adjacency matrix.
- Performs BFS traversal from a selected starting building.
- Performs DFS traversal from a selected starting building.
- Validates the number of buildings and starting vertex.
- Provides a menu-driven interface.

7. How to Execute
1. Save the C++ program as "campus_connectivity.cpp".
2. Open the file in a C++ compiler.
3. Compile and run the program.
4. Select option "1" to create the campus graph.
5. Enter the number of buildings and the adjacency matrix.
6. Select option "2" to display the adjacency matrix.
7. Select option "3" to perform BFS.
8. Select option "4" to perform DFS.
9. Select option "5" to exit the program.

Compilation Command
g++ campus_connectivity.cpp -o campus_connectivity

Execution Command
./campus_connectivity

For Windows, run "campus_connectivity.exe".

8. Sample Output
The following example uses four buildings represented by vertices "0", "1", "2", and "3".

Input Adjacency Matrix

0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

BFS Traversal
Starting from building "0":
BFS Traversal starting from Building 0: 0 1 2 3

DFS Traversal
Starting from building "0":
DFS Traversal starting from Building 0: 0 1 3 2

9. Time Complexity
Let "V" represent the number of buildings.
- BFS: O(V²), when an adjacency matrix is used.
- DFS: O(V²), when an adjacency matrix is used.

10. Space Complexity
- Adjacency Matrix: O(V²)
- Visited Array: O(V)
- BFS Queue: O(V)
- DFS Recursion Stack: O(V)

The overall space complexity is O(V²) due to the adjacency matrix.

11. Applications
- Campus building connectivity analysis.
- Campus navigation systems.
- Road and transportation networks.
- Computer network connectivity.
- Graph traversal and path exploration.

12. Conclusion
The program demonstrates the representation of campus buildings using an adjacency matrix and the implementation of BFS and DFS in C++. BFS explores connected buildings level by level using a queue, whereas DFS explores paths recursively before backtracking. These algorithms provide a basic understanding of graph traversal and connectivity analysis.