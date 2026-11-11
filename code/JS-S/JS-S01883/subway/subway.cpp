#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 505;
const ll maxm = 5e5 + 5;
const ll maxq = 1e5 + 5;
ll c, n, m, d, q;
ll w[maxm];
ll k[maxn];
ll a[maxn][1001], t[maxn][maxm];
ll x[maxq], y[maxq];

ll hc[maxn][maxn];
vector<pair<ll, ll> >g[maxm];

ll ans = 0x3f3f3f3f3f3f3f3f;
bool vis[maxm];
void dfs(ll cur, ll fa, ll ed, ll xian, ll tim){
    if(tim >= ans){
        return ;
    }
    if(cur == ed){
        tim += t[xian][cur];
        tim += w[ed];
        ans = min(ans, tim);
        return ;
    }
    for(ll i = 0; i < g[cur].size(); i++){
        ll line = g[cur][i].first;
        if(line == xian){
            continue;
        }
        for(ll j = 1; j <= k[line]; j++){
            ll ch = a[line][j];
            if(ch == cur || ch == fa){
                continue;
            }
            if(vis[ch]){
                continue;
            }
            vis[ch] = true;
            if(xian == -1){
                dfs(ch, cur, ed, line, tim + t[line][cur]);
            }else{
                dfs(ch, cur, ed, line, tim + hc[xian][line]);
            }
            vis[ch] = false;
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for(ll i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> k[i];
        for(ll j = 1; j <= k[i]; j++){
            cin >> a[i][j];
            cin >> t[i][a[i][j]];
            g[a[i][j]].push_back(make_pair(i, j) );
        }
    }

    for(ll i = 1; i <= m; i++){
        for(ll j = 0; j <= m; j++){
            if(i == j){
                hc[i][j] = 0;
            }else{
                hc[i][j] = 0x3f3f3f3f3f3f3f3f;
            }
        }
    }

    for(ll i = 1; i <= m; i++){
        for(ll gi = 0; gi < g[i].size(); gi++){
            ll u = g[i][gi].first;
            ll tu = t[u][i];
            for(ll gj = gi + 1; gj < g[i].size(); gj++){
                ll v = g[i][gj].first;
                ll tv = t[v][i];
                hc[u][v] = hc[v][u] = min(hc[u][v], tu + tv);
            }
        }
    }

    for(ll r = 1; r <= q; r++){
        cin >> x[r] >> y[r];
        ans = 0x3f3f3f3f3f3f3f3f;
        memset(vis, false, sizeof(vis));
        dfs(x[r], x[r], y[r], -1, w[x[r]]);
        cout << ans << "\n";
    }
    //cout<<"::  "<<w[1]<<endl;
    cout << flush;
    return 0;
}
