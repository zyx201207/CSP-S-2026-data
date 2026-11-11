#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 5e5 + 1000;
int c,m,n,d,q,cnt,a[N],h[N];
bool vis[N];
struct node{int to,next,w;} e[N*40];
struct que{
    int x,d;
    bool operator < (const que &u) const {return u.d < d;}
};
inline int read(){
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
    return x;
}
inline void add(int u,int v,int w){
    e[++cnt] = {v,h[u],w};
    h[u] = cnt;
}
void dijkstra(int s,vector<vector<long long>> &dis){
    memset(vis,0,sizeof(vis));
    priority_queue<que> q;
    q.push({s+n,0}),dis[s][s+n] = 0;
    while(!q.empty()){
        auto [u,_] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u];i;i = e[i].next){
            int v = e[i].to,w = e[i].w;
            if(dis[s][u] + w < dis[s][v]){
                dis[s][v] = dis[s][u] + w;
                q.push({v,dis[s][v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(),m = read(),n = read(),d = read(),q = read();
    vector<vector<long long>> dis(m + 1,vector<long long>(n + m + 1,INF));
    for(int i = 1;i <= n;i++) a[i] = read();
    for(int i = 1;i <= m;i++){
        int sumsta = read();
        for(int j = 1;j <= sumsta;j++){
            int v = read(),w = read();
            add(n + i,v,w),add(v,n + i,w);
        }
    }
    for(int i = 1;i <= m;i++) dijkstra(i,dis);
    while(q--){
        int x = read(),y = read();
        long long ans = LLONG_MAX;
        for(int i = 1;i <= m;i++) ans = min(ans,dis[i][x] + dis[i][y]);
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}
