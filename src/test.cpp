//
//  test.cpp
//
//  Tests to prove your code works.
//  You should NOT modify the end of this file.
//
//  Copyright 2019 David Kopec
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

#include "WeightedGraph.h"
#include "catch.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;
using namespace csi281;

void printEdges(list<typename WeightedGraph<string, int>::WeightedEdge> wes) {
    for (auto &we : wes) {
        cout << "(" << we.from << " -" << we.weight << "> " << we.to << "), ";
    }
    cout << endl;
}

auto totalWeight(list<typename WeightedGraph<string, int>::WeightedEdge> wes) {
    auto total = 0;
    for (auto &we : wes) {
        total += we.weight;
    }
    return total;
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE( "mst() cityGraph1 Test", "[mst]" ) {
    WeightedGraph<string, int> cityGraph1 = WeightedGraph<string, int>();
    cityGraph1.addEdge("Seattle", "Chicago", 2097);
    cityGraph1.addEdge("Seattle", "Denver", 1331);
    cityGraph1.addEdge("Seattle", "San Francisco", 807);
    cityGraph1.addEdge("San Francisco", "Denver", 1267);
    cityGraph1.addEdge("San Francisco", "Los Angeles", 381);
    cityGraph1.addEdge("Los Angeles", "Denver", 1015);
    cityGraph1.addEdge("Los Angeles", "Kansas City", 1663);
    cityGraph1.addEdge("Los Angeles", "Dallas", 1435);
    cityGraph1.addEdge("Denver", "Chicago", 1003);
    cityGraph1.addEdge("Denver", "Kansas City", 599);
    cityGraph1.addEdge("Kansas City", "Chicago", 533);
    cityGraph1.addEdge("Kansas City", "New York", 1260);
    cityGraph1.addEdge("Kansas City", "Atlanta", 864);
    cityGraph1.addEdge("Kansas City", "Dallas", 496);
    cityGraph1.addEdge("Chicago", "Boston", 983);
    cityGraph1.addEdge("Chicago", "New York", 787);
    cityGraph1.addEdge("Boston", "New York", 214);
    cityGraph1.addEdge("Atlanta", "New York", 888);
    cityGraph1.addEdge("Atlanta", "Dallas", 781);
    cityGraph1.addEdge("Atlanta", "Houston", 810);
    cityGraph1.addEdge("Atlanta", "Miami", 661);
    cityGraph1.addEdge("Houston", "Miami", 1187);
    cityGraph1.addEdge("Houston", "Dallas", 239);
    cout << "------cityGraph1------" << endl;
    cityGraph1.debugPrint();
    auto result = cityGraph1.mst("New York");
    cout << "------cityGraph1 mst------" << endl;
    printEdges(result);
    // Are there the right number of edes in the result?
    CHECK( result.size() == (cityGraph1.numVertices() - 1) );
    // Is it the right total weight?
    CHECK( totalWeight(result) == 6513 );
    // Make sure these are all valid edges
    for (auto &we : result) {
        CHECK( cityGraph1.edgeExists(we.from, we.to) );
    }
}

// DO NOT MODIFY THIS TEST CASE
TEST_CASE( "mst() cityGraph2 Test", "[mst]" ) {
    WeightedGraph<string, int> cityGraph2 = WeightedGraph<string, int>();
    cityGraph2.addEdge("Seattle", "Chicago", 1737);
    cityGraph2.addEdge("Seattle", "San Francisco", 678);
    cityGraph2.addEdge("San Francisco", "Riverside", 386);
    cityGraph2.addEdge("San Francisco", "Los Angeles", 348);
    cityGraph2.addEdge("Los Angeles", "Riverside", 50);
    cityGraph2.addEdge("Los Angeles", "Phoenix", 357);
    cityGraph2.addEdge("Riverside", "Phoenix", 307);
    cityGraph2.addEdge("Riverside", "Chicago", 1704);
    cityGraph2.addEdge("Phoenix", "Dallas", 887);
    cityGraph2.addEdge("Phoenix", "Houston", 1015);
    cityGraph2.addEdge("Dallas", "Chicago", 805);
    cityGraph2.addEdge("Dallas", "Atlanta", 721);
    cityGraph2.addEdge("Dallas", "Houston", 225);
    cityGraph2.addEdge("Houston", "Atlanta", 702);
    cityGraph2.addEdge("Houston", "Miami", 968);
    cityGraph2.addEdge("Atlanta", "Chicago", 588);
    cityGraph2.addEdge("Atlanta", "Washington", 543);
    cityGraph2.addEdge("Atlanta", "Miami", 604);
    cityGraph2.addEdge("Miami", "Washington", 923);
    cityGraph2.addEdge("Chicago", "Detroit", 238);
    cityGraph2.addEdge("Detroit", "Boston", 613);
    cityGraph2.addEdge("Detroit", "Washington", 396);
    cityGraph2.addEdge("Detroit", "New York", 482);
    cityGraph2.addEdge("Boston", "New York", 190);
    cityGraph2.addEdge("New York", "Philadelphia", 81);
    cityGraph2.addEdge("Philadelphia", "Washington", 123);
    cout << "------cityGraph2------" << endl;
    cityGraph2.debugPrint();
    auto result = cityGraph2.mst("New York");
    cout << "------cityGraph2 mst------" << endl;
    printEdges(result);
    // Are there the right number of edes in the result?
    CHECK( result.size() == (cityGraph2.numVertices() - 1) );
    // Is it the right total weight?
    CHECK( totalWeight(result) == 5372 );
    // Make sure these are all valid edges
    for (auto &we : result) {
        CHECK( cityGraph2.edgeExists(we.from, we.to) );
    }
}
