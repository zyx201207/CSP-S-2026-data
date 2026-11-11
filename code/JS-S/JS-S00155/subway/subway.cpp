#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000ll
using namespace std;
int c,n,m,d,q,w[500005],dis[505][505],len,sa,st,u,v,ans;
vector<pair<int,int> >g[505],bel[500005];
bool cmp(vector<pair<int,int> >x,vector<pair<int,int> >y){return x.size()<y.size();}
int findt(int x,int y){
    if(g[x][(int)g[x].size()-1].first<y)return inf;
    pair<int,int>p=*lower_bound(g[x].begin(),g[x].end(),make_pair(y,0ll));
    if(p.first!=y)return inf;
    return p.second;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>len;
        for(int j=1;j<=len;j++){
            cin>>sa>>st;
            g[i].push_back(make_pair(sa,st));
        }sort(g[i].begin(),g[i].end());
    }sort(g+1,g+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            bel[g[i][j].first].push_back(make_pair(i,g[i][j].second));
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<g[i].size();k++)dis[i][j]=min(dis[i][j],g[i][k].second+findt(j,g[i][k].first));
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>u>>v;ans=inf;
        for(int j=0;j<bel[u].size();j++){
            for(int k=0;k<bel[v].size();k++){
                ans=min(ans,bel[u][j].second+bel[v][k].second+dis[bel[u][j].first][bel[v][k].first]);
            }
        }cout<<ans+w[u]+w[v]<<"\n";
    }
}
