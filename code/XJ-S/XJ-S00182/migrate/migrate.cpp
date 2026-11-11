#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,D,t,c;
int x[N],cnt[N];
struct node{
    int to,w;
    bool operator<(const node &other) const{
        return w>other.w;
    }
};
vector<node> e[N];
int dist[N];//思路：每当到达一个点时，如果新最短路=原最短路，cnt++
void bfs(int start){
    memset(dist,0x3f,sizeof(dist));
    memset(cnt,-1,sizeof(cnt));
    priority_queue<node> q;
    q.push({start,0});
    dist[start]=0;
    while(!q.empty()){
        auto cur=q.top();
        q.pop();
        int u=cur.to,d=cur.w;
        for(auto nxt:e[u]){
            int v=nxt.to,w=nxt.w;
            if(d+w<dist[v]){
                cnt[v]=1;
                dist[v]=d+w;
                q.push({v,dist[v]});
                // printf("1\\%d->%d,d=%d,w=%d,dist[%d]=%d,cnt[%d]=%d\n",u,v,d,w,v,dist[v],v,cnt[v]);
            }
            else if(d+w==dist[v]){
                cnt[v]++;
                // printf("2\\%d->%d,d=%d,w=%d,dist[%d]=%d,cnt[%d]=%d\n",u,v,d,w,v,dist[v],v,cnt[v]);
            }
        }
    }
}
void solve(){
    int ans=0;
    cin>>n>>D;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            int d=abs(x[i]-x[j]);
            if(d<=D){
                e[i].push_back({j,d});
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<":";
    //     for(auto x:e[i]){
    //         cout<<x.to<<','<<x.w<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++){
        bfs(i);
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
}