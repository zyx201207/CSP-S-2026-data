#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int g[1005][1005];
int dist[1005];
bool vis[1005];
struct node{
    int to;
    int w;
};
bool cmp(node x,node y){
    return x.w<y.w;
}
int dijkstra(int s,int t){
    int ans=0;
    ans=ans+g[s][0]+g[t][0];
    node q[100005];
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(vis));
    int head=1;
    int tail=0;
    q[++tail]=node {s,0};
    dist[s]=0;
    while(head<=tail){
        sort(q+head,q+tail,cmp);
        node y=q[head];
        head++;
        int u=y.to;
        if (vis[u]==0){
            vis[u]==1;
            for (int v=1;v<1505;v++){
                if (g[u][v]>0){
                    if (dist[u]+g[u][v]<dist[v]){
                        dist[v]=dist[u]+g[u][v];
                        //q.push(node {dist[s][v],v});
                        q[++tail]=node {v,dist[v]};
                    }
                }
            }
        }
    }
    ans+=dist[t];
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        int u=0,v=i;
        int t;
        cin>>t;
        g[u][v]=t;
        g[v][u]=t;
    }
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int u,v,t;
            cin>>v>>t;
            u=i+m;//yixianzhantai
            g[u][v]=t;
            g[v][u]=t;
        }
    }
    for (int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        cout<<dijkstra(s,t)<<endl;
    }
    return 0;
}
