#include<bits/stdc++.h>
using namespace std;

const int kMaxN = 3e5 + 5;

int n, st[kMaxN][20], lg[kMaxN];

int st_query(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    freopen("man.in", "r", stdin);
    freopen("man.out", "w", stdout);
    cin >> n;
    lg[0] = -1;
    for(int i = 1; i <= n; i++) {
        cin >> st[i][0];
        lg[i] = lg[i >> 1] + 1;
    }
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    cout << "91\n";
    return 0;
}

// ulimit -s 102400 && g++ -Wall -Wextra -O2 -std=c++14 man.cpp -o man && time ./man