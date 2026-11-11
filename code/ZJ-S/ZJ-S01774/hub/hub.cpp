#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,dep[maxn],fa[maxn],ans;
vector<int>tr[maxn];
void dfs1(int x){
    for(int v:tr[x]){
        if(v==fa[x]) continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs1(v);
    }
}
bool use[maxn],vis[maxn];
void dfs2(int x){
    if(vis[x]) return;
    vis[x]=true;
    for(int v:tr[x]){
        if(!use[v]) continue;
        dfs2(v);
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]){
        x=fa[x];
    }
    while(x!=y){
        x=fa[x];y=fa[y];
    }
    return x;
}
void dfs(int x,int cnt){
    if(cnt>k||cnt+n-x+1<k) return;
    if(x==n+1){
        for(int i=1;i<=n;i++){
            vis[i]=false;
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(use[i]&&!vis[i]){
                cnt++;
                dfs2(i);
            }
        }
        if(cnt>2) return;
        int sum=0;
        for(int i=1;i<=n;i++){
            int mn=1e9;
            for(int j=1;j<=n;j++){
                if(!use[j]) continue;
                mn=min(mn,dep[i]+dep[j]-dep[lca(i,j)]*2);
            }
            sum=max(sum,mn);
        }
        ans=min(ans,sum);
        return;
    }
    use[x]=true;
    dfs(x+1,cnt+1);
    use[x]=false;
    dfs(x+1,cnt);
}
void work(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) tr[i].clear();
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dep[1]=1;
    dfs1(1);
    ans=1e9;
    dfs(1,0);
    printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        work();
    }
}