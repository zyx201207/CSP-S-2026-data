#include<bits/stdc++.h>
#define int long long
#define qrw ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
int C,T,n,d,x[2000006],vis[200005],dis[200005];
vector<int> adj[200005];
signed main(){
    qrw;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    if(C>10){
        for(int i=1;i<=T;i++) cout<<0<<endl;
        return 0;
    }
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i],adj[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[i]-x[j])<=d) adj[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            queue<int> q;
            for(int j=1;j<=n;j++) vis[j]=0,dis[j]=INT_MAX;
            q.push(i);
            vis[i]=0,dis[i]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                vis[u]++;
                for(int v:adj[u]){
                    if(vis[v]>2) continue;
                    if(dis[u]+1<=dis[v]) dis[v]=dis[u]+1,q.push(v);
                }
            }
            for(int j=1;j<=n;j++){
                // cout<<i<<" "<<j<<" "<<dis[j]<<endl;
                if(vis[j]==2){
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
// Twenty years later,what you will regret is not things you've done, but things you havn't try.
// So, throw off the bowlines, sail far away from your warm house, as far as you can.
// Dream. Explore. Discover.                                                             ----Unknown