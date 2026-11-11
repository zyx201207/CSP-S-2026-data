#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=2e3+3,M=2e6+6;
int n,fa[M];
ll d,a[M],f[N][N],dis[N][N];
void _main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    fa[n+1]=n;
    for(int i=n;i>=1;i--){
        fa[i]=fa[i+1];
        while(a[fa[i]]-a[i]>d)fa[i]--;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        queue<int>q;
        memset(dis[i],0x3f,sizeof(dis[i])),memset(f[i],0,sizeof(f[i]));
        q.push(i),f[i][i]=1,dis[i][i]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int j=x+1;j<=fa[x];j++){
                if(dis[i][j]==0x3f3f3f3f3f3f3f3f)dis[i][j]=dis[i][x]+1,q.push(j);
                if(dis[i][j]==dis[i][x]+1)f[i][j]+=f[i][x];
            }
        }
        for(int j=i;j<=n;j++)if(f[i][j]==2)ans++;
        // for(int j=i;j<=n;j++)if(f[i][j]==2)cout<<i<<' '<<j<<'\n';
    }
    cout<<ans<<'\n';
}
namespace ASDF{
constexpr int N=2e6+6;
int n,fa[N],dep[N],dfn[N],rk[N],cnt,st[21][N],tot;
ll d,a[N];
vector<int>e[N];
pair<int,int>b[N];
void dfs(int p){
    dfn[rk[p]=++cnt]=p;
    for(int x:e[p])dep[x]=dep[p]+1,dfs(x);
}
int mi(int x,int y){return rk[x]<rk[y]?x:y;}
int lca(int x,int y){
    if(x==y)return x;
    x=rk[x],y=rk[y];
    if(x>y)swap(x,y);
    return mi(st[__lg(y-x)][x+1],st[__lg(y-x)][y-(1<<__lg(y-x))+1]);
}
void _main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)e[i].clear(),dfn[i]=rk[i]=dep[i]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    fa[n+1]=n;
    for(int i=n;i>=1;i--){
        fa[i]=fa[i+1];
        while(a[fa[i]]-a[i]>d)fa[i]--;
        if(i!=fa[i])e[fa[i]].push_back(i);
    }
    cnt=0;
    for(int i=n;i>=1;i--)if(!rk[i])dfs(i);
    for(int i=1;i<=n;i++)st[0][i]=fa[dfn[i]];
    for(int i=1;i<21;i++)for(int j=1;j+(1<<i)-1<=n;j++)st[i][j]=mi(st[i-1][j],st[i-1][j+(1<<i-1)]);
    tot=0;
    for(int i=1;i<=n;i++){
        if(fa[i]>i+1&&dep[fa[i]]==dep[fa[i]-1]&&dep[fa[i]]!=dep[fa[i]-2])
            b[++tot]={i,lca(fa[i],fa[i]-1)};
    }
    for(int i=1;i<=n;i++)cout<<fa[i]<<' ';cout<<'\n';
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<lca(i,j)<<' ';cout<<'\n';}
    for(int i=1;i<=tot;i++)cout<<b[i].first<<' '<<b[i].second<<'\n';
    ll ans=0;
    for(int i=n,j=tot,mn=n+1;i>=1;i--){
        if(fa[i]==i)mn=i+1,tot=j;
        for(;j>=1&&b[j].first==i;j--)
            if(j!=tot)mn=min(mn,b[j+1].second);
        if(j!=tot)ans+=max(0,mn-b[j+1].second);
    }
    cout<<ans<<'\n';
}
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t=1;cin>>c>>t;
    if(c<=10)while(t--)_main();
    else while(t--)ASDF::_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ std.cpp -o std -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/