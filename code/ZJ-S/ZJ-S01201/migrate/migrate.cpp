#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 rnd(time(NULL));
vector<ll> num;
vector<size_t> vis; 
vector<ll> way;
vector<ll> dis;
ll n, d, ans;
void bfs(ll s, size_t _time) {
    queue<ll> que;
    que.push(s);
    way[s] = 1;
    vis[s] = _time;
    dis[s] = 0;
    while (!que.empty()) {
        ll now = que.front();
        que.pop();
        if (way[now] == 2) {
            ans++;
        }
        for (ll i = now; i < num.size(); i++) {
            if (num[i] - num[now] > d)
                break;
            ll to = i;
            if (vis[to] != _time) {
                vis[to] = _time;
                way[to] = way[now];
                dis[to] = dis[now] + 1;
                que.push(to);
            } else if (vis[to] == _time && dis[to] == dis[now] + 1) {
                way[to] += way[now];
            }
        }
    }
}
void solve() {
    cin >> n >> d;
    ans = 0;
    vis.resize(n + 1);
    dis.resize(n + 1);
    way.resize(n + 1);
    num.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (ll i = 1; i <= n; i++) {
        bfs(i, rnd());
    }
    cout << ans << '\n';
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll c, T;
    cin >> c >> T;
    while(T--) {
        solve();
    }
    return 0;
}