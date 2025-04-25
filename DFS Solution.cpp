class Solution {
public:
    // DFS function to mark all connected stones (sharing row or column)
    void dfs(vector<vector<int>>& stones, int i, vector<bool>& visited) {
        visited[i] = true;  // Mark current stone as visited

        for (int j = 0; j < stones.size(); j++) {
            // If stone `j` shares row or column with stone `i` and is not visited
            if (!visited[j] && (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])) {
                dfs(stones, j, visited);  // Recursively visit all connected stones
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<bool> visited(stones.size(), false);  // Track visited stones
        int components = 0;  // Count of connected components (islands)

        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
                dfs(stones, i, visited);  // Start DFS for each unvisited stone
                components++;  // New connected component found
            }
        }

        // Maximum stones we can remove = total stones - number of connected components
        return stones.size() - components;
    }
};
