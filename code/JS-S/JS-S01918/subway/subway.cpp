#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int c,n,m,d,Q;
struct node{
    int v,w;
    bool operator < (const node & B) const{
        return w > B.w;
    }
};
priority_queue<node>q;
vector<node>sta[500005];
int W[500005];
int G[505][505];
int dis[505][505],vis[505][505],inq[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    memset(G,0x3f,sizeof(G));
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int u=1;u<=n;u++){
        G[u][u]=0;
        int k;cin>>k;
        for(int i=1;i<=k;i++){
            int a,t;cin>>a>>t;
            for(int j=0;j<sta[a].size();j++){
                int v=sta[a][j].v,nt=sta[a][j].w;
                G[u][v]=G[v][u]=min(G[u][v],t+nt);
            }
            sta[a].push_back({u,t});
            // cout<<a<<":"<<sta[a].size()<<endl;
        }
    }
    // for(int i=1;i<=n;i++,cout<<endl)
    //     for(int j=1;j<=n;j++)cout<<G[i][j]<<" ";
    
    // return 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }

    while(Q--){
        int x,y;cin>>x>>y;
        int ans=0x3f3f3f3f3f3f3f3fll;
        // LONG_LONG_MAX;
        // cout<<sta[x].size()<<" "<<sta[y].size()<<endl;
        for(int i=0;i<sta[x].size();i++){
            for(int j=0;j<sta[y].size();j++){
                ans=min(ans,sta[x][i].w+sta[y][j].w+G[sta[x][i].v][sta[y][j].v]);
            }
        }
        cout<<ans+W[x]+W[y]<<'\n';
    }
    // for(int s=1;s<=n;s++){
    //     dis[s][s]=0;
    //     while(q.size())q.pop();
    //     q.push({s,0});
    //     inq[s][s]=1;
    //     while(q.size()){
    //         int u=q.top().v;
    //         q.pop();
    //         if(vis[s][u])continue;
    //         vis[s][u]=1;
    //         for(int v=1;v<=n;v++){
    //             int w=G[i][j];
    //         }
    //     }
    // }
    return 0;
}