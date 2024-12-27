#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countPossibleRoots(int n, vector<pair<int, int>>& edges) {
    unordered_set<int> childNodes;
    for (auto& edge : edges) childNodes.insert(edge.second);
    int possibleRoots = 0;
    for (int i = 1; i <= n; ++i) {
        if (childNodes.find(i) == childNodes.end()) ++possibleRoots;
    }
    return possibleRoots;
}

int main() {
    int n = 6;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {3, 4}, {5, 6}};
    cout << countPossibleRoots(n, edges) << endl;
    return 0;
}
