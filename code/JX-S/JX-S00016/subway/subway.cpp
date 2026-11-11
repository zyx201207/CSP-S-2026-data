#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
ui w[500005];
int k[505];
vector<int> sta[500005];
ll dis[505][505];
vector<vector<ui> >ti;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(dis,0x3f,sizeof dis);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    ti.resize(n+1);
    for(int i=1;i<=n;i++)ti[i].resize(m);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ui t,tm;
            cin>>t>>tm;
            ti[i][t]=tm;
            sta[t].push_back(i);
            for(auto to:sta[t]){
                dis[i][to]=dis[to][i]=min((ll)(tm+ti[to][t]),dis[i][to]);
            }
            dis[i][i]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        ll ans=9e18;
        for(auto ls:sta[s]){
            for(auto le:sta[e]){
                ans=min(ans,(ll)(w[s]+w[e]+ti[ls][s]+ti[le][e]+dis[ls][le]));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
