#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+1;
ll ww[N],w[501][N],c,n,m,d,q;
bool vis[N];
vector<vector<ll>> g(N);//g[i]:tong guo de di tie
ll search(ll x,ll y){
    for(ll i=1;i<=n;i++){
        if(w[i][x]!=0&&w[i][y]!=0) return w[i][x]+w[i][y];
    }
    ll minn=1e9+10;
    for(ll i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        minn=min(minn,search(x,i)+search(i,y));
        vis[i]=0;
    }
    return minn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>ww[i];
    }
    for(ll i=1;i<=n;i++){
        ll k,la=0;
         cin>>k;
         if(k==1){
            ll a,t;
            cin>>a>>t;
            continue;
         }
         for(ll j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            g[a].push_back(i);
            w[i][a]=t;
         }
    }
    for(ll i=1;i<=q;i++){
        ll x,y;
        cin>>x>>y;
        cout<<1ll+ww[x]+ww[y]+search(x,y)-1<<endl;
    }
    return 0;
}
