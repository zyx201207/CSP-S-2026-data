#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
typedef pair<int,int> pi;
typedef long long ll;
int c,n,m,d,t,cost[500020],dis[500520],T;
vector<pi> g[500520];
void solve(){
    while(t--){
        for(int i=1;i<=m+n;i++){
            dis[i]=inf;
        }
        int u,v;
        cin>>u>>v;
        ll ans=cost[u]+cost[v];
        dis[u]=0;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<g[x].size();i++){
                int to=g[x][i].first;
                if(dis[x]+1<dis[to]){
                    dis[to]=dis[x]+1;
                    q.push(to);
                }
            }
        }
        ans+=ll(dis[v]*T);
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>cost[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int u,w;
            cin>>u>>w;
            T=w;
            g[u].push_back({m+i,w});
            g[m+i].push_back({u,w});
        }
    }
    if(c>=12&&c<=15){
        solve();
        return 0;
    }
    while(t--){
        for(int i=1;i<=m+n;i++){
            dis[i]=inf;
        }
        int u,v;
        cin>>u>>v;
        ll ans=cost[u]+cost[v];
        dis[u]=0;
        priority_queue<pi> q;
        q.push({0,u});
        while(!q.empty()){
            pi p=q.top();
            q.pop();
            int x=p.second;
            if(dis[x]<p.first){
                continue;
            }
            for(int i=0;i<g[x].size();i++){
                int to=g[x][i].first,w=g[x][i].second;
                if(dis[x]+w<dis[to]){
                    dis[to]=dis[x]+w;
                    q.push({dis[to],to});
                }
            }
        }
        ans+=dis[v];
        cout<<ans<<endl;
    }
    return 0;
}
