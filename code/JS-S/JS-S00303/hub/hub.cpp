#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define m_p make_pair
#define P pair<int,int>
#define lowbit(x) (x&(-x))
#define fr first
#define sc second
typedef long long ll;
vector<int> g[100005];
vector<P> e;
int bu,bv;
int n,k;
int vis[100005];
bool check(int u,int v){
    if(u==bu&&v==bv) return 1;
    if(u==bv&&v==bu) return 1;
    return 0;
}
vector<int> in;
void dfs1(int x,int p){
    in.pb(x);vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        if(u==p||check(x,u)) continue;
        dfs1(u,x);
    }
}
int d[100005];
const int inf=1e9;
int V[100005];
void dfs2(int x,int p,int dep){
    d[x]=dep;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        if(u==p||check(x,u)) continue;
        dfs2(u,x,dep+1);
    }
}
int mx[100005],cnt[100005];
void dfs3(int x,int p){
    mx[x]=1;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        if(u==p||check(x,u)) continue;
        dfs3(u,x);
        mx[x]=max(mx[x],mx[u]+1);
    }
    cnt[mx[x]]++;
}
void go(int x){
    //cout<<"mid "<<x+1<<endl;
    for(int i=0;i<=n;i++){
        mx[i]=inf;
        cnt[i]=0;
    }
    dfs3(x,-1);
    for(int i=n-1;i>=0;i--) cnt[i]+=cnt[i+1];
    //for(int i=0;i<=n;i++) cout<<cnt[i]<<" ";cout<<endl;
    int len=n;
    for(int i=1;i<=n;i++){
        while(len>0&&cnt[len]<=i) len--;
        V[i]=min(V[i],len);
        //cout<<"V "<<i<<" "<<len<<endl;
    }
}
vector<int> Sol(vector<int> a){
    //for(int i=0;i<a.size();i++) cout<<a[i]+1<<" ";cout<<endl;
    for(int i=0;i<=n;i++) V[i]=inf;
    for(int i=0;i<n+2;i++) d[i]=inf;
    dfs2(a[0],-1,0);
    int s=a[0];
    for(int i=0;i<n;i++) if(d[i]!=inf&&d[i]>d[s]) s=i;
    for(int i=0;i<n+2;i++) d[i]=inf;
    dfs2(s,-1,0);
    vector<int> ds;
    int t=a[0];
    for(int i=0;i<n;i++){
        if(d[i]!=inf&&d[i]>d[t]) t=i;
        ds.pb(d[i]);
    }
    for(int i=0;i<n+2;i++) d[i]=inf;
    dfs2(t,-1,0);
    int mn=1e9;
    for(int i=0;i<n;i++) mn=min(mn,max(ds[i],d[i]));
    for(int i=0;i<n;i++) if(max(ds[i],d[i])==mn) go(i);
    vector<int> ans;
    for(int i=0;i<=n;i++) ans.pb(V[i]);
    return ans;
}
int sol(){
    for(int i=0;i<n;i++) vis[i]=0;
    in.clear();
    dfs1(0,-1);
    vector<int> v1=Sol(in),v2;
    in.clear();
    for(int i=0;i<n;i++) if(!vis[i]){
        dfs1(i,-1);
        v2=Sol(in);
        break;
    }
    int ans=1e9;
    for(int i=1;i<k;i++) ans=min(ans,max(v1[i],v2[k-i]));
    //cout<<"ans "<<ans<<endl;
    //cout<<endl;
    return ans;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n+2;i++) g[i].clear();
    e.clear();
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
        e.pb({u,v});
    }
    int ans=inf;
    for(int i=0;i<n-1;i++){
        bu=e[i].fr,bv=e[i].sc;
        ans=min(ans,sol());
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--) solve();
    return 0;
}