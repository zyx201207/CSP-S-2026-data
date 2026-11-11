#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int M = 510;
typedef long long ll;
typedef pair<ll,ll> PII;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;

//vector<vector<PII>> adj(N);
int dis[M][M];
int f[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    f[x] = y;
}

vector<PII> edg;

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u -- , v --;
        dis[u][v] = dis[v][u] = 1;
        edg.push_back({u, v});
        dis[i][i] = 0;
    }
    for(int k = 0; k < n; k ++) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int ans = INF;
    for(int mask = 0; mask < (1 << n); mask ++) {
        int cnt = 0;
        vector<int> st(n + 10, 0);
        for(int i = 0; i < n; i ++) {
            if((mask >> i) & 1) {
                cnt ++;
                st[i] = 1;
            }
        }


        if(cnt != k) continue;

        for(int i = 0; i < n; i ++) f[i] = i;
        for(int i = 0; i < n - 1 - 1; i ++) {
            int u = edg[i].first, v = edg[i].second;
            if(!st[u] || !st[v]) continue;
            u == find(u), v == find(v);
            if(u == v) continue;
            merge(u, v);
        }
        cnt = 0;
        for(int i = 0; i < n; i ++) {
            if(!st[i]) continue;
            if(find(i) == i) cnt ++;
        }
        if(cnt > 2) continue;
        int res = 0;
        for(int i = 0; i < n; i ++) {
            int res2 = INF;
            for(int j = 0; j < n; j ++) {
                if(!st[j]) continue;
                res2 = min(res2, dis[i][j]);
            }
            res = max(res, res2);
        }
        ans = min(ans, res);
    }

    cout << ans << endl;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            dis[i][j] = INF;
        }
    }
    edg.clear();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    int t = 1;
    cin >> t;
    memset(dis, 0x3f, sizeof dis);
    while(t --) {
        solve();
    }
    return 0;
}
