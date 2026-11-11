#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{
    int next;
    int to;
}es[4000005];
int head[2000005],ecnt;
inline void e_add(int u,int v){
    es[ecnt].next=head[u];
    es[ecnt].to=v;
    head[u]=ecnt;
    ecnt++;
}
int c,t;
int n,k;
int ST[2000005][25],dep[2000005];
bool sy[2000005];
int ans;
void dfs2(int id,int fa){
    for(int i=1;i<=20;i++){
        ST[id][i]=ST[ST[id][i-1]][i-1];
    }
    for(int i=head[id];i;i=es[i].next){
        int v=es[i].to;
        if(v==fa){
            continue;
        }
        dep[v]=dep[id]+1;
        ST[v][0]=id;
        dfs2(v,id);
    }
}
inline int lca(int x,int y){
    if(dep[y]>dep[x]){
        swap(x,y);
    }
    for(int h=dep[x]-dep[y],i=0;h;h>>=1,i++){
        if(h&1){
            x=ST[x][i];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=20;i>=0;i--){
        if(ST[x][i]!=ST[y][i]){
            x=ST[x][i];
            y=ST[y][i];
        }
    }
    return ST[x][0];
}
void dfs1(int id,int gs){
    if(id==n+1){
        if(gs!=k){
            return;
        }
        int fans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sy[j]){
                    fans=max(fans,dep[i]+dep[j]-2*dep[lca(i,j)]);
                }
            }
        }
        ans=min(ans,fans);
        return;
    }
    dfs1(id+1,gs);
    sy[id]=true;
    dfs1(id+1,gs+1);
    sy[id]=false;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ecnt=1;
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            e_add(u,v);
            e_add(v,u);
        }
        ans=0x3f3f3f3f;
        dfs2(1,-1);
        dfs1(1,0);
        printf("%d\n",ans);
    }
    return 0;
}