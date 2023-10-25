#include <iostream>
#include <vector>
#ifndef MYGRAPH_H
#define MYGRAPH_H
using namespace std;

struct Link {

public:

   int v1, v2;
   float w;

   bool operator<(const Link &other) const
   {
      return w < other.w;
   }
   bool operator==(const Link &other) const
   {
      return v1 == other.v1 && v2 == other.v2 && w == other.w;
   }
};

class MyHelper
{

public:
   MyHelper();
   vector<Link> sortedList;
   vector<Link> MST;
   int numOfNodes;
};

ostream &operator<<(ostream &, const Link &);
class MyGraph {

   int numOfNodes;
   vector<Link> sortedList;

public:
   MyGraph();

   MyGraph(int numOfNodes)
       : numOfNodes(numOfNodes){};

   MyGraph(const MyGraph&);

   bool addEdge(int a, int b, float w);
   void output(ostream& os);
   pair<bool, float> weight(int a, int b);

   // additional helper functions
   void sortGraph();
   vector<Link> findMinimumSpanningTree(MyHelper &m);
   int findRoot(vector<int> &parent, int node);
};

vector<Link> Task1(int n, vector<Link>& pipes, MyHelper& helper);
pair<bool, Link> Task2(int n, vector<Link>& pipes, Link newPipe, MyHelper helper);

#endif