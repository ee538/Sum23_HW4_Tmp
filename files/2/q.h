#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

/**
 * This function is used by Google Test. Don't touch!
 */
template <class T>
void PrintCollection(T input, bool add_new_line = true) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }";
  if (add_new_line) {
    std::cout << std::endl;
  }
}

//-----------------------------------------------------------------------------
// You can use this enum for implementation of ReachesACycle function below.
enum class NodeStatus { NotVisited, Visiting, Visited };
//-----------------------------------------------------------------------------
// The return value of BFS function.
// You don't need to change this struct, but the BFS function that you implement
// should return a value of this type, so please read and understand it.
struct BFSReturnValue {
  // Distance of root to each node.
  std::vector<int> distance;

  // Maps each node i to a path representing the shortest path from root to node
  // i.
  std::map<int, std::vector<int>> path;

  // The nodes that are visited in BFS order. Note that this is not used to mark
  // if a node is visited or not, but it is a vector that shows the order of the
  // nodes that are visited in BFS order. For example, in a graph with root 0
  // and children of root being 1, 2, the visited value after BFS should be:
  //
  //{0, 1, 2}
  std::vector<int> visited;
};

// Implement your own Graph class.
class Graph {
 public:
  //-----------------------------------------------------------------------------
  // The following functions are implemented. No need to touch!
  //-----------------------------------------------------------------------------
  // The constructor.
  Graph(std::map<int, std::set<int>> &adjacency_list)
      : adjacency_list_(adjacency_list) {}

  // Used to print the graph. Will be called by google test in auto grader.
  void Print() {
    std::cout << "Graph: {" << std::endl;
    for (auto e : adjacency_list_) {
      std::cout << "  " << e.first << ": ";
      PrintCollection(e.second, /*add_new_line=*/false);
      std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
  }

  //-----------------------------------------------------------------------------
  // TODO: Implement the following functions.
  //-----------------------------------------------------------------------------
  // Performs DFS search from root and returns the visited nodes in DFS order.
  // When there is a choice, the node with lower value should be visited first.

  std::vector<int> DFS(int root);

  // Performs DFS search on all nodes and returns the visited nodes in DFS
  // order. When there is a choice, the node with lower value should be visited
  // first. Note that this function does not take any inputs.
  std::vector<int> DFSAll();

  // Performs BFS search from root and returns a result of type BFSReturnValue,
  // which has the following:
  // 1. result.visited (vector): visited nodes in BFS order.
  // 2. result.path (map): a map of node i to a vector, where the vector is the
  // shortest path from root to i.
  // 3. result.distance (vector): element i represents the shortest distance
  // from root to node i.
  //
  // Assume root is a valid node in the graph.
  BFSReturnValue BFS(int root);

  // Returns true if there is at least one path between nodes i and j.
  // Assume i, j are valid nodes in the graph.
  bool IsPathBetweenNodes(int i, int j);

  // Returns true if the graph is bidirectional. A bidirectional graph is a
  // graph in which if edge (i,j) is in E, then the edge (j,i) is also in E.
  // An empty graph is considered bidirectional.
  // A graph of a single node is considered bidirectional.
  bool IsBidirectional();

  // Returns true if the graph is connected, i.e. if we start from each node, we
  // can get to any other node.
  bool IsConnected();

  // Returns true if start_node can reach a cycle
  bool ReachesACycle(int start_node);

  // Returns true if the graph has any cycles
  bool HasCycle();

  // Helper function for ReachesACycle
  bool ReachesACycleHelper(int start_node, std::map<int, NodeStatus> &status);

 private:
  std::map<int, std::set<int>> adjacency_list_;

  // Optionally you can implement and use these functions.
  void DFS_helper(int root, std::map<int, bool> &marks,
                  std::vector<int> &visited);

  void BFS_helper(int root, std::vector<int> &distance,
                  std::vector<int> &previous, std::vector<int> &visited);
};

//-----------------------------------------------------------------------------

// hints
// implement DFS_helper first so you can re-use it in other functions
// in DFS_helper
//    'marks' is to recorded the mapping between node_number and whether it has been visited before or not
//    'visited' is to record the nodes that have been visited
  
// std::vector<int> DFS(int root);
//    use DFS_helper

// std::vector<int> DFSAll()
//  Iterate all elements (e) in adjacency_list_
//  If the current node (e.first) has not been visited before
//    call DFS_helper with e.first as input
// Finally, return 'visited'

// bool Graph::IsPathBetweenNodes(int i, int j) 
//  use DFS_helper, return marks[j]

// bool IsConnected();
//   If call DFS_helper on for every node in adjacency_list_, if for any of the nodes, 
//    marks.size() != adjacency_list_.size() after DFS_helper, it means there are nodes 
//    not visited, and are disconnected
// 
//   To iterate the nodes, use
//         'for(auto e: adjacency_list_)'
//   e.first is just the current node we need to traverse

// In BFS_helper
//    it is the usual BFS + keeping track of
//        the distance between root & current node ('distance')
//        the parent of the current node ('previous')
//    This can be achieved by distance[cur_node] = distance[parent] + 1, and previous[cur_node] = parent
//    For root, we have distance[root] = 0, and previous[root] = -1

// BFSReturnValue Graph::BFS(int root)
//  First call BFS_helper
//  Then init an instance of 'BFSReturnValue'. We can asssign 'previous' and 'visited' from BFS_helper to the struct. The last 
//  element we need is 'path'. We can obtain 'path' by iterating every node in the adjacency list and collect information from
//  'previus'
//  To iterate the nodes, use
//         'for(auto e: adjacency_list_)'
//  e.first is just the current node we need to traverse
//  
//  We can construct the path from back to front from 'previous', and finally use std::reverse to reverse the order


// Check Cycle part: first implement ReachesACycleHelper
// bool Graph::ReachesACycleHelper(int start_node,
//                                 std::map<int, NodeStatus> &status)
// method: recursion, core idea: find if there is a path so that the nodes are all in the Visting status
//  First: handle base cases: 1. if the status of start_node is Visiting
//                       2. if the status of start_node is Visited
//  Set the start_node to be Visiting
//  Iterate all the neighbors of start_node and run ReachesACycleHelper recursively on the neighbor node
//      if ReachesACycleHelper can return true, then there is a cycle
//  Set the status of start_node to be Visited
//  There is no cycle from start_node

// bool Graph::ReachesACycle(int start_node)
//    simply call ReachesACycleHelper

// bool Graph::HasCycle();
// Iterate every node and its neighbors in the adjacency_list_
// For any node that is of status "Unvisited", if ReachesACycleHelper returns true with it, then there is 
//    a cycle in the graph

// bool Graph::IsBidirectional()
// bidirectional means for every node, it is also in the neighbor list of every of its neighbors
// Therefore, we can use two for-loops to iterate every node, and every neighbor of the node
//    We can use std::find to check if the current node is in the neighbor list of any of the neigbor
// If not, it's not bidirectional
