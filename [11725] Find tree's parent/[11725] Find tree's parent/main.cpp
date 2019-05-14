//
//  main.cpp
//  [11725] Find tree's parent
//
//  Created by 서형중 on 14/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define _min(x, y) ((x < y) ? x : y)
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }
    const int root = 1;
    vector<int> depth(n + 1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(root); visited[root] = true;
    int readyqueue_size = (int)q.size();
    while (!q.empty()) {
        static int cnt = 1;
        int v =  q.front();
        q.pop(); --readyqueue_size;
        depth[v] = cnt;
        for (int i = 0; i < matrix[v].size(); ++i) {
            if (visited[matrix[v][i]] == false) {
                visited[matrix[v][i]] = true;
                q.push(matrix[v][i]);
            }
        }
        if (readyqueue_size == 0) {
            ++cnt;
            readyqueue_size = (int)q.size();
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        int parent = i;
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (_min(depth[i], depth[matrix[i][j]]) < depth[i])
                parent = matrix[i][j];
        }
        cout << parent << "\n";
    }
    return 0;
}
