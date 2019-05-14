//
//  main.cpp
//  [13439] Factorial with recurrence relation
//
//  Created by 서형중 on 14/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <cstdio>
using namespace std;
#define MOD 1000000009

int s[1001][101] = {0};
int s_func(int n, int k) {
    if (n == 0)
        return s[0][k] = 1;
    if (k == 0)
        return s[n][0] = n;
    
    int &ret = s[n][k];
    if (ret > 0)
        return ret;
    return ret = (s_func(n, k - 1) * s_func(n - 1, k))% MOD;
}
int cnt_of_aliquot(int n) {
    int i, cnt = 0;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            cnt += 2;
        }
    }
    if (i * i == n) {
        ++cnt;
    }
    return cnt;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", cnt_of_aliquot(s_func(n, k)));
    return 0;
}
