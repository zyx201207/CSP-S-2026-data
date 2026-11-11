#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int n, m;
long long maxn = -2e9;
void dfs(int depth, long long ans) {
    if (depth >= m) {
        maxn = max(maxn, ans);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            vis[i] = true;
            if (depth == 0) dfs(depth + 1 , a[i]);
            else dfs(depth + 1, ans & a[i]);
            vis[i] = false;
        }
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == m) {
        long long ansn = a[1];
        for (int i = 2; i <= n; i++) {
            ansn &= a[i];
        }
        cout << ansn << endl;
        return 0;
    } else if (m == n - 1) {
        long long maxn1 = a[2];
        for (int i = 3; i <= n; i++) maxn1 &= a[i];
        for (int i = 2; i <= n; i++) {
            long long ands = a[1];
            for (int j = 2; j <= n; j++) {
                if (j != i) ands &= a[i];
            }
            maxn1 = max(maxn1, ands);
        }
        cout << maxn1 << endl;
        return 0;
    } else dfs(0, 0);
    cout << maxn << endl;
    return 0;
}
