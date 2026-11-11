#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n % 2 == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}

