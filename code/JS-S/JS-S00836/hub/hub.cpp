#include <bits/stdc++.h>
using namespace std;
bool l[1005][1005] = {};
void dfs(int s, int e, int t);
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c, t, n, k, u, v;

    cin >> c >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        memset(l,0,sizeof(l));
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            l[u][v] = 1;
            l[v][u] = 1;
        }
        dfs(1, n, l);
        cout << 1 << endl;
    }
    return 0;
}
