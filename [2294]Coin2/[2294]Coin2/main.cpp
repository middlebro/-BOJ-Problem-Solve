//
//  main.cpp
//  [2294]Coin2
//
//  Created by 서형중 on 08/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    
    vector<int> coin_cost;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        coin_cost.push_back(value);
    }
    sort(coin_cost.begin(), coin_cost.end(), greater<int>());
    for (int i = 1; i < coin_cost.size(); ++i) {
        if (coin_cost[i - 1] == coin_cost[i])
            coin_cost.erase(coin_cost.begin() + i--);
    }
    vector<int> cnt(n,0);
    bool impossible = true;
    for (int k = 0; k < n; ++k) {
        int rem = q;
        for (int j = k; j < n; ++j) {
            int i = coin_cost[j];
            if((rem / i > 0) && (rem - (rem / i) * i >= 0)) {
                cnt[k] += rem / i;
                rem -= (rem / i) * i;
            }
            if (rem == 0) {
                impossible = false;
                break;
            }
        }
    }

    sort(cnt.begin(), cnt.end());
    cout << ((impossible) ? -1 : cnt[0]) << "\n";
    
    return 0;
}
