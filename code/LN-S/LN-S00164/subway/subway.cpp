#include<bits/stdc++.h>
#define pii std::pair<int,int>
namespace fzx{
    const int N=1e3+10,M=2e5+10;
    int head[N],fail[M],edge[M],w[M],tot,dis[N],W[N],a[N][N],t[N][N];
    bool vis[N];
    std::priority_queue<pii,std::vector<pii>,std::greater<pii> >q;
    void add(int u,int v,int x){
        tot++;
        fail[tot]=head[u];
        head[u]=tot;
        edge[tot]=v;
        w[tot]=x;
    }
    int dijkstra(int S,int T){
        memset(dis,0x3f,sizeof dis);
        memset(vis,false,sizeof vis);
        while(q.size())q.pop();
        q.push({0,S});
        dis[S]=0;
        while(q.size()){
            int x=q.top().second;
            q.pop();
            if(vis[x])continue;
            vis[x]=true;
            for(int i=head[x];i;i=fail[i])
                if(dis[edge[i]]>dis[x]+w[i])
                    dis[edge[i]]=dis[x]+w[i],
                    q.push({dis[edge[i]],edge[i]});
        }
        return dis[T];
    }
    void main(){
        int c,n,m,d,q;
        scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
        for(int i=1;i<=m;i++)
            scanf("%d",&W[i]);
        for(int i=1;i<=n;i++){
            int K;
            scanf("%d",&K);
            for(int j=1;j<=K;j++)
                scanf("%d%d",&a[i][j],&t[i][j]);
            for(int j=1;j<=K;j++)
                for(int k=j+1;k<=K;k++)
                    add(a[i][j],a[i][k],t[i][j]+t[i][k]),
                    add(a[i][k],a[i][j],t[i][j]+t[i][k]);
        }
        while(q--){
            int S,T;
            scanf("%d%d",&S,&T);
            printf("%d\n",dijkstra(T,S)+W[S]+W[T]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    fzx::main();
    return 0;
}