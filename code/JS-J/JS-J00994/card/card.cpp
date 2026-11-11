#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, maxm = 3e5 + 5;
int n, m;
int a[maxn], vis[maxm], ans[maxm];
stack<int> st;
void tp_m2() {
    int cnt = 0;
    if (a[n] == 1){
        for(int i = 1; i <= n; i++) if (a[i] == 2) cnt++;
        cout << n << " " << cnt;
    }
    if (a[n] == 2){
        for(int i = 1; i <= n; i++) if (a[i] == 1) cnt++;
        cout << cnt << " " << n;
    }
}
void tp_a() {
    a[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) {
        if(a[i + 1] > a[i]) cout << i << " ";
    }
}
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    bool tpa = 1;
    int maxx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (maxx > a[i]) tpa = 0;
        maxx = max(maxx, a[i]);
    }
    if (m == 2) {
        tp_m2();
        return 0;
    }
    if (tpa) {
        tp_a();
        return 0;
    }
    for (int t = 1; t <= n; t++) {
        while (!st.empty()) st.pop();
        memset(vis, 0, sizeof(vis));
        for (int i = t; i <= n; i++) {
            if (vis[a[i]]) {
                while (!st.empty()) {
                    st.pop();
                    if (int(st.top()) == int(a[i])) break;
                }
                vis[a[i]]--;
            }
            st.push(a[i]);
            vis[a[i]]++;
        }
        for (int i = 1; i <= m; i++) {
            if (vis[i]) ans[i]++;
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
