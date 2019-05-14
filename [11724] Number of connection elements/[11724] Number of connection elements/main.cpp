//
//  main.cpp
//  [11724] Number of connection elements
//
//  Created by 서형중 on 15/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1);
    vector<int> visited(n + 1, false);
    while (m--) {
        int u, v;
        cin >> u >> v;
        matrix[u].push_back(v);
        matrix[v].push_back(u);
    }
    int number_of_connection_elements = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == false) {
            visited[i] = true;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int j = 0; j < matrix[v].size(); ++j) {
                    if (visited[matrix[v][j]] == false) {
                        visited[matrix[v][j]] = true;
                        q.push(matrix[v][j]);
                    }
                }
            }
            ++number_of_connection_elements;
        }
    }
    cout << number_of_connection_elements << "\n";
    return 0;
}
