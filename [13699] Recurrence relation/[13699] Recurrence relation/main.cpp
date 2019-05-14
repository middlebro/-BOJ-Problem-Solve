//
//  main.cpp
//  [13699] Recurrence relation
//
//  Created by 서형중 on 14/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int ll;
ll t[36];
ll recFunc(int n) {
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            t[i] += t[j] * t[i - 1 - j];
        }
    }
    return t[n];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    t[0] = 1;
    
    int n;
    cin >> n;
    cout << recFunc(n) << endl;
    
    return 0;
}
