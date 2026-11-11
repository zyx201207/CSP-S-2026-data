#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int cid,n,m,w[N],dis[505][505],d,q;
vector<pair<int,int> > vc[N];
void upd(int u,int v,int w){
    dis[u][v]=min(dis[u][v],w);
    dis[v][u]=min(dis[v][u],w);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>cid>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int len;cin>>len;
        for(int j=1,x,y;j<=len;j++)
            cin>>x>>y,vc[x].push_back({i,y});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<vc[i].size();j++)
            for(int k=j+1;k<vc[i].size();k++)
                upd(vc[i][j].first,vc[i][k].first,vc[i][j].second+vc[i][k].second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        int ans=1e18;
        for(auto s:vc[x])
            for(auto t:vc[y])
                ans=min(ans,dis[s.first][t.first]+s.second+t.second);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}