#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') f=-1;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return f*x;
}
const int N=1e4+10;
struct node{
    int to,nxt;
};
node E[N];
int tot,head[N];
void addedge(int u,int v){
    E[++tot]={v,head[u]};
    head[u]=tot;
}
int c,T,n,k,vis[N],h[N],ans;
void dfs(int u,int fa){
    vis[u]=1;
    for(int i=head[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(vis[v]||v==fa||!h[v]) continue;
        dfs(v,u);
    }
}
bool check(){
    int tot=0;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&h[i]){
            dfs(i,0);
            tot++;
        }
    }
    if(tot>2) return false;
    return true;
}
int dis[N];
int getans(){
    for(int j=1;j<=n;j++) dis[j]=n+1;
    for(int x=1;x<=n;x++){
        if(h[x]){
            queue<int> q;
            for(int j=1;j<=n;j++) vis[j]=0;
            q.push(x);dis[x]=0;
            while(!q.empty()){
                int u=q.front();q.pop();
                vis[u]=1;
                for(int i=head[u];i;i=E[i].nxt){
                    int v=E[i].to;
                    if(vis[v]) continue;
                    vis[v]=1;q.push(v);
                    dis[v]=min(dis[v],dis[u]+1);
                }
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dis[i]);
    return res;
}
void work(int dep,int x){
    if(x>k) return;
    if(dep>n){
        if(check()){
            ans=min(ans,getans());
        }
        return;
    }
    h[dep]=1;
    work(dep+1,x+1);
    h[dep]=0;
    work(dep+1,x);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();T=read();
    while(T--){
        n=read();k=read();
        memset(head,0,sizeof(head));
        for(int i=1;i<=n;i++) vis[i]=h[i]=0;
        ans=n+1;
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            addedge(x,y);addedge(y,x);
          
        } 
        work(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/