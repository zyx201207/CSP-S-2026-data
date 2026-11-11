#include <bits/stdc++.h>
using namespace std;
int c, t;
vector<int> v[1000005];
int dep[1000005], root, depth;
int f[1000005];
bool vis[1000005];
void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < v[u].size(); i++) {
        if(!vis[v[u][i]]) {
            dep[v[u][i]] = dep[u] + 1;
            if(dep[v[u][i]] > depth) {
                depth = dep[v[u][i]];
                root = v[u][i];
            }
            dfs(v[u][i]);
        }
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--) {
        memset(dep, 0, sizeof(dep));
        for(int i = 0; i <= 1000000; i++) {
            v[i].clear();
        }

        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1);
        cout << depth / 2 << endl;
    }
    return 0;
}
