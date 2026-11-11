#include <iostream>
#include <cstdio>
#include <limits.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long LL;

struct Edge{
    LL v,w;
    Edge(){}
    Edge(LL a,LL b):v(a),w(b){}
    friend bool operator< (const Edge& a,const Edge& b){
        return a.w>b.w;
    }
};

LL c,n,m,d,q;
LL w[500005],k[500005],t[505][500005];
vector<int> e[505],e1[500005];
vector<Edge> edge[505];
LL dis[505][505];
bool flag[505];

void dijkstra(int s){
    for(int i=1;i<=n;i++){
        dis[s][i]=LONG_LONG_MAX;
    }
    dis[s][s]=0;
    memset(flag,false,sizeof(flag));
    priority_queue<Edge> pq;
    pq.push({s,dis[s][s]});
    while(!pq.empty()){
        int u=pq.top().v;
        pq.pop();
        if(!flag[u]){
            flag[u]=true;
            for(Edge e:edge[u]){
                LL v=e.v,w=e.w;
                if(!flag[v]&&dis[s][v]>dis[s][u]+e.w){
                    dis[s][v]=dis[s][u]+e.w;
                    pq.push({v,dis[s][v]});
                }
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x;
            cin>>x>>t[i][x];
            e[i].push_back(x);
            e1[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int x:e[i]){
            for(int y:e1[x]){
                if(y!=i){
                    edge[i].push_back({y,t[i][x]+t[y][x]});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        LL ans=LONG_LONG_MAX;
        for(int i:e1[x]){
            for(int j:e1[y]){
                if(dis[i][j]!=LONG_LONG_MAX){
                    ans=min(ans,t[i][x]+t[j][y]+dis[i][j]);
                }
            }
        }
        cout << w[x]+w[y]+ans<<endl;
    }
    return 0;
}
