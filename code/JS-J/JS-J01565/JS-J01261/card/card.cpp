#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int sum[300005];
int a[500005];
int vis[300005];
stack<int> st;
void x (int i) {
    memset(vis, 0, sizeof(vis));
    for (int j = i; j <= n; j ++) {
        st.push(a[j]);
        vis[a[j]] ++;
        int u = st.top();
        if (vis[u] == 2) {
            st.pop();
            while (st.top() != u) {
                int v = st.top();
                vis[v] -= 1;
                st.pop();
            }
            vis[u] -= 1;
        }
    }
    for (int i = 1; i <= m; i ++) {
        if (vis[i] != 0) sum[i] ++;
    }
}
 signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n;  i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        x(i);
    }
    sum[a[n]] = n;
    for (int i = 1; i <= m; i ++) {
        cout << sum[i] << " ";
    }
     return 0;
 }
