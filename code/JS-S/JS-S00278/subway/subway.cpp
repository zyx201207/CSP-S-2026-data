#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
bool A=1,B=1;
pair <ll,ll>a[1005];
bool f[1005];
vector<pair<ll,ll>>g[1005];
ll n,c,m,qqq,q,w[N];
ll d[1005][1005];
void dfs(ll x,ll fu,ll jia,ll lst){
    if(f[x])return;
    f[x]=1;
    for(auto [u,v]:g[x]){
        if(u!=lst){
            dfs(u,fu,jia+v,x);
        }
    }
    f[x]=0;
    d[fu][x]=min(d[fu][x],jia);
    d[x][fu]=min(d[x][fu],jia);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>qqq>>q;
    ll T;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        ll k;
        cin>>k;
        for(int j=1;j<=k;++j){
            ll x,t;
            cin>>x>>t;
            a[j]={x,t};
        }
        for(int j=1;j<=k;++j){
            for(int z=j+1;z<=k;++z){
                g[a[j].first].push_back({a[z].first,a[j].second+a[z].second});
                g[a[z].first].push_back({a[j].first,a[j].second+a[z].second});
            }
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=i+1;j<=m;++j){
            d[i][j]=2e18;
            d[j][i]=2e18;
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        dfs(x,x,0,0);
        dfs(x,x,0,0);
        //cout<<x<<" "<<y<<endl;
        cout<<d[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
