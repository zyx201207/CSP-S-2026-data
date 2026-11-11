#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=1e16;
int c,n,m,d,q,w[N],dist[555][555];
vector<pair<int,int> >G[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
            G[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=INF;
    for(int i=1;i<=n;i++)
        dist[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<G[i].size();j++)
            for(int k=0;k<G[i].size();k++)
                dist[G[i][j].first][G[i][k].first]=min(dist[G[i][j].first][G[i][k].first],G[i][j].second+G[i][k].second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    while(q--){
        int x,y,ans=INF;cin>>x>>y;
        for(int i=0;i<G[x].size();i++)
            for(int j=0;j<G[y].size();j++)
                ans=min(ans,dist[G[x][i].first][G[y][j].first]+G[x][i].second+G[y][j].second);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}