#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[1010];
int dist[1010];
int vis[1010];
signed main(){
    ios::sync_with_stdio(0)；
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<pair<int,int> > e[1010];
    for(int i=1;i<=n;i++){
        int st,ed;
        int cs1;
        int cs2;
        cin>>st>>cs1>>ed>>cs2;
        int cost=cs1+cs2;
        e[st].push_back({ed,cost});
        e[ed].push_back({st,cost});
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<>> pq;
        memset(dist,2e18,sizeof(dist));
        memset(vis,0,sizeof(vis));
        pq.push({0,x});
        while(!pq.empty()){
            pair<int,int> pp=pq.top();
            pq.pop();
            int dis=pp.first;
            int u=pp.second;
            for(auto v:e[u]){

                int to=v.first;
                if(vis[to]) continue;
                vis[to]=1;
                int len=v.second;
                if(dist[to]<dis+len){
                        dist[to]=dis+len;
                    pq.push({dist[to],to});

                }
            }
        }
        cout<<w[x]+w[y]+dist[y]<<endl;

    }
}
