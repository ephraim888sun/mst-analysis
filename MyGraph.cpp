#include <iostream>
#include "MyGraph.h"


ostream& operator<<(ostream& os, const Link& l)
{
   os << l.v1 << " " << l.v2 << " " << l.w;
   return os;
}

MyGraph::MyGraph()
{

}

MyGraph::MyGraph(const MyGraph&)
{

}

bool MyGraph::addEdge(int a, int b, float w)
{
   if (b < a)
   {
      int temp = a;
      a = b;
      b = temp;
   }
   if (a > numOfNodes || b > numOfNodes)
      return false;
   sortedList.push_back(Link{a, b, w});
   return true;
}

void MyGraph::output(ostream& os)
{
   os << numOfNodes << "\n";
   for (auto l : sortedList)
   {
      os << l.v1 << " " << l.v2 << " " << l.w << "\n";
   }
}

pair<bool, float> MyGraph::weight(int a, int b)
{
   pair<bool, float> res = {false, -1};
   if (b < a)
   {
      int temp = a;
      a = b;
      b = temp;
   }
   for (auto node : sortedList)
   {
      if (node.v1 == a && node.v2 == b)
      {
         res.first = true;
         res.second = node.w;
         break;
      }
   }
   return res;
}

void MyGraph::sortGraph()
{
   sort(sortedList.begin(), sortedList.end());
}

int MyGraph::findRoot(vector<int> &parent, int node)
{
   while (-1 != parent[node])
   {
      node = parent[node];
   }
   return node;
}

vector<Link> MyGraph::findMinimumSpanningTree(MyHelper &mh)
{
   sortGraph();
   mh.sortedList = sortedList;
   vector<Link> mst;
   vector<int> parent(numOfNodes + 1, -1);
   int counter = 0;
   for (const Link &edge : sortedList)
   {
      int rootA = findRoot(parent, edge.v1);
      int rootB = findRoot(parent, edge.v2);
      if (rootA != rootB)
      {
         counter++;
         mst.push_back(edge);
         parent[rootA] = rootB;
         if (counter >= numOfNodes - 1)
         {
            break;
         }
      }
   }
   mh.MST = mst;
   return mst;
}

MyHelper::MyHelper()
{
}

vector<Link> Task1(int n, vector<Link>& pipes, MyHelper& helper)
{
   MyGraph graph(n);
   for (auto a : pipes)
   {
      graph.addEdge(a.v1, a.v2, a.w);
   }
   return graph.findMinimumSpanningTree(helper);
}

pair<bool, Link> Task2(int n, vector<Link>& pipes, Link newPipe, MyHelper helper)
{
  Link l1;
  pair<bool, Link> sol;
  sol.first = true;
  sol.second = newPipe;
  return sol;
}
