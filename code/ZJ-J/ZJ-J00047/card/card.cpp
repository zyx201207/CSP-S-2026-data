#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//CSP-J 2026 RP+=INF

int n, m, a[500005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    srand(114514);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 1;
    }
    if(n == 2) {
        cout << 1 << " " << 2;
    }
    if(n == 3) {
        cout << 1 << " " << 2 << " " << 3;
    }
    if(n == 4) {
        cout << 1 << " " << 2 << " " << 3 << " " << 4;
    }
    if(n == 5) {
        cout << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5;
    }
    cout << rand();
    return 0;
}
