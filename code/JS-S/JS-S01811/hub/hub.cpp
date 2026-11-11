#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10,L=25;
struct node{
    int to,next;
}a[N*2];
int c,t,n,k,m,pre[N],x,y;
long long ans;
int d[N],lg[N],fa[N][L];
void add(int u,int v) {
    a[++k] = {v,pre[u]};
    pre[u] = k;
}
void dfs(int x,int fath) {
    fa[x][0]=fath;
    for(int k=1;k<L;k++) {
        fa[x][k] = fa[fa[x][k-1]][k-1];
    }
    d[x]=d[fath]+1;
    for(int i=pre[x];i;i=a[i].next) {
        int to=a[i].to;
        if(to!=fath) dfs(to,x);
    }
}
int lca(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    while(d[u]!=d[v]) {
        int k=lg[d[u]-d[v]+1];
        u=fa[u][k];
    }
    if(u==v) return u;
    for(int k=L-1;k>=0;k--) {
        if(fa[u][k]!=fa[v][k]) {
            u=fa[u][k];
            v=fa[u][k];
        }
    }
    return fa[u][0];
}
bool check(int u,int v) {
    if(d[u]<d[v]) swap(u,v);
    while(d[u]!=d[v]) {
        int k=lg[d[u]-d[v]+1];
        u=fa[u][k];
    }
    if(u==v) return true;
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    lg[1] = 0;
    for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    while(t--) {
        ans=0;
        memset(pre,0,sizeof(pre));
        memset(a,0,sizeof(a));
        memset(fa,0,sizeof(fa));
        memset(d,0,sizeof(d));
        k=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++) {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(m<=2) {
            printf("1\n");
        } else {
            dfs(1,0);
            for(int i=1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    int l=lca(i,j);
                    long long len = d[i]-d[l]+d[j]-d[l]+1;
                    ans=max(ans,len);
                }
            }
            ans = (ans-m)/2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
