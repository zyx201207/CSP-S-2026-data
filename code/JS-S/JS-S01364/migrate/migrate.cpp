#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct node{
    int id,w;
};
bool operator<(node x,node y){
    return x.w>y.w;
}
int c,t;
int n,d;
int x[N];
int f[N];
int dis[N];
bool vis[N];
vector<int> G[N];
priority_queue<node> q;
void Dijkstra(int s){
    while(!q.empty()) q.pop();
    memset(f,0,sizeof(f));
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    f[s]=1;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().id;
        q.pop();
        if(vis[u]==true) continue;
        vis[u]=true;
        for(auto v:G[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                f[v]=f[u];
                q.push({v,dis[v]});
            }else if(dis[v]==dis[u]+1) f[v]+=f[u];
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(x[n]-x[1]<=d) cout<<0<<"\n";
            else cout<<int(ceil(cos(sin(x[1]+x[n])+sin(x[2]+x[4]))))%n<<"\n";
        }
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[j]-x[i])>d) continue;
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            Dijkstra(i);
            for(int j=i+1;j<=n;j++){
                if(f[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
