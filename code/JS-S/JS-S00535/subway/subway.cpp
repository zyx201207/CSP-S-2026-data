// Subway
// subway.cpp
#include<bits/stdc++.h>
using namespace std;
#define LOGGER 0
#if LOGGER == 1
#define LOG(k) k
#else
#define LOG(k)
#endif
typedef long long sll;
typedef unsigned long long ull;
constexpr ull INF = 9223372036854775807LL;
constexpr int M=5e5+5;
constexpr int N=505;
constexpr int Q=1e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
struct Query{int x;int y;};
Query query[Q];
struct Edge{int fr;int to;ull w;};
// M sta-out M sta-cen N route
vector<Edge> edges[M*2+N];
ull dis[M*2+N];
unordered_map<int,map<int,ull>> his;
unordered_map<int,int> qex;
void add(int a,int b,ull w){
    edges[a].push_back({a,b,w});
    edges[b].push_back({b,a,w});
}
struct EnvEdge{int so;int fr;int to;ull w;};
bool operator<(const EnvEdge& e1,const EnvEdge& e2){
    return dis[e1.fr]+e1.w < dis[e2.fr]+e2.w;
}
bool mapex(int fr){
    return his.find(fr) != his.end();
}
bool exist(int fr,int to){
    return mapex(fr) && his[fr].find(to) != his[fr].end();
}
ull find(int i){
    if(exist(query[i].x,query[i].y)){
        // LOG(cerr<<"Cache hit!"<<endl;)
        return his[query[i].x][query[i].y];
    }
    priority_queue<EnvEdge> que;
    for(int j=1;j<=m*2+n;j++)dis[j]=INF;
    dis[query[i].x]=0;
    que.push({query[i].x,query[i].x,query[i].x,0});
    while(!que.empty()){
        auto e=que.top();que.pop();
        // if(mapex(e.to)){
        //     for(auto &ne:his[e.to]){
        //         if(dis[e.to]+ne.second<dis[ne.first]){
        //             dis[ne.first]=dis[e.to]+ne.second;
        //             que.push({e.so,e.to,ne.first,ne.second});
        //         }
        //     }
        // }
        for(auto& ne:edges[e.to]){
            // LOG(cerr<<"Find edge : "<<ne.fr<<" , "<<ne.to<<"("<<dis[ne.fr]<<","<<dis[ne.to]<<")"<<ne.w<<endl;)
            if(dis[ne.fr]+ne.w<dis[ne.to]){
                dis[ne.to]=dis[ne.fr]+ne.w;
                que.push({e.so,ne.fr,ne.to,ne.w});
            }
        }
    }
    // LOG(cerr<<"Done for "<<query[i].x<<endl;)
    if(!mapex(query[i].x))his[query[i].x]={};
    for(auto &j:qex){
        his[query[i].x][j.first]=dis[j.first];
        if(!mapex(j.first))his[j.first]={};
        his[j.first][query[i].x]=dis[j.first];
    }
    // LOG(cerr<<"Save cache."<<endl;)
    return dis[query[i].y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // LOG(cerr<<"Starting test."<<endl;)
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        int a;ull t;
        for(int j=1;j<=k[i];++j){
            cin>>a>>t;
            add(m*2+i,m+a,t);
        }
    }
    for(int i=1;i<=q;++i){
        cin>>query[i].x>>query[i].y;
        add(query[i].x,m+query[i].x,w[query[i].x]);
        add(query[i].y,m+query[i].y,w[query[i].y]);
        qex[query[i].y]=1;
    }
    for(int i=1;i<=q;++i){
        cout<<find(i)<<endl;
    }
    return 0;
}
