#include <bits/stdc++.h>
using namespace std;

//istream &fin=cin;
//ostream &fout=cout;
ifstream fin("subway.in");
ofstream fout("subway.out");
#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

using u8=unsigned char;
using u32=unsigned;
using i32=int;
using u64=unsigned long long;
using i64=long long;

#define FOR(i,a,b) for(u32 i=a;i<=(b);i++)
#define REP(i,a,b) for(u32 i=a;i<(b);i++)
#define RFOR(i,a,b) for(u32 i=(a)+1;i-->b;)

template<typename T,typename U=T>
bool ckmin(T&a,U&&b){
    return b<a&&(a=forward<U>(b),true);
}

constexpr u32 kN=505,kM=500'005,kV=kN+kM;
constexpr u64 kInf=4e18;
u32 c,n,m,d,q,w[kM];
bool vis[kV];
u64 dis[kN][kN],cdis[kV];
vector<pair<u32,u32>> /*graph[kV],*/out[kM];

//void add_edge(u32 u,u32 v,u32 t){
//    graph[u].emplace_back(v,t);
//    graph[v].emplace_back(u,t);
//}
//struct Node{
//    u64 d;
//    u32 u;
//    friend bool operator<(Node a,Node b){
//        return a.d>b.d;
//    }
//};
//priority_queue<Node> pq;
//void dijkstra(u32 u){
//    fill_n(vis+1,n+m,false);
//    fill_n(cdis+1,n+m,kInf);
//    cdis[u]=0;
//    pq.push({cdis[u],u});
//    while(!pq.empty()){
//        u=pq.top().u;
//        pq.pop();
//        if(!vis[u]){
//            vis[u]=true;
//            for(auto p:graph[u]){
//                u32 v=p.first,t=p.second;
//                if(cdis[u]+t<cdis[v]){
//                    cdis[v]=cdis[u]+t;
//                    pq.push({cdis[v],v});
//                }
//            }
//        }
//    }
//}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    fin>>c>>n>>m>>d>>q;
    FOR(i,1,m){
        fin>>w[i];
    }
    FOR(i,1,n){
        u32 k;
        fin>>k;
        REP(ti,0,k){
            u32 a,t;
            fin>>a>>t;
//            add_edge(i,n+a,t);
            out[a].emplace_back(i,t);
        }
    }
    FOR(i,1,n){
        fill_n(dis[i]+1,n,kInf);
        dis[i][i]=0;
    }
    FOR(i,1,m){
        for(auto p1:out[i]){
            for(auto p2:out[i]){
                ckmin(dis[p1.first][p2.first],p1.second+p2.second);
            }
        }
    }
    FOR(k,1,n){
        FOR(i,1,n){
            FOR(j,1,n){
                ckmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            
        }
    }
    REP(i,0,q){
        u32 x,y;
        fin>>x>>y;
        u64 ans=4e18;
        for(auto p1:out[x]){
            for(auto p2:out[y]){
                ckmin(ans,dis[p1.first][p2.first]+p1.second+p2.second);
            }
        }
        ans+=w[x]+w[y];
        fout<<ans<<"\n";
    }
}
