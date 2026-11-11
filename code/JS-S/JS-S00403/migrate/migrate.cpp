#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
const int inf=0x3f;
struct node{
    int u,dis;
    bool operator>(const node &other)const{return dis>other.dis;}
};
priority_queue<node,vector<node>,greater<node>> pq;
int dis[N][N];
int cnt[N][N];
int x[N];
int vis[N][N];
vector<int> g[N];
queue<int> q;
int n,d;
int ans=0;
void dijikstra(int s){
    while(!pq.empty()) pq.pop();
    memset(vis,0,sizeof(vis));
    pq.push({s,0}); dis[s][s]=0; cnt[s][s]=1;
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        int u=cur.u,dist=cur.dis;
        for(int v:g[u]){
            if(dis[s][v]>dist+1){
                dis[s][v]=dist+1;
                cnt[s][v]=1;
                pq.push({v,dis[s][v]});
            }
            else if(dis[s][v]==dist+1) cnt[s][v]++;
        }
    }
}
void solve(){
    cin>>n>>d;
    ans=0;
    memset(dis,inf,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d) {
                //cout<<i<<" "<<j<<endl;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
        g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
    }
    for(int i=1;i<=n;i++) dijikstra(i);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt[i][j]==2) {
                ans++;
                //cout<<dis[i][j]<<" ";
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    //cout<<dis[0][2]<<endl;
    //cout<<dis[2][5]<<endl;
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        solve();
    }
}
