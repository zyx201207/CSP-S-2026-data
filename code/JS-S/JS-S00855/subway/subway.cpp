#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
ll c,n,m,d,q;
ll w[500005],vx[505][505],dist[505][505];
vector<pll> va[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){cin>>w[i];}
    for(int i=1;i<=n;i++){
        ll k,a,t;
        vector<ll> vt;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>t;
            va[a].push_back({t,i});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vx[i][j]=1e18;
    for(int i=1;i<=m;i++){
        for(auto u:va[i]){
            for(auto v:va[i]){
                if(u.second==v.second) vx[u.second][v.second]=0;
                else vx[u.second][v.second]=min(vx[u.second][v.second],u.first+v.first);
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=vx[i][j];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        ll x,y,ans,cnt=1e18;
        cin>>x>>y;
        ans=w[x]+w[y];
        for(auto [t1,i]:va[x]){
            for(auto [t2,j]:va[y]){
                cnt=min(cnt,dist[i][j]+t1+t2);
            }
        }
        cout<<ans+cnt<<'\n';
    }
    return 0;
}
