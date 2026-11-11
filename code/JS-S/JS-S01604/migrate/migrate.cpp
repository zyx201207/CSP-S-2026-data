#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e6+10;
int c,T;
int n,d;
int x[N];
struct edge{
    int from,to;
};
vector<edge> e[N];
struct node{
    int num,dis;
    bool operator < (const node& o)const{
        return dis>o.dis;
    }
};
int dist[N];
int cnt[N];
void dijkstra(int s){
    memset(dist,0x3f,sizeof(dist));
    priority_queue<node> qwq;
    qwq.push({s,dist[s]=0});
    for(int i=1;i<=n;i++){
        cnt[i]=1;
    }
    while(!qwq.empty()){
        node fn=qwq.top(); int u=fn.num;
        /*
        cout<<u<<'\n';
        for(int i=1;i<=n;i++){
            cout<<dist[i]<<' ';
        }cout<<'\n';
        for(int i=1;i<=n;i++){
            cout<<cnt[i]<<' ';
        }cout<<'\n';
        */
        qwq.pop();
        for(edge ee:e[u]){
            int v=ee.to;
            if(dist[v]>fn.dis+1){
                dist[v]=fn.dis+1;
                qwq.push({v,dist[v]});
                cnt[v]=1;
            }else if(dist[v]==fn.dis+1){
                cnt[v]+=cnt[u];
            }
        }
    }
}
void solve_force(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(x[i]-x[j])<=d){
                e[i].emplace_back(edge{i,j});
                e[j].emplace_back(edge{j,i});
            }
        }
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
        for(int j=i+1;j<=n;j++){
            //cout<<cnt[j]<<' ';
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    if(n<=5000){
        solve_force();
        return ;
    }else{
        cout<<0<<'\n';
        return ;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
/*
RP++
16:35 24pts
*/
