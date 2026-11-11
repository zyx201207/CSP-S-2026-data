#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
long long t[500005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        bool vis[500005];
        stack<int> s;
        memset(vis, false, sizeof(vis));
        for (int j = i; j <= n; j++) {
            if (!vis[a[j]]) {
                s.push(a[j]);
                vis[a[j]] = true;
            } else {
                while (s.top() != a[j]) {
                    vis[s.top()] = false;
                    s.pop();
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            if (vis[j]) t[j]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << t[i] << (i == m ? "" : " ");
    }
    return 0;
}
