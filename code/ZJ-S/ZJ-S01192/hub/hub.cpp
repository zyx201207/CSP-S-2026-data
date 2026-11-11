#include<bits/stdc++.h>
// #define int long long
#define ll long long
#define ull unsigned long long
#define ld double
#define uint unsigned
#define PII pair<int,int>
#define umap unordered_map
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define cl(f,x) memset(f,x,sizeof(f))
#define pcnt(x) __builtin_popcount(x)
#define lg(x) (31-__builtin_clz(x))
using namespace std;
void file_IO() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=1e6+5;
int head[N],len;
struct node {
    int to,nxt;
}; node edge[N<<1];
void add_edge(int u,int v) {
    edge[++len]={v,head[u]}; head[u]=len;
}
int d[N],pa[N],rt;
void dfs(int u,int fa) {
    d[u]=d[fa]+1; pa[u]=fa;
    if(d[u]>d[rt])
        rt=u;
    for(int i=head[u];i;i=edge[i].nxt) {
        int v=edge[i].to;
        if(v!=fa)
            dfs(v,u);
    }
}
int maxdep[N],t[N],tot,n,k;
bool inp[N];
int dfs1(int u,int fa,int x) {
    maxdep[u]=0;
    int cnt=0;
    for(int i=head[u];i;i=edge[i].nxt) {
        int v=edge[i].to;
        if(v!=fa&&!inp[v]) {
            cnt+=dfs1(v,u,x);
            chkmax(maxdep[u],maxdep[v]+1);
        }
    }
    if(maxdep[u]>=x)
        ++cnt;
    return cnt;
}
int b[N];
bool check(int x) {
    int res=0;
    vector<PII> vec;
    rep(i,0,tot+1)
        b[i]=0;
    rep(i,1,tot) {
        res+=dfs1(t[i],0,x);
        int d=max(x-maxdep[t[i]],0);
        if(!d)
            --res;
        // debug("%d get (%d,%d) = %d , (%d,%d) = %d\n",i,x+1,i-d
        // ,max(i-d-x,1),i+d,tot-x+1,max(tot-x+1-(i+d),1));
        chkmax(b[max(i-d-x,1)-1],max(tot-x+1-(i+d),1));
    }
    int mn=INF;
    per(i,tot,1) {
        chkmax(b[i],b[i+1]);
        chkmin(mn,i+b[i]);
    }
    return res+mn<=k;
}
void solve() {
    scanf("%d%d",&n,&k);
    rep(i,1,n)
        head[i]=0,inp[i]=false;
    len=tot=0;
    rep(i,2,n) {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    rt=0;
    dfs(1,0);
    int x=rt; rt=0;
    dfs(x,0);
    int y=rt;
    while(y) {
        t[++tot]=y; inp[y]=true;
        if(x==y)
            break;
        y=pa[y];
    }
    // debug("total = %d\n",tot);
    int l=0,r=tot>>1,ans=tot>>1;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    printf("%d\n",ans);
}
bool M2;
// g++ hub.cpp -std=c++14 -O2 -Wall -o hub
signed main() {
    file_IO();
    int _,testcase=1;
    scanf("%d%d",&_,&testcase);
    while(testcase--)
        solve();
    debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}