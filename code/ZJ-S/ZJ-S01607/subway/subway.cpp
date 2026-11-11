#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define SZ(a) (int)a.size()-1
#define fi first
#define se second
#define mkp make_pair
using ll=long long;
using namespace std;

namespace MyCode{
    const int N=505, M=5e5+10;
    int c, n, m, d, q;
    vector<pair<int,int>>w[M];
    ll dis[N][N], a[M];
    void Main(){
        cin>>c>>n>>m>>d>>q;
        rep(i, 1, n) rep(j, 1, i-1) dis[i][j]=dis[j][i]=2e18;
        rep(i, 1, m) cin>>a[i];
        rep(i, 1, n) {
            int k;
            cin>>k;
            rep(j, 1, k) {
                int a, t;
                cin>>a>>t;
                w[a].push_back(mkp(i, t));
            }
        }
        rep(i, 1, m) {
            rep(j, 0, SZ(w[i])) rep(k, 0, SZ(w[i])) {
                dis[w[i][j].fi][w[i][k].fi]=min(dis[w[i][j].fi][w[i][k].fi], (ll)(w[i][j].se+w[i][k].se));
                dis[w[i][k].fi][w[i][j].fi]=min(dis[w[i][k].fi][w[i][j].fi], (ll)(w[i][k].se+w[i][j].se));
            }
        }
        rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
        rep(i, 1, q) {
            int s, t;
            cin>>s>>t;
            if(s==t) {
                cout<<0<<'\n';
                return;
            }
            ll ans=4e18;
            rep(j, 0, SZ(w[s])) rep(k, 0, SZ(w[t])) ans=min(ans, (ll)dis[w[s][j].fi][w[t][k].fi]+w[s][j].se+w[t][k].se+a[s]+a[t]);
            cout<<ans<<'\n';
        }
    }
}

int main(){
 freopen("subway.in", "r", stdin);
 freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T=1;
    // cin>>T;
    // MyCode::init();
    while(T--) MyCode::Main();
    return 0;
}