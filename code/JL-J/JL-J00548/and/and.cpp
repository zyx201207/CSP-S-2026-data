#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200010];
long long maxx;
int b[200010];

void dfs (int x, int y) {
    if (y == m) {
        long long ans = b[0];
        for (int i = 1; i < m; i++) {
            ans = ans & b[i];
        }
        maxx = max(maxx, ans);
        return;
    }
    for (int i = x + 1; i <= n; i++) {
        b[y] = a[i];
        dfs(i, y + 1);
    }
}

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << maxx;
    return 0;
}
