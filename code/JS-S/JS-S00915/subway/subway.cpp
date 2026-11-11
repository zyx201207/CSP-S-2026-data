#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int M=1e4+7,N=5e5+7;
int w[N];
int a[507][N],t[507][N],k[507];
int g[507][507];
struct b{
    int u,v,w;
    bool operator < (const b &c) const{
        if(w==c.w){
            if(u==c.u) return v<c.v;
            return u<c.u;
        }
        return w<c.w;
    }
}h[507*507];
bool vis[507][507];
vector<int> pa[N];
int fa[N];
int find(int u){
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
void merge(int x,int y){
    if(x==y) return;
    int sx=fa[x],sy=fa[y];
    if(sx>sy) swap(sx,sy);
    fa[sx]=sy;
}
int bs=0;
int c,n,m,d,q;
void kruskal(int k){
    int i=1;
    while(bs<=m&&i<=500*500){
        if(h[i].u>h[i].v) swap(h[i].u,h[i].v);
        if(find(h[i].u)!=find(h[i].v))
            bs++,pa[h[i].u].push_back(h[i].v),merge(h[i].u,h[i].v);
        i++;
    }
}
int st,ed,sum=0;
bool f=1;
void dfs(int x){
    if(x==m+1){
        cout<<sum<<endl;
        f=0;
        return;
    }
    for(auto j:pa[x]){
        sum+=g[x][j];
        dfs(j);
        if(f==0) return;
        sum-=g[x][j];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0x3f3f3f3f,sizeof g);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
        cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<i;++j){
            for(int x=1,y=1;x<=k[i],y<=k[j];){
                if(a[i][x]<a[j][y]) x++;
                else if(a[i][x]>a[j][y]) y++;
                else g[i][j]=g[j][i]=min(g[i][j],t[i][x]+t[j][y]),x++,y++;
            }
        }
    }
    while(q--){
        cin>>st>>ed;
        int ct=0;
        memset(pa,0,sizeof pa);
        bs=0;f=1;sum=0;
        for(int i=0;i<=m;++i) fa[i]=i;
        for(int i=0;i<=500;++i) g[0][i]=g[i][0]=g[m+1][i]=g[i][m+1]=0x3f3f3f3f;
        for(int i=0;i<=500;++i)
            for(int j=0;j<=500;++j)
                h[++ct].u=i,h[ct].v=j,h[ct].w=g[i][j];
        for(int i=1;i<=m;++i){
            int x=lower_bound(a[i]+1,a[i]+k[i]+1,st)-a[i];
            if(a[i][x]==st){
                g[0][i]=g[i][0]=w[st]+t[i][x];
                h[i+1].w=w[st]+t[i][x];
            }
        }
        for(int i=1;i<=m;++i){
            int x=lower_bound(a[i]+1,a[i]+k[i]+1,ed)-a[i];
            if(a[i][x]==ed){
                g[m+1][i]=g[i][m+1]=w[ed]+t[i][x];
                h[(m+1)*501+i+1].w=w[ed]+t[i][x];
            }
        }
        stable_sort(h,h+250001);
        kruskal(m+1);
        dfs(0);
    }
    return 0;
}
