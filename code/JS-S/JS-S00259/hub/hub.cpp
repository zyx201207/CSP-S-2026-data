#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define dep(i,e,s) for(int i=e;i>=s;i--)
#define lc id<<1
#define rc id<<1|1
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int maxn=105;
int n,k,fa[maxn];
vector<int> edges[maxn];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
bool check(int x){
    rep(i,1,n) fa[i]=i;
    int cnt1=0,cnt2=0;
    rep(i,1,n){
        if(x&(1<<(i-1))){
            cnt1++;
            for(auto j:edges[i]){
                if(x&(1<<(j-1))){
                    int a=find(i),b=find(j);
                    if(a!=b) fa[a]=b;
                }
            }
        }
    }
    rep(i,1,n) if(x&(1<<(i-1))) if(fa[i]==i) cnt2++;
    if(cnt1>k||cnt2>2||cnt1==0) return 0;
    return 1;
}
int mi[22][maxn],dfn[maxn],idx=0,d[maxn];
int get(int x,int y){return (dfn[x]<dfn[y])?x:y;}
void dfs(int x,int f){
    d[x]=d[f]+1;
    mi[0][dfn[x]=++idx]=f;
    for(auto i:edges[x]){
        if(i!=f){
            dfs(i,x);
        }
    }
}
void init(){
    rep(i,1,__lg(n)){
        rep(j,1,n-(1<<i)+1){
            mi[i][j]=get(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
        }
    }
}
int LCA(int x,int y){
    if(x==y) return x;
    if((x=dfn[x])>(y=dfn[y])) swap(x,y);
    int d=__lg(y-x++);
    return get(mi[d][x],mi[d][y-(1<<d)+1]);
}
int dis(int x,int y){return d[x]+d[y]-d[LCA(x,y)]*2;}
void solve(){
    cin>>n>>k;
    rep(i,1,n) edges[i].clear();
    memset(mi,0,sizeof mi);
    memset(dfn,0,sizeof dfn);
    memset(d,0,sizeof d);
    idx=0;
    rep(i,1,n-1){
        int u,v;
        cin>>u>>v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1,0);
    init();
    int ans=1<<30;
    rep(x,0,(1<<n)-1){
        if(!check(x)) continue;
        int mx=0;
        // rep(i,1,n) if(x&(1<<(i-1))) cout<<i<<" ";
        rep(i,1,n){
            int mn=1<<30;
            rep(j,1,n){
                if(x&(1<<(j-1)))
                mn=min(dis(i,j),mn);
            }
            mx=max(mx,mn);
        }
        // cout<<mx<<"\n";
        ans=min(ans,mx);
    }
    cout<<ans<<"\n";
}
int c,T;
signed main(){
    freopen("hub.in","r",stdin);    
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    if(c>3) return 0;
    while(T--){
        solve();
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/