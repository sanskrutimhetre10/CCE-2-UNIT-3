1. Project Title
Develop a Knockout Cricket Tournament Tree, Compute Height, Depth of Any Node and Number of Nodes at Each Level, and Verify the Maximum-Nodes Formula

2. Problem Statement
A knockout cricket tournament consists of multiple rounds in which teams compete against each other, and the winner of each match advances to the next round. Representing such a tournament in a structured way helps us understand its organization and analyze its properties.
The aim of this project is to develop a knockout cricket tournament using a binary tree in C++. The program calculates the height of the tree, finds the depth of any specified node, counts the number of nodes at each level, and verifies the mathematical formula for the maximum number of nodes at a particular level of a binary tree.

3. Objectives
1. To develop a binary tree representing an eight-team knockout cricket tournament.
2. To calculate the height of the tournament tree.
3. To find the depth of any team or match node.
4. To count the number of nodes present at each level.
5. To verify the maximum-nodes formula \(2^l\), where \(l\) is the level number.
6. To verify the maximum-total-nodes formula \(2^{h+1}-1\), where \(h\) is the tree height.
7. To understand the application of binary trees, recursion, and level-order traversal in C++.

4. Theory
Binary Tree
A binary tree is a non-linear data structure in which each node can have at most two children, called the left child and the right child.
In this project, the tournament is represented as a binary tree. Each team is represented by a leaf node, while each match is represented by an internal node. The root node represents the grand final.
Knockout Tournament Structure
An eight-team knockout tournament contains:
- 4 quarterfinal matches
- 2 semifinal matches
- 1 final match
Each match combines two competing teams or two earlier matches.The tournament tree contains eight team nodes and seven match nodes, giving a total of 15 nodes.

Important Terminology
Height: The number of edges in the longest path from the root to a leaf node.
Depth: The number of edges from the root to a particular node. The root has depth 0.
Level: The position of a node in the tree, with the root at level 0.
Leaf node: A node that has no children. In this project, the team names are leaf nodes.

Maximum-Nodes Formula
The maximum number of nodes at level  in a binary tree is:
\[
N_l=2^l
\]

Therefore:
- Level 0: \(2^0=1\) node
- Level 1: \(2^1=2\) nodes
- Level 2: \(2^2=4\) nodes
- Level 3: \(2^3=8\) nodes
The maximum number of nodes in a binary tree of height \(h\) is:
\[
N=2^{h+1}-1
\]

For a tournament tree of height 3:
\[
N=2^{3+1}-1=15
\]

The actual node counts match these maximum values because the tournament tree is a full binary tree.

5. Algorithm
1. Start the program.
2. Define a node structure containing a name, a left pointer, and a right pointer.
3. Create eight team nodes.
4. Create four quarterfinal match nodes and connect the corresponding team nodes.
5. Create two semifinal nodes and connect the quarterfinal nodes.
6. Create the grand final node and connect the two semifinal nodes.
7. Calculate the height recursively.
8. Use level-order traversal to count the nodes at each level.
9. Calculate the maximum number of nodes at each level using \(2^l\).
10. Compare the actual node count with the calculated maximum.
11. Verify the total-node formula \(2^{h+1}-1\).
12. Accept a node name and calculate its depth.
13. Display the results.
14. Stop the program.

6.Flowchart
                                          
                                                                               
                                                                                
Start-->Create binary tree node structure--->Build 8-team knockout tournament-->Calculate tree height-->Count nodes at each level-->Calculate maximum nodesusing 2^l-->Actual count equals maximum?--Display formula verifiedDisplay count differs frommaximumVerify total nodes formulaEnter node nameFind depth of specified nodeDisplay height, counts, anddepthStopYesNo





7. C++ Program
This program builds the tournament tree, calculates its height, counts nodes at every level, verifies both formulas, and finds the depth of a node entered by the user.

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    string name;
    Node *left, *right;

    Node(string n) {
        name = n;
        left = right = nullptr;
    }
};

class Tournament {
    Node* root;

    int height(Node* n) {
        if (n == nullptr) return -1;
        return 1 + max(height(n->left), height(n->right));
    }

    int findDepth(Node* n, string name, int d) {
        if (n == nullptr) return -1;
        if (n->name == name) return d;

        int result = findDepth(n->left, name, d + 1);
        if (result != -1) return result;

        return findDepth(n->right, name, d + 1);
    }

public:
    Tournament() {
        Node* q1 = new Node("India vs Pakistan");
        q1->left = new Node("India");
        q1->right = new Node("Pakistan");

        Node* q2 = new Node("Australia vs England");
        q2->left = new Node("Australia");
        q2->right = new Node("England");

        Node* q3 = new Node("South Africa vs New Zealand");
        q3->left = new Node("South Africa");
        q3->right = new Node("New Zealand");

        Node* q4 = new Node("Sri Lanka vs Bangladesh");
        q4->left = new Node("Sri Lanka");
        q4->right = new Node("Bangladesh");

        Node* s1 = new Node("Semifinal 1");
        s1->left = q1;
        s1->right = q2;

        Node* s2 = new Node("Semifinal 2");
        s2->left = q3;
        s2->right = q4;

        root = new Node("Grand Final");
        root->left = s1;
        root->right = s2;
    }

    void analyze() {
        int h = height(root);
        map<int, int> counts;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        int total = 0;

        while (!q.empty()) {
            Node* current = q.front().first;
            int level = q.front().second;
            q.pop();

            counts[level]++;
            total++;

            if (current->left)
                q.push({current->left, level + 1});

            if (current->right)
                q.push({current->right, level + 1});
        }

        cout << "\nTOURNAMENT TREE REPORT\n";
        cout << "Tree Height: " << h << "\n\n";

        cout << "Nodes at Each Level:\n";
        for (auto p : counts) {
            int maximum = 1 << p.first;

            cout << "Level " << p.first
                 << ": Actual = " << p.second
                 << ", Maximum = " << maximum
                 << " -> "
                 << (p.second == maximum
                     ? "VERIFIED" : "NOT MAXIMUM")
                 << "\n";
        }

        int expected = (1 << (h + 1)) - 1;

        cout << "\nTotal Nodes: " << total << "\n";
        cout << "Maximum Total Nodes: " << expected << "\n";
        cout << "Total Formula: "
             << (total == expected ? "VERIFIED" : "NOT EQUAL")
             << "\n";

        string name;
        cout << "\nEnter node name to find its depth: ";
        getline(cin >> ws, name);

        int d = findDepth(root, name, 0);

        if (d == -1)
            cout << "Node not found.\n";
        else
            cout << "Depth of " << name << ": " << d << "\n";
    }
};

int main() {
    Tournament t;
    t.analyze();
    return 0;
}



8. Sample Input
The tournament teams are predefined in the program. The user enters a node name to find its depth.

Enter node name to find its depth: India
Other valid queries include Grand Final, Semifinal 1, and India vs Pakistan.

9. Sample Output

TOURNAMENT TREE REPORT
Tree Height: 3

Nodes at Each Level:
Level 0: Actual = 1, Maximum = 1 -> VERIFIED
Level 1: Actual = 2, Maximum = 2 -> VERIFIED
Level 2: Actual = 4, Maximum = 4 -> VERIFIED
Level 3: Actual = 8, Maximum = 8 -> VERIFIED

Total Nodes: 15
Maximum Total Nodes: 15
Total Formula: VERIFIED

Enter node name to find its depth: India
Depth of India: 3

Result Analysis
Level	Actual nodes	Maximum nodes (\(2^l\))
0	1	1
1	2	2
2	4	4
3	8	8
Total	15	15
The output verifies that the tournament tree contains 15 nodes and has a height of 3. Every level contains the maximum possible number of nodes, and the total-node formula is verified.

10. Applications
- Representing knockout tournaments in sports.
- Understanding hierarchical data structures.
- Practising binary tree traversal and recursion.
- Calculating tree height, node depth, and level-wise node counts.
- Verifying mathematical properties of binary trees.

11. Conclusion
The project successfully develops a knockout cricket tournament tree using a binary tree in C++. It calculates the height of the tree, finds the depth of a specified node, counts the nodes at each level, and verifies the maximum-nodes formula.
The results demonstrate that the eight-team tournament has a height of 3 and contains 15 nodes. The maximum number of nodes at each level follows the formula \(2^l\), while the maximum total number of nodes follows \(2^{h+1}-1\).
Thus, the project demonstrates the practical application of binary trees and helps develop an understanding of recursion, level-order traversal, and tree analysis.

12. Complexity Analysis
Let \(n\) be the total number of nodes in the tree.
Operation	Time complexity
Building the tournament tree	\(O(n)\)
Calculating height	\(O(n)\)
Counting nodes at each level	\(O(n)\)
Finding the depth of a node	\(O(n)\)
The overall space complexity is \(O(n)\), because the tree and the level-order traversal queue may store up to \(n\) nodes.
