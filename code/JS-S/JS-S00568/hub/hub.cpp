#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back

const int N=1e6+9;
inline int lowbit(int x){return x&(-x);}
inline void chkmin(int &x,int y){x=x<y?x:y;}
inline void chkmax(int &x,int y){x=x>y?x:y;}
inline void chkmin(ll &x,ll y){x=x<y?x:y;}
inline void chkmax(ll &x,ll y){x=x>y?x:y;}

int n,k,mi[22][N],dep[N],dfn[N],idx;
int get(int u,int v){return dep[u]<dep[v]?u:v;}
vector<int> G[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    mi[0][dfn[u]=++idx]=fa;
    for(auto v:G[u]){
        if(v!=fa) dfs(v,u);
    }
}
int lca(int u,int v){
    if(u==v) return u;
    if((u=dfn[u])>=(v=dfn[v])) swap(u,v);
    int d=__lg(v-u++);
    return get(mi[d][u],mi[d][v-(1<<d)+1]);
}
int dist(int u,int v){
    int d=lca(u,v);
    return dep[u]+dep[v]-2*dep[d];
}


bool vis1[N];
void dfs1(int u,int fa,int S){
    vis1[u]=1;
    for(auto v:G[u]){
        if(v!=fa && (S>>(v-1))&1) dfs1(v,u,S);
    }
}
bool check(int S){
    for(int i=1;i<=n;++i) vis1[i]=0;
    int cnt=0;
    for(int i=0;i<n;++i){
        if((S>>i)&1 && !vis1[i+1]){dfs1(i+1,0,S); ++cnt;}
    }
    if(cnt>2) return 0;
    return 1;
}
#define INF (int)(1e9)
void sub1(){
    int ans=INF;
    for(int S=0;S<(1<<n);++S){
        if(!check(S) || __builtin_popcount(S)!=k) continue;
        //for(int i=0;i<n;++i) if((S>>i)&1) cout<<i+1<<' ';
        int mx=0;
        for(int i=0;i<n;++i){
            int tmp=INF;
            for(int j=0;j<n;++j)
                if((S>>j)&1) chkmin(tmp,dist(i+1,j+1));
            chkmax(mx,tmp);
        } chkmin(ans,mx);
    } cout<<ans<<'\n';
}
void Mian(int TestCase){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1,0);
    for(int j=1;j<22;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            mi[j][i]=get(mi[j-1][i],mi[j-1][i+(1<<j-1)]);

    if(n<=10) sub1();
}
void Mianclr(){
    for(int i=1;i<=n;++i) G[i].clear();
    idx=0;
    for(int i=1;i<=n;++i) dfn[i]=dep[i]=0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c=0,T=1; cin>>c>>T;
    while(T--){
        Mian(c);
        Mianclr();
    }
}
