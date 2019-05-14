//
//  main.cpp
//  [1260]DFS, BFS
//
//  Created by 서형중 on 10/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool edge[1001][1001] =  {{false}};
bool visited_dfs[1000] = {false};
bool visited_bfs[1000] = {false};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        edge[v1][v2] = true;
        edge[v2][v1] = true;
    }

    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (visited_bfs[v] == true)
            continue;
        visited_bfs[v] = true;
        cout << v << " ";
        for (int i = n; i > 0; --i) {
            if (edge[v][i] == true) {
                s.push(i);
            }
        }
    }
    cout << "\n";
    
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(visited_dfs[v] == true)
            continue;
        visited_dfs[v] = true;
        cout << v << " ";
        for (int i = 1; i < 1001; ++i) {
            if (edge[v][i] == true) {
                q.push(i);
            }
        }
    }
    cout << "\n";
    
    return 0;
}
