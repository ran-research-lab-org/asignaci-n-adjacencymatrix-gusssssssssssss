#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(8);
  G.addEdge(0,1);
  G.addEdge(0,5);
  G.addEdge(1,6);
  G.addEdge(3,2);
  G.addEdge(5,0);
  G.addEdge(5,1);
  G.addEdge(5,2);
  G.addEdge(7,6);

  G.print();

  cout << "Amount of edges: " << G.numEdges() << endl;
  for(int i = 0; i < 8; ++i)
    cout << "Node " << i << "'s in degree: " << G.inDegree(i) << endl;
  
  cout << "Is node 6 an influencer? " << std::boolalpha << G.isInfluencer(6) << endl;
  cout << "Is node 2 an influencer? " << std::boolalpha << G.isInfluencer(2) << endl;
  cout << "Is node 0 an influencer? " << std::boolalpha << G.isInfluencer(0) << endl;

}
