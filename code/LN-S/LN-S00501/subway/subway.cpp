#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10;
const int maxn = 510;
int c , n , m , d , q;
long long w[maxn];

struct edge{
    int a ;
    long long t;
    edge(int a=0,long long t=0):a(a),t(t){}
};
vector<edge> adj[maxn];
long long ans = 0;

long long dis[maxn];
bool vis[maxn];

int fa[maxn];
long long dfs(int u , int x , long long w){
    if(fa[u] == x) return 0;
    w += adj[fa[u]][0].t;
    dfs(fa[u] , x , w);
    return w;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i = 1 ; i <= m ; i++) scanf("%ld",&w[i]);
    for(int i = 1 ; i <= n ; i++){
        int k; scanf("%d",&k);
        for(int j = 1 ; j <= k ;j++){
            int a ; long long t; scanf("%d %ld",&a,&t);
            adj[i].push_back(edge(a,t));
        }
    }
    for(int i = 1 ; i <= q ; i++){
        int x , y; scanf("%d %d",&x,&y);
        for(int z = 1 ; z <= maxn ; z++) dis[z] = 1e18;
        memset(vis , false , sizeof(vis));
        memset(fa , 0 , sizeof(fa));
        ans = 0;

        ans += w[x] + w[y];

        priority_queue<pair<long long ,int> > q;
        dis[x] = 0; fa[x] = x;
        q.push({0,x});
        while(!q.empty()){
            int u = q.top().second; q.pop();

            if(vis[u]) continue;
            vis[u] = true;

            for(int j = 1 ; j < adj[u].size() ; j++){
                int v = adj[u][j].a , w = adj[u][j].t;
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    fa[v] = u;
                }
                q.push({-dis[v],v});
            }
        }
        ans += dfs(y , x , 0);

        printf("%ld\n",ans + dis[y] + adj[x][0].t);
    }

    return 0;
}


