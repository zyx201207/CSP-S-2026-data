#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 7;
const int INF = 1e9;
int c, n, m, d, q;
int w[N];
vector<ll> a[505], t[505];
vector<pii> g[N];
vector<int> id[N];
map<pii, ll> way;
ll solve(int st, int ed) {
    ll sum = 1e9;
    vector<vector<ll>> mp(m + 1, vector<ll> (n + 1, INF));
    queue<array<ll, 3>> q;
    for(auto i : id[st]) q.push({st, i, way[{st, i}]});
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(mp[cur[0]][cur[1]] <= cur[2]) continue;
        mp[cur[0]][cur[1]] = cur[2];
        if(cur[0] == ed) sum = min(sum, cur[2] + way[{ed, cur[1]}]);
        for(auto v : g[cur[0]]) {
            if(v.se == cur[1]) q.push({v.fi, v.se, cur[2]});
            else q.push({v.fi, v.se, cur[2] + way[{cur[0], cur[1]}] + way[{cur[0], v.se}]});
        }
    }
    return sum;
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>> c>> n>> m>> d>> q;
    for(int i = 1; i <= m; i++) cin>> w[i];
    for(int i = 1; i <= n; i++) {
        int k;
        cin>> k;
        a[i].resize(k + 1);
        t[i].resize(k + 1);
        for(int j = 1; j <= k; j++) {
            cin>> a[i][j]>> t[i][j];
            way[{a[i][j], i}] = t[i][j];
            id[a[i][j]].pb(i);
            if(j != 1) {
                g[a[i][j]].pb({a[i][j - 1], i});
                g[a[i][j - 1]].pb({a[i][j], i});
            }
        }
    }
    while(q --) {
        int x, y;
        cin>> x>> y;
        cout<< solve(x, y) + w[x] + w[y]<< "\n";
    }
    return 0;
}
