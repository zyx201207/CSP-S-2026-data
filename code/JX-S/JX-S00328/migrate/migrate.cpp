#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e6 + 7;
const int INF = 1e9;
int c, T, n;
ll d;
vector<int> g[N];
set<pii> s;
ll x[N];
void bfs(int st) {
    vector<int> cnt(n + 1, 0), dis(n + 1, INF);
    queue<pii> q;
    dis[st] = 0;
    q.push({st, 0});
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        if(dis[u.fi] > u.se) {
            dis[u.fi] = u.se;
            cnt[u.fi] = 1;
        }else if(dis[u.fi] == u.se) cnt[u.fi] ++;
        else continue;
        for(auto v : g[u.fi]) {
            q.push({v, u.se + 1});
        }
    }
    int tmp = 0;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 2) {
            s.insert({i, st});
            s.insert({st, i});
        }
    }
}
void solve() {
    cin>> n>> d;
    s.clear();
    for(int i = 1; i <= n; i++) cin>> x[i], g[i].clear();
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(llabs(x[i] - x[j]) <= d) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    for(int i = 1; i <= n; i++) bfs(i);
    cout<< s.size() / 2<< "\n";
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>> c>> T;
    while(T --) {
        solve();
    }
    return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
