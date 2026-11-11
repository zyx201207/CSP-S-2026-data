#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 505
#define int long long
using namespace std;
typedef pair<int,int> PII;
int c,n,m,d,q;
int w[MAXN];
int k[MAXN];
vector<PII> g[MAXN];
int dis[MAXM][MAXM];
int ans;
signed main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            g[m+i].push_back({t,a});
            g[a].push_back({t,m+i});
        }
    }
    for (int i=0;i<MAXM;i++){
        for (int j=0;j<MAXM;j++){
            dis[i][j]=100000000000005;
        }
    }
    for (int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for (int k=1;k<=m;k++){
        for (int i=0;i<g[k].size();i++){
            for (int j=i;j<g[k].size();j++){
                int u=g[k][i].second-m,v=g[k][j].second-m;
                dis[u][v]=min(dis[u][v],g[k][i].first+g[k][j].first);
                dis[v][u]=min(dis[v][u],dis[u][v]);
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        ans=LLONG_MAX;
        for (int i=0;i<g[x].size();i++){
            for (int j=0;j<g[y].size();j++){
                int u=g[x][i].second-m,v=g[y][j].second-m;
                ans=min(ans,w[x]+g[x][i].first+dis[u][v]+g[y][j].first+w[y]);
            }
        }
        cout<<ans<<'\n';
    }

    return 0;

}
