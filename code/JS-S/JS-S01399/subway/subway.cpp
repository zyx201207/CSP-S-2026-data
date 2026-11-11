#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int w[M];
int c,n,m,d,q,k,ans;
bool vis[M]; 
priority_queue <pair<int,int>> qu;
int head[M],nxt[M*2],ver[M*2],tot=0,wei[M*2];
int dist[M];
void add(int u,int v,int val){
    nxt[++tot]=head[u];ver[tot]=v;wei[tot]=val;head[u]=tot;
}
void dis(int s){
    dist[s]=0;
    qu.push({0,s});
    memset(vis,0,sizeof(vis));
    while(!qu.empty()){
        int u=qu.top().second;
        qu.pop();
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){      
            int v=ver[i];
            if(vis[v]) continue;            
            if(dist[v]>=dist[u]+wei[i]){
            dist[v]=dist[u]+wei[i];
            qu.push({-dist[v],v});
            }
        }  
    }   
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout); 
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    memset(head,0,sizeof(head));
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        int temp[k+1][2];
        for(int j=1;j<=k;j++){
            scanf("%d %d",&temp[j][0],&temp[j][1]);
        }
        for(int h=1;h<k;h++){
            for(int f=h+1;f<=k;f++){
                add(temp[h][0],temp[f][0],temp[h][1]+temp[f][1]);
                add(temp[f][0],temp[h][0],temp[h][1]+temp[f][1]);
               
            }
        }
    }
    for(int i=1;i<=q;i++){
        ans=0;
        int x,y;
        scanf("%d %d",&x,&y);
        ans+=w[x]+w[y];
        memset(dist,0x3f,sizeof(dist));
        dis(x);
        ans+=dist[y];
        printf("%d\n",ans);
    }
}