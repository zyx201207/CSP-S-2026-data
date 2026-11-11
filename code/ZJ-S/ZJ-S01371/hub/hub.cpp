#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e6 + 10;
int c, t, n, k;
int u[maxn], v[maxn];
vector<int> vec[maxn];
int vis[maxn];
void dfs(int x, int fa, int fr) {
    vis[x] = fr;
    for (int i = 0; i < vec[x].size(); i++) {
        int v = vec[x][i];
        if (v == fa) continue;
        dfs(v, x, fr);
    }
}
int dep[maxn], cnt;
void dfs2(int x, int fa, int mid) {
    dep[x] = 1;
    for (int i = 0; i < vec[x].size(); i++) {
        int v = vec[x][i];
        if (v == fa) continue;
        dfs2(v, x, mid);
        dep[x] = max(dep[x], dep[v] + 1);
    }
    if (dep[x] > mid) cnt++;
}
bool chk(int mid, int u, int v) {
    dfs(u, 0, u);
    dfs(v, 0, v);
    int ans1 = 0x3f3f3f3f, ans2 = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        cnt = 0; dfs2(i, 0, mid);
        if (vis[i] == u) ans1 = min(ans1, cnt);
        else ans2 = min(ans2, cnt);
        if (ans1 + ans2 <= k) return true;
    }
    if (ans1 + ans2 <= k) return true;
    return false;
}
int maxx = 0, maxi;
void dfs3(int x, int fa) {
    dep[x] = dep[fa] + 1;
    if (dep[x] > maxx) {
        maxx = dep[x]; maxi = x;
    }
    for (int i = 0; i < vec[x].size(); i++) {
        int v = vec[x][i];
        if (v == fa) continue;
        dfs3(v, x);
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u[i], &v[i]);
        }
        if (k == 2) {
            int ans = 0x3f3f3f3f;
            for (int ban = 1; ban < n; ban++) {
                for (int i = 1; i < n; i++) {
                    if (i == ban) continue;
                    vec[u[i]].push_back(v[i]);
                    vec[v[i]].push_back(u[i]);
                }
                dfs3(u[ban], 0);
                int st = maxi; maxx = maxi = 0;
                dfs3(st, 0);
                int ans1 = maxx; maxx = maxi = 0;
                dfs3(v[ban], 0);
                st = maxi; maxx = maxi = 0;
                dfs3(st, 0);
                int ans2 = maxx; maxx = maxi = 0;
                ans = min(ans, max(ans1 / 2, ans2 / 2));
                for (int i = 1; i <= n; i++) {
                    vec[i].clear();
                }
            }
            printf("%d\n", ans);
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int ban = 1; ban < n; ban++) {
            for (int i = 1; i < n; i++) {
                if (i == ban) continue;
                vec[u[i]].push_back(v[i]);
                vec[v[i]].push_back(u[i]);
            }
            int l = 0, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (chk(mid, u[ban], v[ban])) r = mid;
                else l = mid + 1;
            }
            ans = min(ans, l);
            for (int i = 1; i <= n; i++) {
                vec[i].clear();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
0 1
10 2
1 2
2 3
2 4
3 5
4 6
4 7
1 8
8 9
9 10
*/
