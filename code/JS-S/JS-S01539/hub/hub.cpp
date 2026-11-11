#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, k, ans, dp[1000005];
vector<ll> e[1000005];
bool f[1000005], f1[1000005];
ll dfs(ll x, ll fa){
    ll rt = 1;
    f1[x] = 1;
    for (auto i: e[x]){
        if (i != fa && f[x]){
            rt += dfs(i, x);
        }
    }
    return rt;
}
void run1(){
    memset(dp, 0x3f, (n + 5) * 8);
    queue<pair<ll, ll>> q;
    for (ll i = 1; i <= n; i++){
        if (f[i]){
            dp[i] = 0;
            q.push({0, i});
        }
    }
    while (!q.empty()){
        pair<ll, ll> x1 = q.front();
        q.pop();
        if (x1.first == dp[x1.second]){
            for (auto i: e[x1.second]){
                if (dp[i] > x1.first + 1){
                    dp[i] = x1.first + 1;
                    q.push({dp[i], i});
                }
            }
        }
    }
    ll rt = 0;
    for (ll i = 1; i <= n; i++) rt = max(rt, dp[i]);
    ans = min(rt, ans);
}
void choose(ll x, ll cnt){
    if (x == n + 1){
        if (cnt == k){
            ll rt = 0;
            for (ll i = 1; i <= n; i++) f1[i] = 0;
            for (ll i = 1; i <= n; i++){
                if (f[i] && (f1[i] == 0)){
                    dfs(i, -1);
                    rt++;
                }
            }
            if (rt <= 2){
                run1();
            }
        }
        return;
    }
    if (cnt > k) return;
    f[x] = 0;
    choose(x + 1, cnt);
    f[x] = 1;
    choose(x + 1, cnt + 1);
}
void run(){
    ans = 9e18;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++){
        e[i].clear();
        f[i] = 0;
    }
    for (ll i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    choose(1, 0);
    cout << ans << endl;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c, t;
    cin >> c >> t;
    for (ll i = 1; i <= t; i++) run();
    return 0;
}
