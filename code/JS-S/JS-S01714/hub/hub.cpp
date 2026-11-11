#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v,nxt;
}e[2000005];
int pos,head[1000005];
void addEdge(int u,int v){
    e[++pos]={v,head[u]};
    head[u]=pos;
}
int n,k,ans;
bool ps[1000005],vis[1000005];
void dfs(int u,int fa){
    vis[u]=true;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa||!ps[v]) continue;
        dfs(v,u);
    }
}
int bfs(int s){
    memset(vis,0,sizeof vis);
    queue<pair<int,int> >q;
    q.push({s,0});
    while(!q.empty()){
        int u=q.front().first,dis=q.front().second;
        q.pop();
        if(ps[u]) return dis;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v]){
                vis[v]=true;
                q.push({v,dis+1});
            }
        }
    }
    return -1;
}
void solve(){
    scanf("%d%d",&n,&k);
    memset(head,0,sizeof head);
    pos=0;
    ans=1e9;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=k) continue;
        for(int j=1;j<=n;j++) ps[j]=(i>>j-1)&1,vis[j]=0;
        int cnt=0,res=0;
        for(int j=1;j<=n;j++){
            if(!ps[j]) continue;
            if(!vis[j]){
                cnt++;
                if(cnt>2) break;
                dfs(j,0);
            }
        }
        if(cnt>2) continue;
        for(int j=1;j<=n;j++) res=max(res,bfs(j));
        ans=min(ans,res);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--) solve();
    return 0;
}