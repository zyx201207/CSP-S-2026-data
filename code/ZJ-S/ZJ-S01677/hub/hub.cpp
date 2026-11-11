#include<bits/stdc++.h>
#define rep(i,l,r) for(int qwp=(r),i=(l);i<=qwp;i++)
#define per(i,r,l) for(int qwp=(l),i=(r);i>=qwp;i--)
#define pb push_back
using namespace std;
constexpr int N=5e5+5;
int n,k,mid;vector<int>g[N];
namespace S1{
int fa[N],Ih[N];
void dfs1(int u){
    Ih[u]=0;for(auto v:g[u])if(v!=fa[u])
    fa[v]=u,dfs1(v),Ih[u]=max(Ih[u],Ih[v]+1);
}
int Oh[N];
void dfs2(int u){
    int mx=-1,se=-1;
    for(auto v:g[u])if(v!=fa[u]){
        if(Ih[v]>mx)se=mx,mx=Ih[v];
        else if(Ih[v]>se)se=Ih[v];
    }
    for(auto v:g[u])if(v!=fa[u])Oh[v]=max(Oh[u],Ih[v]==mx?se:mx)+1,dfs2(v);
}
int If[N];
bool vis3[N];
void dfs3(int u){
    vis3[u]=1;
    If[u]=1;
    for(auto v:g[u])if(v!=fa[u]){
        dfs3(v);
        if(Ih[v]>=mid)If[u]+=If[v];
    }
}
int sf[N];
bool check(){
    rep(x,2,n){
        rep(i,1,n)fa[i]=sf[i];fa[x]=sf[x],fa[sf[x]]=x;
        rep(i,1,n)vis3[i]=0;
        dfs1(x),Oh[x]=-1,dfs2(x),dfs3(x);
        int mn1=k+1;rep(i,1,n)if(vis3[i]&&Oh[i]+1<=mid)mn1=min(mn1,If[i]);
        rep(i,1,n)vis3[i]=0;
        dfs1(sf[x]),Oh[sf[x]]=-1,dfs2(sf[x]),dfs3(sf[x]);
        int mn2=k+1;rep(i,1,n)if(vis3[i]&&Oh[i]+1<=mid)mn2=min(mn2,If[i]);
        if(mn1+mn2<=k)return 1;
    }
    return 0;
}
void slv(){
    fa[1]=0,dfs1(1),Oh[1]=-1,dfs2(1);
    rep(i,1,n)sf[i]=fa[i];
    int res=n;for(int l=1,r=n;mid=l+r>>1,l<=r;)
    if(check())res=mid,r=mid-1;else l=mid+1;
    cout<<res<<'\n';
}
}
namespace S2{
int f1[N],f2[N];
void dfs1(int u,int pre){
    int mx=0,se=0;
    int MX=0;
    for(auto v:g[u])if(v!=pre){
        dfs1(v,u);
        int t=f1[v]+1;
        if(t>mx)se=mx,mx=t;
        else if(t>se)se=t;
        MX=max(MX,f2[v]);
    }
    f1[u]=mx,f2[u]=max(mx+se,MX);
}
int g1[N],g2[N];
void dfs2(int u,int pre){
    int mx=g1[u]+1,se=0,th=0;
    int MX=g2[u],SE=0;
    for(auto v:g[u])if(v!=pre){
        int t=f1[v]+1;
        if(t>mx)th=se,se=mx,mx=t;
        else if(t>se)th=se,se=t;
        else if(t>th)th=t;
        int T=f2[v];
        if(T>MX)SE=MX,MX=T;
        else if(T>SE)SE=T;
    }
    for(auto v:g[u])if(v!=pre){
        int x=mx,y=se,z=th,t=f1[v]+1;
        if(x==t)x=y,y=z;
        else if(y==t)y=z;
        g1[v]=x;
        int X=MX,Y=SE,T=f2[v];
        if(X==T)X=Y;
        g2[v]=max(X,x+y);
        dfs2(v,u);
    }
}
void slv(){
    dfs1(1,0),g1[1]=g2[1]=-1,dfs2(1,0);
    int ans=n;rep(i,2,n)ans=min(ans,max((f2[i]+1)/2,(g2[i]+1)/2));
    cout<<ans<<'\n';
}
}
void slv(){
    cin>>n>>k;rep(i,1,n)g[i]={};
    rep(i,1,n-1){int x,y;cin>>x>>y;g[x].pb(y),g[y].pb(x);}
    if(k==n)return cout<<"0\n",void();
    if(k==2)return S2::slv();
    return S1::slv();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int csi,T;cin>>csi>>T;while(T--)slv();
    return 0;
}
/*
ulimit -v 1048576;ulimit -s 1048576
g++ -O2 -std=c++14 -static hub.cpp -o %;size %;time ./%
ulimit -s 1048576
g++ -O2 -std=c++14 -fsanitize=address,leak,undefined hub.cpp -o %;size %;time ./%
*/