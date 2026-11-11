#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<<#x<<": "<<x<<'\n';
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<'\n';
#define debug3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<'\n';
const ll MAXN=505,MAXM=5e5+555,INF=1e17;
ll c,n,m,d,q,s,t;
ll w[MAXM];
//vector< array<ll,2> >g[MAXN];
vector< vector<ll> >f;
void Floyd(){
    for (int k=1;k<=n+m;k++){
        for (int i=1;i<=n+m;i++){
            for (int j=1;j<=n+m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
void solve(){
    ll ans=w[s]+w[t];
    ll ps=s+n,pt=t+n;
    ans+=f[ps][pt];
    cout<<ans<<'\n';
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
//    vector< vector<ll> >f(n+m+5,vector<ll>(n+m+5,0));
    f.resize(n+m+5,vector<ll>(n+m+5,INF));
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        //build edge
        //line 1 -> n
        //pos n+1->n+m
        ll k,a,t;cin>>k;
        for (int j=1;j<=k;j++){
            cin>>a>>t;
            ll pos=a+n;
//            g[i].push_back({pos,t});
//            g[pos].push_back({i,t});
            f[i][pos]=f[pos][i]=t;
        }
    }
    Floyd();
    while (q--){
        cin>>s>>t;//s -> t
        solve();
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
