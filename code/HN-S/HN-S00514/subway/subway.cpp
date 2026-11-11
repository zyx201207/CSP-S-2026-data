#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rint register int
inline int read(){
    rint s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
inline void print(rint x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int c,n,m,d,q,w[500005],cnt,fa[500505],dep[500505],dis[500505],f[500505][20];
struct node{
    int x,y,z;
}a[500005];
struct edge{
    int to,dist;
};
vector<edge>e[500505];
inline int find(rint x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
inline void dfs(rint cur,rint fa){
    dep[cur]=dep[fa]+1,f[cur][0]=fa;
    for(rint i=1;i<=19;i++)f[cur][i]=f[f[cur][i-1]][i-1];
    for(auto i:e[cur]){
        rint y=i.to,d=i.dist;
        if(y==fa)continue;
        dis[y]=dis[cur]+d;
        dfs(y,cur);
    }
}
inline int lca(rint x,rint y){
    if(dep[x]<dep[y])swap(x,y);
    rint d=dep[x]-dep[y];
    for(rint i=19;i>=0;i--)if((d>>i)&1)x=f[x][i];
    if(x==y)return x;
    for(rint i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(rint i=1;i<=m;i++)w[i]=read();
    for(rint i=1,k,x,t;i<=n;i++){
        k=read();
        while(k--){
            x=read(),t=read();
            a[++cnt]={m+i,x,t};
        }
    }
    sort(a+1,a+1+cnt,[](node x,node y){
        return x.z<y.z;
    });
    for(rint i=1;i<=m+n;i++)fa[i]=i;
    for(rint i=1;i<=cnt;i++){
        rint x=a[i].x,y=a[i].y,z=a[i].z,fx=find(x),fy=find(y);
        if(fx==fy)continue;
        fa[fx]=fy;
        e[x].push_back({y,z}),e[y].push_back({x,z});
    }
    dfs(1,0);
    while(q--){
        rint x=read(),y=read(),z=lca(x,y);
        print(w[x]+w[y]+dis[x]+dis[y]-2*dis[z]),putchar('\n');
    }
    return 0;
}