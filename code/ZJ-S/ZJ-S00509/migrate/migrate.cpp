#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 5;

int __c, n;
ll d, a[N];

void solvea(){
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    if (n == 1){
        cout << "0\n";
        return ;
    }
    ll _d = a[2] - a[1];
    ll cnt = d / _d;
    if (cnt <= 1){
        cout << "0\n";
        return ;
    }
    cout << max(0ll, (ll)n - cnt - cnt + 1) << "\n";

    // ll res = 0;
    // for (int i = 1; i <= n; i ++ ) if (i + cnt + cnt - 1 <= n && cnt > 1) res ++ ;
    // cout << res << "\n";
}
void solveb(){
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    ll res = 0;
    for (int i = 1; i <= n; i ++ ){
        int r = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        if (r - i <= 1) continue;
        int lt = a[r - 2] + 1 + d, rt = a[r - 1] + d;
        int _l = lower_bound(a + 1, a + n + 1, lt) - a;
        int _r = upper_bound(a + 1, a + n + 1, rt) - a - 1;
        if (_r <= r) continue;
        _l = max(_l, r + 1);
        if (_l > _r) continue;
        res += _r - _l + 1;
    }
    cout << res << "\n";
}

vector <int> g[N];
int dis[N], cnt[N];

void dijkstra(int st){
    for (int i = 1; i <= n; i ++ ) dis[i] = n + 5, cnt[i] = 0;
    priority_queue <pii, vector <pii>, greater <pii> > q;
    q.push({0, st});
    dis[st] = 0, cnt[st] = 1;
    while (q.size()){
        int d = q.top().fi, u = q.top().se; q.pop();
        for (auto v : g[u]){
            if (dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                q.push({dis[v], v});
            }
            else if (dis[v] == dis[u] + 1){
                cnt[v] += cnt[u];
                if (cnt[v] > 2) cnt[v] = 3;
            }
        }
    }
}
void solvesm(){
    for (int i = 1; i <= n; i ++ ) cin >> a[i], g[i].clear();
    for (int i = 1; i <= n; i ++ ){
        for (int j = i + 1; j <= n; j ++ ){
            if (a[j] - a[i] <= d) g[i].push_back(j);
            else break;
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i ++ ){
        dijkstra(i);
        for (int j = 1; j <= n; j ++ ){
            if (dis[j] <= n && cnt[j] == 2) res ++ ;
        }
    }
    cout << res << "\n";
}
void solve(){
    cin >> n >> d;
    if (11 <= __c && __c <= 12) solvea();
    else if (n <= 300) solvesm();
    else if (13 <= __c && __c <= 14) solveb();
    else solvesm();
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> __c;

    int T; cin >> T;
    while (T -- ) solve();
}