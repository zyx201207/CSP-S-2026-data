#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
#define vci vector<int>
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define gr(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=110;
inline int read(){
    int x=0;char ch=gc();bool fg=0;
    while(!isdigit(ch)) fg^=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=gc();
    return fg?~(x-1):x;
}
int T,n,k,mp[N][N],fa[N],as;
vci g[N];
int fid(int x){
    return x==fa[x]?x:fa[x]=fid(fa[x]);
}
int dfs(int x,int fb,int d,int vl){
    if((vl>>x-1)&1) return d; int ap=n+1;
    for(int v:g[x]) if(v!=fb)
        ap=min(ap,dfs(v,x,d+1,vl));
    return ap;
}
int cal(int x){
    int ap=0;
    fr(i,1,n) ap=max(ap,dfs(i,0,0,x));
    return ap;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    T=read(),T=read();
    while(T--){
        n=read(),k=read(),as=n+1;
        fr(i,1,n-1){
            int x=read(),y=read();
            mp[x][y]=mp[y][x]=1;
            g[x].pb(y),g[y].pb(x);
        }
        fr(i,0,(1<<n)-1){
            if(__builtin_popcount(i)!=k) continue;
            fr(j,1,n) fa[j]=j;
            fr(j,1,n) fr(o,1,n){
                if(((i>>j-1)&1)&&((i>>o-1)&1)&&mp[j][o])
                    fa[fid(j)]=fid(o);
            }
            int ans=0;
            fr(j,1,n) if(((i>>j-1)&1)&&j==fid(j))
                ans++;
            if(ans>2) continue;
            as=min(as,cal(i));
        }
        fr(i,1,n) fr(j,1,n) mp[i][j]=0;
        fr(i,1,n) g[i].clear();
        printf("%d\n",as);
    }
    return 0;
}