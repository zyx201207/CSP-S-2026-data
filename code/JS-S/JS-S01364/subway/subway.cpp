#include<bits/stdc++.h>
using namespace std;
const int N=1000+5;
struct node{
    int w,id;
};
bool operator<(node x,node y){
    return x.w>y.w;
}
int k[N];
int w[N];
int c,n,m,d,Q;
int a[505][N];
int t[505][N];
int dis[500*N];
bool vis[500*N];
priority_queue<node> q;
vector<pair<int,int> > G[N];
void Dijkstra(int s){
    while(!q.empty()) q.pop();
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    int sum=0;
    for(int i=1;i<=n;i++){
        if(G[sum+s].size()==0){
            sum+=k[i];
            continue;
        }
        q.push({sum+s,t[i][s]});
        dis[sum+s]=t[i][s];
        sum+=k[i];
    }
    while(!q.empty()){
        int u=q.top().id;
        q.pop();
        if(vis[u]==true) continue;
        vis[u]=true;
        for(auto it:G[u]){
            int v=it.first,w=it.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    int cur=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(j!=1) G[cur+a[i][j]].push_back({cur+a[i][j],t[i][j]});
        }
        cur+=k[i];
    }
    while(Q--){
        int l,r;
        cin>>l>>r;
        Dijkstra(l);
        int ans=1e9;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(G[sum+r].size()==0){
                sum+=k[i];
                continue;
            }
            ans=min(ans,dis[sum+r]);
            sum+=k[i];
        }
        cout<<ans+w[l]+w[r]<<"\n";
    }
    return 0;
}
