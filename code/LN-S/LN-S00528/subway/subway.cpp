#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int n,m,C,D,q;
int W[500005];
struct edge{int v,w;};
vector<edge> a[505];
vector<edge> z[500005];
int dis[505][505];
signed main(){
    qrw;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++) cin>>W[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v,w;
            cin>>v>>w;
            a[i].push_back({v,w});
            z[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<z[i].size();j++){
            for(int l=0;l<z[i].size();l++){
                if(j==l) continue;
                dis[z[i][j].v][z[i][l].v]=min(dis[z[i][j].v][z[i][l].v],z[i][j].w+z[i][l].w);
            }
        }
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=LONG_LONG_MAX;
        for(int j1=0;j1<z[x].size();j1++){
            for(int j2=0;j2<z[y].size();j2++){
                ans=min(ans,dis[z[x][j1].v][z[y][j2].v]+z[x][j1].w+z[y][j2].w);
            }
        }
        cout<<ans+W[x]+W[y]<<endl;
    }
}
// 我是不是要挂分了QaQ
// 这是Berd第一次在-S赛场上写出来T2！大家祝我不要挂分qwq