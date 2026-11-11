#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
const int N=4e3+11,INF=0x3f3f3f3f;
int tid,n,k;
int fa[N],tfa[N];
int f[N][N],g[N][N];
int ps,dps;
int ct[N],mxd[N];
bool del[N];
std::vector<int> G[N];
void clr() {
    for(int i=1;i<=n;i++) {
        G[i].resize(0);
        memset(f[i]+1,0,n<<2);
        memset(g[i]+1,0,n<<2);
    }
}
void dfs(int u,int from) {
    fa[u]=from;
    for(auto v:G[u])
        if(v!=from) dfs(v,u);
}
void Gps(int u,int from,int d) {
    tfa[u]=from;
    if(!ps||d>dps) ps=u,dps=d;
    for(auto v:G[u])
        if(!del[v]&&v!=from) Gps(v,u,d+1);
}
void Gmxd(int u,int from) {
    mxd[u]=0;
    for(auto v:G[u])
        if(!del[v]&&v!=from) Gmxd(v,u),mxd[u]=std::max(mxd[v],mxd[u]);
    ct[++mxd[u]]++;
    // db("%d,%d\n",u,mxd[u]);
}
void calc(int p,int *f) {
    ps=dps=0,Gps(p,0,0);
    int t=ps;
    ps=dps=0,Gps(t,0,0);
    int d=dps>>1;
    while(d--) ps=tfa[ps];
    // db("ps=%d\n",ps);
    memset(ct+1,0,n<<2);
    Gmxd(ps,0);
    // for(int i=1;i<=n;i++) db("%d%c",ct[i]," \n"[i==n]);
    for(int i=n-1;i>=1;i--) ct[i]+=ct[i+1];
    for(int i=1;i<=n;i++) {
        int x=ct[i]-ct[i+1];
        while(x--) f[--ct[i]]=i;
    } 
}
void slv() {
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        if(i>1) {
            // db("Csub %d:\n",i);
            del[i]=1,calc(fa[i],g[i]),del[i]=0;
            // db(" => ");
            // for(int j=1;j<=n;j++) db("%d%c",g[i][j]," \n"[j==n]);
            // db("\n\n");
        }
        // db("sub %d:\n",i);
        del[fa[i]]=1,calc(i,f[i]),del[fa[i]]=0;
        // db("=> ");
        // for(int j=1;j<=n;j++) db("%d%c",f[i][j]," \n"[j==n]);
        // db("\n\n");
    }
    int rs=f[1][k];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<k;j++)
            rs=std::min(rs,std::max(f[i][j],g[i][k-j]));
        // db("=> %d\n",rs);
    }
    cout<<rs<<'\n';
}
int main() {
    int T; cin>>tid>>T;
    while(T--) slv(),clr();   
    return 0;
}