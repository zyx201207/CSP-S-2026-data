#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int c,n,m,d,p;
int wl[maxn];
typedef pair<long long,int>pii;
long long dist[maxn];
bool vis[maxn];
vector<pii>adj[maxn];
long long diser(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii>> qq;
    dist[s]=0;
    qq.push({0,s});
    while(!qq.empty()){
        int u=qq.top().second;
        qq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto &e:adj[u]){
            int v=e.first;
            long long w=e.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                qq.push({dist[v],v});
            }
        }
    }
    return dist[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)cin>>wl[i];
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int cnt;
        for(int j=0;j<a;j++){
            int x,y;
            cin>>x>>y;
            if(j!=0){
                adj[x+m*i].push_back({cnt+m*i,0});
                adj[cnt+m*i].push_back({x+m*i,0});
            }
            adj[x].push_back({x+m*i,y});
            adj[x+m*i].push_back({x,y});
            cnt=x;
        }
    }
    for(int i=1;i<=p;i++){
        int s,t;
        cin>>s>>t;
        cout<<diser(s,t)+wl[s]+wl[t]<<endl;
    }
    return 0;
}
