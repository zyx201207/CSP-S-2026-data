#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 5e5 + 10;

LL n, m, a[N], p[N];

bool check(int k) {
    for(int r = k; r <= n; r++)
        if(a[r] * k - (p[r] - p[r - k]) <= m) return true;
    return false;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
    int L = 1, R = n + 1;
    while(R - L > 1) {
        int M = (L + R) >> 1;
        if(check(M)) L = M;
        else         R = M;
    }
    cout << L << endl;
    return 0;
}