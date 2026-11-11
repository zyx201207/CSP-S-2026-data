#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define INF 0x3f3f3f3f
#define endl '\n'
// #define int ll
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0' or ch>'9') {if (ch=='-') f=-f;ch=getchar();}
    while (ch>='0' and ch<='9') x=x*10+(ll)(ch-'0'),ch=getchar();
    return x*f;
}
ll gcd(ll x,ll y){
    if (y==0) return x;
    return gcd(y,x%y);
}
ll qpow(ll x,ll y,ll mod){
    ll ans=1;
    if (mod==-1) mod=1e18;
    while (y){
        if (y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
const int N=1e6;
int n,k,fa[N+5][30],dep[N+5],di[N+5],ans;
vector<int> e[N+5];
bool vis[N+5],flot[N+5];
void dfs(int u,int from){
    fa[u][0]=from,dep[u]=dep[from]+1;
    for (int v:e[u]){
        if (v==from) continue;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if (dep[x]<dep[y]) swap(x,y);
    for (int j=21;j>=0;j--) if (dep[fa[x][j]]>=dep[y]) x=fa[x][j];
    if (x==y) return x;
    for (int j=21;j>=0;j--) if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
    return fa[x][0];
}
void bfs(int st){
    queue<int> q;
    q.push(st);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int v:e[u]){
            if (!vis[v] or flot[v]) continue;
            flot[v]=true;
            q.push(v);
        }
    }
}
bool check(){
    int cnt=0;
    for (int i=1;i<=n;i++) flot[i]=false;
    for (int i=1;i<=n;i++) if (vis[i] and !flot[i]) { bfs(i);cnt++; }
    return cnt>2;
}
void dfs1(int x,int cnt){
    if (x==n+1){
        if (cnt!=k) return;
        if (check()) return;
        // for (int i=1;i<=n;i++) cerr<<vis[i]<<" ";
        // cerr<<endl;
        for (int i=1;i<=n;i++){
            if (vis[i]) di[i]=0;
            else di[i]=1e9;
        }
        int sum=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (!vis[j]) continue;
                if (i==j) continue;
                int lc=lca(i,j);
                di[i]=min(di[i],dep[i]+dep[j]-2*dep[lc]);
                sum=max(sum,di[i]);
            }
        }
        // for (int i=1;i<=n;i++) cerr<<di[i]<<" ";
        // cerr<<endl;
        // cerr<<sum<<endl<<endl;
        ans=min(ans,sum);
        return;
    }
    dfs1(x+1,cnt);
    if (cnt<k){
        vis[x]=true;
        dfs1(x+1,cnt+1);
        vis[x]=false;
    }
}
void init(){
    for (int i=1;i<=n;i++) e[i].clear();
}
void solve(){
    n=read(),k=read();
    init();
    for (int i=1;i<n;i++){
        int u=read(),v=read();
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0);
    for (int j=1;j<=24;j++) for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
    ans=1e9;
    dfs1(1,0);
    printf("%d\n",ans);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll cc=read();
    ll t=read();
    while (t--) solve();
    return 0;
}