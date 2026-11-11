#include<bits/stdc++.h>
using lli=long long;
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q;
lli w[M];
int k[N];
struct edge{
    int v;
    lli w;
    bool operator<(const edge& b)const{
        return w>b.w;
    }
};
vector<edge> g[N+M];
lli dis[N+M];
void dijk_0(int s){
    for(int i=1;i<=n+m;i++){
        dis[i]=0x3f3f3f3f3f3f3f3f;
    }
    dis[s]=0;
    priority_queue<edge> q;
    q.push({s,0});
    while(!q.empty()){
        auto [u,d]=q.top();q.pop();
        if(d!=dis[u])continue;
        for(auto [v,w]:g[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
void solve_0(){
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int v,w;
            cin>>v>>w;
            g[m+i].push_back({v,w});
            g[v].push_back({m+i,w});
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        dijk_0(s);
        cout<<dis[t]+w[s]+w[t]<<"\n";
    }
}
void dijk_a1(int s){
    for(int i=1;i<=m;i++){
        dis[i]=0x3f3f3f3f3f3f3f3f;
    }
    dis[s]=0;
    priority_queue<edge> q;
    q.push({s,0});
    while(!q.empty()){
        auto [u,d]=q.top();q.pop();
        if(d!=dis[u])continue;
        for(auto [v,w]:g[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
void solve_a1(){
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int v[3];
        lli w[3];
        for(int j=1;j<=k[i];j++){
            cin>>v[i]>>w[i];
        }
        if(k[i]==1)continue;
        g[v[1]].push_back({v[2],w[1]+w[2]});
        g[v[2]].push_back({v[1],w[1]+w[2]});
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        dijk_a1(s);
        cout<<dis[t]+w[s]+w[t]<<"\n";
    }
}
void solve_b(){
    ;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<7){
        solve_0();
    }else if(c<9){
        solve_a1();
    }
    return 0;
}
