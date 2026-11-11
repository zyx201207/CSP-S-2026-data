#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int nn=5e5+5;
int c,n,m,d,qes,f[505][505],w[nn],k[505],vis[505];
struct ren{
    int a,t;
};
vector<ren>as[505];
struct node{
    int v,w;
};
vector<node>g[505];
vector<node>ed[nn];
priority_queue<pii,vector<pii>,greater<pii> >q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>qes;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            ed[a].push_back({i,t});
            as[i].push_back({a,t});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)f[i][j]=1e18;
    for(int i=1;i<=n;i++){
        for(int j=0;j<as[i].size();j++){
            int u=as[i][j].a,w=as[i][j].t;
            for(int l=0;l<ed[u].size();l++){
                int v=ed[u][l].v,ws=ed[u][l].w;
                f[i][v]=min(f[i][v],w+ws);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)f[i][j]=0;
            if(f[i][j]<1e18 && i!=j){

                g[i].push_back({j,f[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)f[i][j]=1e18;
    for(int i=1;i<=n;i++){
        while(!q.empty())q.pop();
        for(int j=1;j<=n;j++)vis[j]=0;
        f[i][i]=0;
        q.push({0,i});
        while(!q.empty()){
            int u=q.top().se;q.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(int j=0;j<g[u].size();j++){
                int v=g[u][j].v,w=g[u][j].w;
                //if(i==1 && v==3){
                //    cout<<"is"<<f[i][v]<<" "<<f[i][u]<<" "<<w<<'\n';
                //}
                if(f[i][v]>f[i][u]+w){
                    f[i][v]=f[i][u]+w;
                    q.push({f[i][v],v});
                }
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
    //    }
    //}
    while(qes--){
        int xs,ys;
        cin>>xs>>ys;
        int ans=1e18;
        for(int i=0;i<ed[xs].size();i++){
            int u=ed[xs][i].v,w=ed[xs][i].w;
            for(int j=0;j<ed[ys].size();j++){
                int v=ed[ys][j].v,ws=ed[ys][j].w;
                ans=min(ans,f[u][v]+w+ws);
            }
        }
        cout<<ans+w[xs]+w[ys]<<'\n';
    }
    return 0;
}
