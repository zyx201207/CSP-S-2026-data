#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e6 + 10, M = 21, N10 = 4010;
int c, t, n, k;
int lca[N][M], deep[N];
vector<int> mp[N];
int fa[N];
vector<int> e[N];
bool vis[N];
bool base[N];
void build_tree(int node, int d) {
    for(int i = 0;i < mp[node].size();i ++) {
        if(!vis[mp[node][i]]) {
            e[node].push_back(mp[node][i]);
            vis[mp[node][i]] = 1;
            fa[mp[node][i]] = node;
            deep[mp[node][i]] = d + 1;
            build_tree(mp[node][i], d + 1);
        }
    }
}
void init() {
    for(int i = 1;i <= n;i ++) {
        lca[i][0] = fa[i];
    }
    for(int j = 1;j < M;j ++) {
        for(int i = 1;i <= n;i ++) {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }
}
int min_path(int x, int y) {
    int ans = 0;
    if(deep[x] > deep[y]) {
        swap(x, y);
    }
    for(int i = M - 1;i >= 0;i --) {
        if(deep[lca[y][i]] >= deep[x]) {
            y = lca[y][i];
            ans += 1 << (M - 1);
        }
    }
    for(int i = M - 1;i >= 0;i --) {
        if(lca[x][i] != lca[y][i]) {
            x = lca[x][i], y = lca[y][i];
            ans += 1 << M;
        }
    }
    return ans + 2;
}
int dis[N10][N10];
bool check(int mid) {
    for(int i = 1;i <= n;i ++) {
        base[i] = false;
    }
    int sum = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = i + 1;j <= n;j ++) {
            if(dis[i][j] >= mid) {
                sum ++;
                break;
            }
        }
    }
    if(sum <= k) {
        return true;
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t --) {
        scanf("%d %d", &n, &k);
        for(int i = 1;i <= n;i ++) {
            mp[i].clear();
            vis[i] = false;
        }
        for(int i = 1;i < n;i ++) {
            int u, v;
            scanf("%d %d", &u, &v);
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vis[1] = 1;
        deep[1] = 1;
        build_tree(1, 1);
        init();
        if(c <= 10) {
            for(int i = 1;i <= n;i ++) {
                for(int j = 1;j <= n;j ++) {
                    dis[i][j] = min_path(i, j);
                }
            }
            int l = 0, r = 4010, best = 1000;
            while(l <= r) {
                int mid  = (l + r) / 2;
                if(check(mid)) {
                    r = mid - 1;
                    best = mid;
                }else {
                    l = mid + 1;
                }
            }
            cout << best << "\n";
        }
    }
    return 0;
}
