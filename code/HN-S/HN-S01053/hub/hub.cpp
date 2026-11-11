#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define popcount(x) __builtin_popcount(x)
#define endl '\n'
int o,T,n,k;
const int N = 2e6+10,inf=1e18;
int ans=inf;
vector<int>g[N];
bitset<N>v;
int vis[N],fa[N],siz[N],mx[N];
int dep[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(siz[x]>siz[y])swap(x,y);
    fa[x]=y;
    siz[y]+=siz[x];
}
void tdfs(int x,int f){
    dep[x]=dep[f]+1;
    for(auto v:g[x]){
        if(v==f)continue;
        tdfs(v,x);
    }
}
void check(){
    v.reset();
    for(int i=1;i<=n;i++){
        fa[i]=i;siz[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            for(auto v:g[i]){
                if(vis[v]){
                    merge(i,v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            v[find(i)]=1;
        }
    }
    if(v.count()>2)return;
    int mx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            tdfs(i,0);
            int d=inf;
            for(int j=1;j<=n;j++){
                if(vis[j]){
                    d=min(d,dep[j]-1);
                }
            }
            //cout<<d<<endl;
            mx=max(mx,d);
        }
    }
    ans=min(ans,mx);
}
void dfs(int c,int t){
    if(c==n+1){
        if(t!=k)return;
        check();
        return;
    }
    if(t==k){
        check();
        return;
    }
    vis[c]=1;
    dfs(c+1,t+1);
    vis[c]=0;
    dfs(c+1,t);
    vis[c]=0;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>o>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        cout<<ans<<endl;
        ans=inf;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
    }
    return 0;
}