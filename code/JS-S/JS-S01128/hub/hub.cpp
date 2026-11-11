#include<bits/stdc++.h>
#define ll long long
#define mxn 1000003
#define md 998244353
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rept(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
    int x=0;bool fl=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')fl=1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return fl?-x:x;
}
struct node{
    int x,y;
}e[mxn];
int T,n,k,rt,r1,ds,mid,c[mxn],d[mxn],d2[mxn],f1[mxn];
int t,t1,st[mxn],s[mxn];
int tmp[mxn<<1],*now,*g[mxn];
bool fl,v[mxn],b[mxn];
inline void add(int x,int y){
    *(--g[x])=y,*(--g[y])=x;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;
    if(d[x]>d[rt])rt=x;
    for(int i=0,y;i<c[x];++i)if((y=g[x][i])!=fa)dfs(y,x);
}
void dfs1(int x,int fa){
    if(!fl)st[++t]=x;
    if(x==r1)fl=1;
    for(int i=0,y;i<c[x];++i)if((y=g[x][i])!=fa)dfs1(y,x);
    if(!fl)t--;
}
void dfs2(int x,int fa){
    ds=max(ds,t1);
    s[++t1]=x;
    if(t1>mid+1)v[s[t1-mid]]=1;
    for(int i=0,y;i<c[x];++i)if((y=g[x][i])!=fa&&!b[y])dfs2(y,x);
    t1--;
}
bool check(){
    fill(v+1,v+n+1,0);
    rep(i,1,t){
        ds=0;
        dfs2(st[i],0);
        d2[i]=min(ds,mid);
    }
    int c=0;
    rep(i,1,n)if(v[i])c++;
    if(c>k)return 0;
    int l1=1+mid,l2=t-mid,r2=t-mid;
    f1[mid]=1+mid;
    rep(i,1+mid,t-mid){
        f1[i]=f1[i-1];
        if(i-mid+d2[i]>=l1)f1[i]=max(f1[i],i-mid+d2[i]);
    }
    drep(i,t-mid,1+mid){
        if(i+mid-d2[i]<=r2)l2=min(l2,i+mid-d2[i]);
        if(c+f1[i-1]-l1+1+r2-l2+1<=k)return 1;
    }
    return c+r2-l1+1<=k;
}
void solve(){
    n=read(),k=read();
    rep(i,1,n)c[i]=0;
    for(int i=1,x,y;i<n;++i){
        x=read(),y=read();
        c[x]++,c[y]++;
        e[i]={x,y};
    }
    now=tmp;
    rep(i,1,n)now+=c[i],g[i]=now;
    rept(i,1,n)add(e[i].x,e[i].y);
    rt=t=0,fl=0;
    dfs(1,0);r1=rt;
    dfs(r1,0);dfs1(rt,0);
    fill(b+1,b+n+1,0);
    rep(i,1,t)b[st[i]]=1;
    int l=0,r=(t-1)>>1;
    while(l<r){
        mid=(l+r)>>1;
        if(check())r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(),T=read();
    while(T--)solve();
    return 0;
}