#include<fstream>
#include<queue>
#include<vector>
std::ifstream fin("subway.in");
std::ofstream fout("subway.out");
const int maxn=505;
const int maxm=1005;
const long long INF=0x3f3f3f3f3f3f3f3f;
using pli=std::pair<long long,int>;
std::vector<pli> g[maxm];
int w[maxn];
int t[maxn][maxm];
long long dist[maxm][maxm];
bool vis[maxm][maxm];
int c,n,m,d,q;
void dijkstra(int x,int N){
    for(int i=1;i<=m;i++){
        dist[N][i]=INF;
        vis[N][i]=false;
    }
    std::priority_queue<pli,std::vector<pli>,std::greater<pli>> q;
    q.push({0,x});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[N][u])
            continue;
        vis[N][u]=true;
        for(auto Edge:g[u]){
            int v=Edge.second;
            int w=Edge.first;
            if(dist[N][v]>dist[N][u]+w){
                dist[N][v]=dist[N][u]+w;
                q.push({dist[N][v],v});
            }
        }
    }
}
int main(){
    fin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        fin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        fin>>k;
        int a[k+1];
        for(int j=1;j<=k;j++)
            fin>>a[j]>>t[i][a[j]];
        for(int j=1;j<=k;j++)
            for(int u=j+1;u<=k;u++){
                g[j].push_back({t[i][a[u]]+t[i][a[j]],u});
                g[u].push_back({t[i][a[u]]+t[i][a[j]],j});
            }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        fin>>x>>y;
        dijkstra(x,i);
        fout<<dist[i][y]+w[x]+w[y]<<'\n';
    }
}
