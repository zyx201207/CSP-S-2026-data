#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
ll W[500050];
struct node{
    int v;
    ll w;
};
vector<node>vec[500050];
ll dis[550][550];
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a,t;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            vec[a].push_back({i,t});
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=LONG_MAX;
        }
    }
    for(int k=1;k<=m;k++){
        if(vec[k].size()<2)continue;
        for(int i=0;i<vec[k].size();i++){
            for(int j=0;j<vec[k].size();j++){
                if(i==j)continue;
                int u=vec[k][i].v;
                int v=vec[k][j].v;
                ll w=vec[k][i].w+vec[k][j].w;
                dis[u][v]=dis[v][u]=min(dis[u][v],w);
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=LONG_MAX&&dis[k][j]!=LONG_MAX)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=LONG_MAX;
        for(int j=0;j<vec[x].size();j++){
            for(int k=0;k<vec[y].size();k++){
                int u=vec[x][j].v,v=vec[y][k].v;
                ll w=vec[x][j].w+vec[y][k].w;
                ans=min(ans,w+dis[u][v]);
            }
        }
        ans+=W[x]+W[y];
        cout<<ans<<'\n';
    }
    return 0;
}
