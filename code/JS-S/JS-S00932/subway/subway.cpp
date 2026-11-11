#include <bits/stdc++.h>

#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define rep_(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define fi first
#define se second
#define mpr(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define endl "\n"
#define lowbit(x) (x&-x)
#define sz(s) ((int)s.size())
#define pii pair<int,int>
#define y0 y12345
#define y1 y54321

using  namespace std;

void inline solve(int C);

signed main(){
    srand(time(0));
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int T=1,C=0;

    cin >> C;
    //cin >> T;

    while(T--) solve(C);

    return 0;
}

const int N=510,M=5e5+10,INF=4557430888798830399;

int n,m,d,q,w[M],dp[N][N];
vector<pii> g[M];

void inline upd(int& x,int y){
    if(x>y) x=y;
}

void inline solve(int C){
    cin >> n >> m >> d >> q;
    rep(i,1,m) cin >> w[i];
    rep(i,1,n){
        int k,a,t;
        cin >> k;
        rep(j,1,k){
            cin >> a >> t;
            g[a].pb(mpr(i,t));
        }
    }
    memset(dp,0x3f,sizeof(dp));
    rep(i,1,n) dp[i][i]=0;
    rep(i,1,m){
        for(pii x:g[i]){
            for(pii y:g[i]){
                if(x.fi!=y.fi) upd(dp[x.fi][y.fi],x.se+y.se);
            }
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                upd(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int s,t,ans=INF;
        cin >> s >> t;
        for(pii x:g[s]){
            for(pii y:g[t]){
                upd(ans,dp[x.fi][y.fi]+w[s]+x.se+y.se+w[t]);
            }
        }
        cout << ans << endl;
    }
}
