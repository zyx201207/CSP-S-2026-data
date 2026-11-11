#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int c,t,a[N],n,d;///
int g[N][N],dist1[N],dist2[N];
bool vis[N];
struct node{
    int to;
    int w;
};
bool cmp(node x,node y){
    return x.w<y.w;
}
bool dijkstra(int s,int t){
    int cnt=0;
    node q[10005];
    memset(dist1,0x3f,sizeof(dist1));
    memset(vis,false,sizeof(vis));
    int head=1;
    int tail=0;
    q[++tail]=node {s,0};
    dist1[s]=0;
    while(head<=tail){
        sort(q+head,q+tail,cmp);
        node y=q[head];
        head++;
        int u=y.to;
        if (vis[u]==0){
            vis[u]==1;
            for (int v=1;v<=n;v++){
                if (g[u][v]>0){
                    if (dist1[u]+g[u][v]<dist1[v]){
                        dist1[v]=dist1[u]+g[u][v];
                        //q.push(node {dist[s][v],v});
                        q[++tail]=node {v,dist1[v]};
                    }
                }
            }
        }
    }
    ///
    node q2[10005];
    memset(dist2,0x3f,sizeof(dist2));
    memset(vis,false,sizeof(vis));
    head=1;
    tail=0;
    q2[++tail]=node {t,0};
    dist2[t]=0;
    while(head<=tail){
        sort(q2+head,q2+tail,cmp);
        node y=q2[head];
        head++;
        int u=y.to;
        if (vis[u]==0){
            vis[u]==1;
            for (int v=1;v<=n;v++){
                if (g[u][v]>0){
                    if (dist2[u]+g[u][v]<dist2[v]){
                        dist2[v]=dist2[u]+g[u][v];
                        //q.push(node {dist[s][v],v});
                        q2[++tail]=node {v,dist2[v]};
                    }
                }
            }
        }
    }
    ///
    int minx=0x3f;
    for (int k=1;k<=n;k++){
        if (k!=s&&k!=t){
            minx=min(minx,dist1[k]+dist2[k]);
        }
    }
    for (int k=1;k<=n;k++){
        if (dist1[k]+dist2[k]==minx)cnt++;
    }
    return cnt==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)cin>>a[i];
        for (int u=1;u<n;u++){
            for (int v=u+1;v<=n;v++){
                if (u!=v&&a[v]-a[u]<=d){
                    g[a[u]][a[v]]=a[v]-a[u];
                    g[a[v]][a[u]]=a[v]-a[u];
                }
            }
        }
        for (int u=1;u<n;u++){
            for (int v=u+1;v<=n;v++){
                if (dijkstra(u,v))ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
