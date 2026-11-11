#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
    int to,nxt;
}ed[N<<2];
int head[N],cnt;
void add(int u,int v){
    cnt++;
    ed[cnt].to=v;
    ed[cnt].nxt=head[u];
    head[u]=cnt;
}
int n,k;
int dep[N],f[N][30];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=head[u];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
}
void init(){
    for(int i=1;(1<<i)<=n;i++){
        for(int u=1;u<=n;u++){
            f[u][i]=f[f[u][i-1]][i-1];
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=25;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            x=f[x][i];
        }
    }
    if(x==y)return x;
    for(int i=25;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int dist(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
void cleanqq(){
    memset(head,0,sizeof(head));
    memset(dep,0,sizeof(dep));
    memset(f,0,sizeof(f));
    for(int i=1;i<=cnt;i++){
        ed[i].to=ed[i].nxt=0;
    }
    cnt=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        cleanqq();
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        init();
        if(k==2){
            int res=0x3f3f3f3f;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int ans=0;
                    for(int u=1;u<=n;u++){
                        ans=max(ans,min(dist(u,i),dist(u,j)));
                    }
                    res=min(res,ans);
                }
            }
            cout<<res<<endl;
        }
        else{
            int res=0x3f3f3f3f;
            for(int i=1;i<=n;i++){
                int ans=0;
                for(int u=1;u<=n;u++){
                    ans=max(ans,dist(u,i));
                }
                res=min(res,ans);
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
