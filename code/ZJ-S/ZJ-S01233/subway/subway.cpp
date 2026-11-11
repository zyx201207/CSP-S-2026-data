#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
#define vci vector<int>
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define gr(i,r,l) for(int i=r;i>=l;i--)
#define int long long
using namespace std;
const int N=510,M=5e5+10,inf=1e18;
inline int read(){
    int x=0;char ch=gc();bool fg=0;
    while(!isdigit(ch)) fg^=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=gc();
    return fg?~(x-1):x;
}
struct node{int id,v;};
vector<node>g[M];
int n,m,d,q,w[M],vis[N];
int dis[N][N],mp[N][N];
inline void dij(int x){
    fr(i,1,n) vis[i]=0,dis[x][i]=inf;
    dis[x][x]=0;
    fr(o,1,n){
        int id=-1,mi=inf;
        fr(i,1,n) if(!vis[i]&&dis[x][i]<mi)
            mi=dis[x][i],id=i;
        if(id==-1) return;
        vis[id]=1;
        fr(i,1,n)
            dis[x][i]=min(dis[x][i],mi+mp[id][i]);
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    n=read(),n=read(),m=read(),d=read(),q=read();
    fr(i,1,m) w[i]=read();
    fr(i,1,n){
        int k=read(),x,y;
        fr(j,1,k) x=read(),y=read(),g[x].pb({i,y});
    }
    fr(i,1,n) fr(j,1,n) mp[i][j]=inf;
    fr(i,1,m) for(node x:g[i]) for(node y:g[i])
        mp[x.id][y.id]=min(mp[x.id][y.id],x.v+y.v);
    fr(i,1,n) dij(i);
    while(q--){
        int x=read(),y=read(),ans=inf;
        for(node v:g[x]) for(node u:g[y])
            ans=min(ans,dis[v.id][u.id]+v.v+u.v+w[x]+w[y]);
        printf("%lld\n",ans);
    }
    return 0;
}