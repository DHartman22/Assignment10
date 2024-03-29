//
//  WeightedGraph.h
//  
//  Defines the WeightedGraph class.
//  You SHOULD modify this file.
//  You should not add any additional methods to this class.
//
//  Copyright 2019 David Kopec
//  Modified by Daniel Hartman
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef weighted_graph_hpp
#define weighted_graph_hpp

#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

namespace csi281 {
    
    // V is the type of the vertices
    // W is the type of the weights
    template<typename V, typename W>
    class WeightedGraph {
    public:
        
        // Represents an edge between two vertices with a weight
        struct WeightedEdge {
        public:
            V from;
            V to;
            W weight;
            WeightedEdge(V f, V t, W w) : from(f), to(t), weight(w) {}
            bool operator>(WeightedEdge const &other) const {
                return weight > other.weight;
            }
            bool operator==(WeightedEdge const &other) const {
                return (from == other.from) && (to == other.to) && (weight == other.weight);
            }
        };
        
        // Add a vertex to the graph
        void addVertex(V vertex) {
            adjacencyList.emplace(vertex, list<WeightedEdge>());
        }
        
        // How many vertices are in the graph?
        unsigned int numVertices() {
            return adjacencyList.size();
        }
        
        // Add an edge to the graph
        // *from* is the starting vertex
        // *to* is the ending vertex
        // *weight* is the edge's weight
        // *bidirectional* is whether the edge should be in both directions
        // If *from* and/or *to* do not exist, they are added as vertices
        void addEdge(V from, V to, W weight, bool bidirectional = true) {
            // add from if it's not in the graph
            if (adjacencyList.find(from) == adjacencyList.end()) {
                addVertex(from);
            }
            // add to if it's not in the graph
            if (adjacencyList.find(to) == adjacencyList.end()) {
                addVertex(to);
            }
            // add weighted edges
            adjacencyList[from].push_back(WeightedEdge(from, to, weight));
            if (bidirectional) {
                adjacencyList[to].push_back(WeightedEdge(to, from, weight));
            }
        }
        
        // Return the outgoing weighted edges (as a list) for a vertex
        list<WeightedEdge> neighborsWithWeights(const V &vertex) {
            // ensure we actually have this vertex in the graph
            assert (adjacencyList.find(vertex) != adjacencyList.end());
            return adjacencyList[vertex];
        }
        
        // Determines whether there is an edge between *from* and *to*
        // if either is not in the graph, return false
        bool edgeExists(const V &from, const V &to) {
            if (adjacencyList.find(from) == adjacencyList.end()) {
                return false;
            }
            for (auto &we : adjacencyList[from]) {
                if (we.to == to) { return true; }
            }
            return false;
        }
        
        // Find a minimum-spanning-tree using Jarnik's algorithm
        // Returns a list of WeightedEdges composing the edges
        // in the minimum-spanning-tree
        list<WeightedEdge> mst(V start) {
            // vertices that we have already been to
            unordered_set<V> visited = unordered_set<V>();
            // the final edges in the minimum spanning tree
            list<WeightedEdge> solution = list<WeightedEdge>();
            // the next edges to explore, will always pop/top the smallest weight
            // edge next
            priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>> frontier = priority_queue<WeightedEdge, vector<WeightedEdge>, greater<WeightedEdge>>();
            
            // visit is a lambda expression; think about it like a mini-function
            // that can be called by calling visit(yourVertexGoesHere)
            // this aligns with the inner function visit() from the pseudo code in the slides

			//	1. Pick a starting vertex to be in the minimum spanning
			//	tree
			//	2. Find the lowest - weight edge connecting the minimum
			//	spanning tree to the vertices not yet in the minimum
			//	spanning tree
			//	3. Add the vertex at the end of that lowest - weight edge
			//	to the minimum spanning tree
			//	4. Repeat steps 2 and 3 until every vertex in the graph is
			//	in the minimum spanning tree

            auto visit = [&](V v) {
                // YOUR CODE HERE
				visited.insert(v);
				for (auto& p : neighborsWithWeights(v))
				{
				if (visited.find(p.to) == visited.end()) //pushes unvisited neighbors of v to frontier
				{
					frontier.push(p);
				}
				}
            };
            
			visit(start); //initializes the priority queue by pushing start's neighbors into it

			while (!frontier.empty())
			{
				WeightedEdge node = frontier.top();
				frontier.pop();
				if (visited.find(node.to) != visited.end()) //restarts while loop if the popped node has already been visited
				{
					continue;
				}
				solution.push_back(node); //adds the vertice and its relevant edges to the minimum spanning tree
				visit(node.to); //push node's neighbors into frontier
			}

            return solution;
        }

        // Debug print out the contents of the graph
        void debugPrint() {
            for (auto const& p: adjacencyList) {
                cout << p.first << ": ";
                for (auto const& we: p.second) {
                    cout << "(" << we.to << " " << we.weight << "), ";
                }
                cout << endl;
            }
        }
    private:
        unordered_map<V, list<WeightedEdge>> adjacencyList = unordered_map<V, list<WeightedEdge>>();
    };
}


#endif /* weighted_graph_hpp */
