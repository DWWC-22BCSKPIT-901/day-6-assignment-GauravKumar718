#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& tree, string& s, int& maxLength) {
    int max1 = 0, max2 = 0;
    for (int child : tree[node]) {
        if (child == parent) continue;
        int childPath = dfs(child, node, tree, s, maxLength);
        if (s[node] != s[child]) {
            if (childPath > max1) {
                max2 = max1;
                max1 = childPath;
            } else if (childPath > max2) {
                max2 = childPath;
            }
        }
    }
    maxLength = max(maxLength, max1 + max2 + 1);
    return max1 + 1;
}

int longestPath(vector<int>& parent, string& s) {
    int n = parent.size();
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }
    int maxLength = 0;
    dfs(0, -1, tree, s, maxLength);
    return maxLength;
}

int main() {
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";
    cout << longestPath(parent, s) << endl;
    return 0;
}
