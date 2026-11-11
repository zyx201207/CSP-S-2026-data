#include <bits/stdc++.h>
using namespace std;
struct unionFind{
    vector<int> fa;
    int sz;
    int get(int x){
        return fa[x]==x?x:fa[x]=get(fa[x]);
    }
    void unite(int x,int y){
        int rx=get(x);
        int ry=get(y);
        fa[rx]=ry;
    }
    unionFind(int siz):sz(siz){
        fa.resize(siz);
        for(int i=0;i<siz;i++){
            fa[i]=i;
        }
    }
};
void dijkstra(const vector<vector<pair<int,int>>>& adj,int source,vector<int>& cont){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    cont.assign(adj.size(),INT_MAX);
    cont[source]=0;
    while(!pq.empty()){
        auto d=pq.top().first;
        auto u=pq.top().second;
        pq.pop();
        if(d>cont[d]) continue;
        for(int i=0;i<adj[u].size();i++){
            auto v=adj[u][i].first;
            auto w=adj[u][i].second;
            if(d+w<cont[v]){
                cont[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }
}
int main(){
    #define int long long
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> constantCost(m);
    vector<vector<int>> changeCost(n,vector<int>(m,-1));
    unionFind reachable(m);
    vector<vector<pair<int,int>>> adj(m);
    for(int i=0;i<m;i++){
        cin>>constantCost[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        int lasta=-1;
        for(int j=0;j<k;j++){
            int t,a;
            cin>>a>>t;
            a--;
            changeCost[i][a]=t;
            if(lasta!=-1){
                reachable.unite(lasta,a);
                adj[lasta].emplace_back(a,i);
                adj[a].emplace_back(lasta,i);
            }
            lasta=a;
        }
    }
    for(int i=0;i<q;i++){
        int s,e;
        cin>>s>>e;
        s--,e--;
        vector<int> dist(m,INT_MAX);
        vector<int> endingColor(m,INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        for(int j=0;j<n;j++){
            if(changeCost[j][s]!=-1)
            pq.push({constantCost[s]+changeCost[j][s]+
                     constantCost[e],j,s});
        }
        while(!pq.empty()){
            int d,color,u;
            tie(d,color,u)=pq.top();
            pq.pop();
            for(int j=0;j<adj[u].size();j++){
                int v=adj[u][j].first;
                int color2=adj[u][j].second;
                int w=0;
                if(color!=color2){
                    w=changeCost[color][u]+changeCost[color2][u];
                }
                //cout<<"On node "<<u<<" with color "<<color<<" proceeding edge to "<<v<<" with color "<<color2<<endl;
                //cout<<"w="<<w<<",dist[v]="<<dist[v]<<",d+w="<<d+w<<endl;
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    endingColor[v]=color2;
                    pq.push({d+w,color2,v});
                }
            }
        }
        if(endingColor[e]==INT_MAX) continue;
        //cout<<"dist[e]="<<dist[e]<<",endingColor[e]="<<endingColor[e]<<endl;
        cout<<dist[e]+changeCost[endingColor[e]][e]<<endl;
    }
    #undef int
    return 0;
}
// ________  ________
//|  ____  ||  ____  |   __      __    __
//| |____| || |____| | _|  |_  _|  |_ |__|
//|  ____  ||  ______||_    _||_    _| __
//|_|    \_\|_|         |__|    |__|  |_/
//    R         P        +       +     ;
