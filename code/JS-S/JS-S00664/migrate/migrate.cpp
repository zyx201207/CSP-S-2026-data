#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int u,dis;};
const int MAXN=2e6+5;
int C,T;
int n,d;
int a[MAXN];
int vis[MAXN];
int f[MAXN];
queue<node> q;
int bfs(int s){
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    q.push({s,0});
    while(!q.empty()){
        int u=q.front().u;int dis=q.front().dis;q.pop();
        if(!f[u]){f[u]=dis;vis[u]++;}
        else if(f[u]==dis) vis[u]++;
        int t=upper_bound(a+u+1,a+n+1,a[u]+d)-a;
        for(int v=u+1;v<t;v++) q.push({v,dis+1});
    }
    int ret=0;
    for(int i=s+1;i<=n;i++) if(vis[i]==2) ret++;
    return ret;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<n-1;i++) ans+=bfs(i);
        cout<<ans<<'\n';
    }
    return 0;
}
