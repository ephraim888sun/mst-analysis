
# Minimum Spanning Tree Analysis 

### What is a minimum spanning tree

minimum - sum of the weights is the least

spanning - reaches all the vertices

tree - no cycle

A Minimum Spanning Tree (MST) is an acyclic tree that connects all vertices of a given graph while minimizing the total sum of edge weights.

### Task 1
1. Task 1: Finding the Minimum Spanning Tree (MST)
- Explain that Task1 function in prog2test.cpp calls the Task1 function in MyGraph.cpp.
- Mention that the Task1 function in MyGraph.cpp takes the number of nodes, a vector of links, and a MyHelper object as input.
- Describe that the Task1 function creates a MyGraph object, adds edges to it using the addEdge function, and then finds the MST using the findMinimumSpanningTree function.
- Emphasize that the MST is returned as a vector of links, which is then printed in prog2test.cpp.

### Task 2
2. Task 2: Replacing an Edge in the MST
- Explain that Task2 function in prog2test.cpp calls the Task2 function in MyGraph.cpp.
- Mention that the Task2 function in MyGraph.cpp takes the number of nodes, a vector of links, a new link, and a MyHelper object as input.
- Describe that the Task2 function creates a MyGraph object, initializes a parent vector, and iterates over the sorted list of links in the MyHelper object.
- Explain that if the new link has a smaller weight than the current link, it checks if adding the new link to the MST creates a cycle. If not, it replaces the current link with the new link.
- Emphasize that the function returns a pair indicating whether the edge was replaced and the replaced link, which is then printed in prog2test.cpp.

### Additional
3. Additional Classes and Functions
- Mention the MyGraph class in MyGraph.h and MyGraph.cpp, which represents a graph and provides functions for adding edges, finding the MST, and more.
- Explain the MyHelper class in MyGraph.h, which stores the sorted list of links and the MST.
- Highlight the Link struct in MyGraph.h, which represents an edge in the graph and provides comparison operators.
- Mention the sortGraph function in MyGraph.cpp, which sorts the list of links in ascending order based on weight.
- Explain the findRoot function in MyGraph.cpp, which finds the root of a node in the parent vector.