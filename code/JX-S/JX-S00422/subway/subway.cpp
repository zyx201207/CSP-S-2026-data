#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
const int N=405;
int c,n,m,d,q;
ll w[N],t[N][N];
vector<pair<int,ll>>e[105];//subway to station
vector<pair<int,ll>>e2[N];//station to subway
vector<pair<int,ll>>e3[105];//subway to subway
ll dis[105],vis[105];
void dijkstra(int st,int en){
    priority_queue<pair<ll,int>>pq;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(auto x:e2[st]){
        pq.push(make_pair(-w[st]-x.second,x.first));
        dis[x.first]=w[st]+x.second;
    }
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto x:e3[u]){
            int v=x.first;
            ll w=x.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(make_pair(-dis[v],v));
            }
        }
    }
    
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin >> x >> y;
            e2[x].push_back(make_pair(i,y));
            e[i].push_back(make_pair(x,y));
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(auto x:e2[i]){
    //         cout << x.first<<"cccc";
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(auto x:e[i]){
            for(int j=i+1;j<=n;j++){
                for(auto y:e[j]){
                    if(x.first==y.first){
                        
                        e3[i].push_back(make_pair(j,x.second+y.second));
                        e3[j].push_back(make_pair(i,x.second+y.second));
                        
                        break;
                    }
                }

            }
        }
        
    }
    
    for(int i=1;i<=q;i++){
        int x,y;
        cin >> x >> y;
        dijkstra(x,y);
        ll ans=1e18;
        for(auto cnm:e2[y]){
            // cout << dis[cnm.first]<<"ccc";
            ans=min(ans,dis[cnm.first]+cnm.second+w[y]);
        }
        cout << ans<<"\n";
    }
    return 0;
}