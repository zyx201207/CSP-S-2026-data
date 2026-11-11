#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,k,res;
vector <int> a;
vector <int> to[maxn];
int fa[maxn];
bool vis[maxn];
bool flag[maxn];
int dis[maxn];
inline int find(int x) {
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}
inline void check () {
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=0;i<k;++i) {
        int u=a[i];
        for(int j=0;j<to[u].size();++j) {
            int v=to[u][j];
            if(vis[v]) fa[find(u)]=find(v);
        }
    }
    int tot=0;
    for(int i=1;i<=n;++i) flag[i]=false;
    for(int i=0;i<k;++i) {
        if(flag[find(a[i])]) continue;
        ++tot;
        flag[find(a[i])]=true;
    }
    if(tot>2) return ;
    for(int i=1;i<=n;++i) dis[i]=n+1;
    queue <int> q;
    for(int i=0;i<k;++i) {
        dis[a[i]]=0;
        q.push(a[i]);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0;i<to[u].size();++i) {
            int v=to[u][i];
            if(dis[u]+1 < dis[v]) {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,dis[i]);
    res=min(res,ans);
    return ;
}
inline void Choose(int x,int End) {
    if(x==k+1) {
        check();
        return;
    }
    for(int i=End;i<=n;++i)  {
        a.push_back(i);
        vis[i]=true;
        Choose(x+1,i+1);
        vis[i]=false;
        a.pop_back();
    }
}
inline void solve () {
    cin>>n>>k;
    for(int i=1;i<=n;++i) to[i].clear();
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    res=n;
    Choose(1,1);
    cout<<res<<'\n';
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T; cin>>c>>T;
    while(T--) {
        solve();
    }
    return 0;
}
