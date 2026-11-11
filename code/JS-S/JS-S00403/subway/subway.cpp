#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10;
const int inf=0x3f3f3f3f;
int dis[N][N];
int a[N][N];
int t[N][N];
int pos[N][N];
int w[N],k[N];
int vis[N];
struct edge{
    int v,w;
};
vector<edge> g[N];
struct node{
    int u,dis;
    bool operator>(const node &other)const{return dis<other.dis;}
};
priority_queue<node,vector<node>,greater<node>> pq;
int n,m,d,q;
int tot;
void dijikstra(int s){
    while(!pq.empty()) pq.pop();
    memset(vis,0,sizeof(vis));
    pq.push({s,0});dis[s][s]=0;
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        int u=cur.u,dist=cur.dis;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto x:g[u]){
            int v=x.v,w=x.w;
            if(dis[s][v]>dist+w){
                dis[s][v]=dist+w;
                pq.push({v,dis[s][v]});
            }
        }
    }
}
void sp1(){
    for(int i=1;i<=m;i++){
        int u=a[i][1],v=a[i][2];
        int val=t[i][1]+t[i][2];
        g[u].push_back({v,val});
        g[v].push_back({u,val});
    }
    for(int i=1;i<=m;i++) dijikstra(i);
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int cpos;cin>>cpos;
    cin>>n>>m>>d>>q;
    bool flag1=1,flag2=1;
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]>2) flag1=0;
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    if(flag1){
        sp1();
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            int u=a[i][j],v=a[i][j+1];
            int val1=t[i][j],val2=t[i][j+1];
            if(!pos[i][j]) pos[i][j]=m+(++tot);
            if(!pos[i][j+1]) pos[i][j+1]=m+(++tot);
            int u1=pos[i][j],v1=pos[i][j+1];
            //cout<<u1<<" "<<v1<<endl;
            g[u1].push_back({v1,0});g[v1].push_back({u1,0});
            g[u1].push_back({u,val1});g[u].push_back({u1,val1});
            if(j==k[i]-1) g[v1].push_back({v,val2});g[v].push_back({v1,val2});
        }
    }
    for(int i=1;i<=m;i++) dijikstra(i);
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++) cout<<pos[i][j]<<" ";
        cout<<"\n";
     }*/
    for(int i=1;i<=q;i++){
        int u,v;cin>>u>>v;
        cout<<dis[u][v]+w[u]+w[v]<<"\n";
    }
    return 0;
}
