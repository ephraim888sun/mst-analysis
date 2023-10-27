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
      std::swap(a, b);
   }
   if (a > numOfNodes || b > numOfNodes)
   {
      return false;
   }
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
      std::swap(a, b);
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
         mst.emplace_back(edge);
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
   helper.numOfNodes = n;
   return graph.findMinimumSpanningTree(helper);
}

pair<bool, Link> Task2(int n, vector<Link> &pipes, Link newPipe, MyHelper helper)
{
   MyGraph graph;
   vector<Link> mst;
   vector<int> parent(helper.numOfNodes + 1, -1);
   int counter = 0;
   pair<bool, Link> answer = {false, {-1, -1, -1}};
   for (const Link &edge : helper.sortedList)
   {
      if (answer.first == false && newPipe.w < edge.w)
      {
         int rootA = graph.findRoot(parent, newPipe.v1);
         int rootB = graph.findRoot(parent, newPipe.v2);
         if (rootA != rootB)
         {
            counter++;
            mst.push_back(newPipe);
            parent[rootA] = rootB;
            answer.first = true;
            if (counter >= helper.numOfNodes - 1)
            {
               break;
            }
         }
      }
      int rootA = graph.findRoot(parent, edge.v1);
      int rootB = graph.findRoot(parent, edge.v2);
      if (rootA != rootB)
      {
         counter++;
         mst.push_back(edge);
         parent[rootA] = rootB;
         if (counter >= helper.numOfNodes - 1)
         {
            break;
         }
      }
   }
   if (answer.first == false)
   {
      return answer;
   }
   // otherwise search the mst for which edge is not in it compared to the new one.
   // mst is ordered by size
   int offset = 0;
   for (int i = 0; i < helper.MST.size(); i++)
   {
      if (mst[i] == newPipe)
         offset++;
      if (mst[i + offset].w != helper.MST[i].w)
      {
         return {true, helper.MST[i]};
      }
   }
   // Add a default return statement
   return {false, {-1, -1, -1}};
}