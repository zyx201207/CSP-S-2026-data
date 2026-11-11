#include<bits/stdc++.h>
#define N 1005
using namespace std;
int C,T,n,k,p[N],head[N],cnt=0;
struct node{int v,nxt;}E[N*4];
int dis[N][N],db[N],ans=1e9;bool vis[N];
void add(int u,int v){
    E[++cnt].v=v;
    E[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs1(int sx,int u,int sum){
    dis[sx][u]=sum;
    for(int i=head[u];i;i=E[i].nxt){
        int v=E[i].v;
        if(!vis[v]){
            vis[v]=1;
            dfs1(sx,v,sum+1);
            vis[v]=0;
        }
    }
}
void dfs2(int x,int kp){
    if(x==n+1){
        if(kp!=k)return ;
        int sum=0;
        for(int i=1;i<=n;i++)db[i]=1e9;
        for(int i=1;i<=n;i++){
            if(p[i]){db[i]=0;continue;}
            for(int j=1;j<=n;j++){
                if(p[j])db[i]=min(db[i],dis[i][j]);
            }sum=max(sum,db[i]);
        }ans=min(ans,sum);return ;
    }if(kp>k)return ;
    p[x]=1;dfs2(x+1,kp+1);
    p[x]=0;dfs2(x+1,kp);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){ans=1e9;cnt=0;
        memset(head,0,sizeof(head));
        memset(dis,0x3f,sizeof(dis));
        scanf("%d%d",&n,&k);
        for(int i=1,u,v;i<n;i++){
            scanf("%d%d",&u,&v);
            add(u,v),add(v,u);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)vis[i]=0;
            vis[i]=1;dfs1(i,i,0);
        }
        dfs2(1,0);printf("%d\n",ans);
    }
}
