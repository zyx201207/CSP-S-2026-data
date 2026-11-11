#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

ll c,n,m,d,q;
ll w[500005];
vector<PII> st[500005];
ll mdis[505][505];
ll dis[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1; i <= m; ++i) cin >> w[i];
    for(ll i = 1; i <= n; ++i){
        ll k;
        cin >> k;
        for(ll j = 1; j <= k; ++j){
            ll a,t;
            cin >> a >> t;
            st[a].push_back({i,t});
        }
    }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= n; ++j){
            if(i == j) mdis[i][j] = 0;
            else mdis[i][j] = 0x3f3f3f3f3f3f3f3f;
        }
    }
    for(ll i = 1; i <= m; ++i)
        for(auto s1 : st[i])
            for(auto s2 : st[i])
                mdis[s1.first][s2.first] = min(mdis[s1.first][s2.first],s1.second+s2.second);
    for(ll i = 1; i <= n; ++i)
        for(ll j = 1; j <= n; ++j)
            dis[i][j] = mdis[i][j];
    for(ll k = 1; k <= n; ++k)
        for(ll i = 1; i <= n; ++i)
            for(ll j = 1; j <= n; ++j)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    for(ll i = 1; i <= q; ++i){
        ll s,t;
        cin >> s >> t;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(auto s1 : st[s])
            for(auto t1 : st[t])
                ans = min(dis[s1.first][t1.first]+s1.second+t1.second+w[s]+w[t],ans);
        cout << ans << endl;
    }
    return 0;
}