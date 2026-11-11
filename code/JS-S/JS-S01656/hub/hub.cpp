#include<bits/stdc++.h>
using namespace std;

vector<int> g[N];

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int ans=LLONG_MAX;
    for(int msk=0;msk<(1<<n);msk++){
        int cnt=0;
        vector<int> vis(n+1)
        for(int i=1;i<=n;i++) if(msk>>i-1&1) cnt++,vis[i]=1;
        if(cnt!=k) continue;
        queue<int> q;
        for(int i=1;i<=n;i++) if(vis[i]) q.push(i);
        vector<int> dist(n+1);
        while(q.size()){
            int x=q.front();q.pop();
            for(auto y:g[x]) if(dist[y]==-1)
                dist[y]=dist[x]+1,q.push(y);
        }
        int tmp=0;
        for(int i=1;i<=n;i++) tmp=max(tmp,dist[i]);
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,tc;cin>>c>>tc;
    while(tc--) solve();
    return 0;
}
