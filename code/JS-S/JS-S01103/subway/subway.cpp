#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 507, M = 5e5 + 7, Inf = 1e18;
ll c,n,m,q,d;
ll f[N][N], w[M], k[N];
vector<pair<ll,ll> > v[M];

inline ll read(){
    ll res = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++){
        k[i] = read();
        for(int j = 1, a, t; j <= k[i]; j++){
            a = read(), t = read();
            v[a].push_back({i, t});
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = Inf;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < v[i].size(); j++){
            ll a1 = v[i][j].first, t1 = v[i][j].second;
            for(int k = j+1; k < v[i].size(); k++){
                ll a2 = v[i][k].first, t2 = v[i][k].second;
                f[a1][a2] = min(f[a1][a2],t1 + t2);
                f[a2][a1] = f[a1][a2];
            }
        }
    }
    for(int i = 1; i <= n; i++) f[i][i] = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }
/*
    for(int i = 1; i <= m; i++){
        for(auto j : v[i]){
            ll a = j.first, t = j.second;
            if(mp[{i,a}] == 0){
                vv[i].push_back(a);
                mp[{i,a}] = t;
            } else mp[{i,a}] = min(mp[{i,a}], t);
        }
    }
*/
    for(int i = 1; i <= q; i++){
        ll x, y, ans;
        x = read(), y = read();
        ans = Inf;
        for(auto ii : v[x]){
            for(auto jj : v[y]){
                ll l = ii.first, r = jj.first, t = ii.second + jj.second;
                ans = min(ans, t+f[l][r]);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}
