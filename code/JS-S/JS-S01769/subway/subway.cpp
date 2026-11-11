#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

long long c,n,m,d,q;
long long w[1005];
vector<pair<int,int> > edges[1005];
vector<pair<int,pair<int,int> > > edgesArr;


int fa[1005];
int dist1[1005],dist2[1005][1005];
int getroot(int i){
    if(fa[i]==i) return i;
    return fa[i]=getroot(fa[i]);
}

vector<pair<int,pair<int,int> > > kruskal(){
    sort(edgesArr.begin(),edgesArr.end());
    for(int i=1;i<=500;++i){
        fa[i]=i;
    }
    int cnt=0;
    vector<pair<int,pair<int,int> > > res;
    for(auto edge:edgesArr){
        int u=edge.second.first,v=edge.second.second;
        if(fa[u]!=fa[v]){
            ++cnt;
            res.push_back(edge);
            fa[getroot(u)]=fa[getroot(v)];
        }
        if(cnt==n+m-1){
            break;
        }
    }
    return res;
}

bool isVisited[505];
void dijkstra(int dist[],int s){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    memset(isVisited,false,sizeof isVisited);
    memset(dist,0x3f,4*1000);
    isVisited[s]=true;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto u=pq.top();
        pq.pop();
        for(auto v : edges[u.second]){
            if(dist[v.first]>v.second+dist[u.second]&&!isVisited[v.first]){
                dist[v.first]=v.second+dist[u.second];
                pq.push({dist[v.first],v.first});
                isVisited[v.first]=true;
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;++i){
        cin>>w[i];
    }
    for(int i=1;i<=m;++i){
        int t;
        cin>>t;
        for(int j=1;j<=t;++j){
            int x,v;
            cin>>x>>v;
            edges[n+i].push_back({x,v});
            edges[x].push_back({n+i,v});
            edgesArr.push_back({v,{x,n+i}});
            edgesArr.push_back({v,{n+i,x}});
        }
    }
    if(c>=7&&c<=11){
        auto t=kruskal();
        for(int i=1;i<=n+m;++i){
            edges[i].clear();
        }
        for(auto edge:t){
            int u=edge.second.first,v=edge.second.second,w=edge.first;
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        dijkstra(dist1,1);
        for(int i=1;i<=q;++i){
            int x,y;
            cin>>x>>y;
            cout<<abs(dist1[x]-dist1[y])+w[x]+w[y]<<endl;
        }
    }
    for(int i=1;i<=n;++i){
        dijkstra(dist2[i],i);
    }
    for(int i=1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        cout<<dist2[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}