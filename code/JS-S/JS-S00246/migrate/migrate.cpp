#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int M = 510;
typedef long long ll;
typedef pair<ll,ll> PII;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>> adj(N);

ll x[N];
ll dis[N][3];
ll ans = 0;
ll n, d;
void dij(ll s) {
    queue<PII> q;
    dis[s][0] = 0;
    q.push({0, s});
    while(q.size()) {
        PII T = q.front(); q.pop();
        int di = T.first, u = T.second;

        for(int j = 0; j < adj[u].size(); j ++) {
            int v = adj[u][j].first;
            int w = adj[u][j].second + di;
            if(w <= dis[v][0]) {
                dis[v][2] = dis[v][1];
                dis[v][1] = dis[v][0];
                dis[v][0] = w;
                q.push({w, v});
            } else if(w <= dis[v][1]) {
                dis[v][2] = dis[v][1];
                dis[v][1] = w;
                q.push({w, v});
            } else if(w <= dis[v][2]) {
                dis[v][2] = w;
                q.push({w, v});
            }
        }
    }

    for(int j = s + 1; j <= n; j ++) {
        if(dis[j][0] == dis[j][1] && dis[j][1] < dis[j][2]) {
            ans ++;
        }
    }

    for(int i = 1; i <= n; i ++) {
        dis[i][0] = dis[i][1] = dis[i][2] = INFll;
    }
}

void solve() {

    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        cin >> x[i];
    }

    for(int l = 1, r = 1; l <= n; l ++ ) {
        while(r + 1 <= n && x[r + 1] - x[l] <= d) r ++;
        int u = l;
        for(int v = l + 1; v <= r; v ++ ) {
            PII t;
            t.first = v;
            t.second = 1;
            adj[u].push_back(t);
        }
    }

    for(int i = 1; i <= n; i ++) {
        dij(i);
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i ++) {
        adj[i].clear();
        x[i] = 0;
    }
    ans = 0;
}


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis, 0x3f, sizeof dis);
    int c;
    cin >> c;
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
