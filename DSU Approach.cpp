class Solution {
public:
    vector<int> rank, parent;

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression for optimization
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return; // Already in the same set

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);      // Initialize parent array
        rank.resize(n, 1);     // Initialize rank array

        // Initially, each stone is its own parent (individual component)
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        // Connect stones that share a row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If stones i and j share the same row or column and are in different sets
                if ((stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) &&
                    find(i) != find(j)) {
                    unite(i, j);  // Union the sets
                    components--; // Reduce the number of connected components
                }
            }
        }

        // The maximum number of stones we can remove = total stones - number of components
        return n - components;
    }
};
