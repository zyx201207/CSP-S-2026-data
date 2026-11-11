#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define dep(i,e,s) for(int i=e;i>=s;i--)
#define lc id<<1
#define rc id<<1|1
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int maxn=505,maxm=5e5+10;
const ll inf=1ll<<60;
int c,n,m,d,q;
ll w[maxm],k[maxn],dis[maxn][maxn];
vector<ll> a[maxn],t[maxn];
vector<pii> b[maxm];
signed main(){
    freopen("subway.in","r",stdin);    
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>w[i];
    rep(i,1,n){
        cin>>k[i];
        a[i].pb(0);t[i].pb(0);
        rep(j,1,k[i]){
            ll x,y;
            cin>>x>>y;
            a[i].pb(x);
            t[i].pb(y);
            b[a[i][j]].pb({i,j});
        }
    }
    rep(i,1,n) rep(j,1,n) dis[i][j]=(i==j)?0:inf;
    rep(i,1,m){
        for(auto x:b[i]){
            for(auto y:b[i]){
                dis[x.first][y.first]=min(dis[x.first][y.first],
                t[x.first][x.second]+t[y.first][y.second]);
            }
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(auto s1:b[x]){
            for(auto s2:b[y]){
                ans=min(ans,t[s1.first][s1.second]+t[s2.first][s2.second]+
                dis[s1.first][s2.first]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/