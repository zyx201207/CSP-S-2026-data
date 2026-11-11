// subway
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
template<typename ...Args> void Debug(const Args&... arg){
    int d[] = {(cerr << arg << ' ',0)...};
    cerr << '\n';
}
#define dbg(...) Debug(#__VA_ARGS__,'=',__VA_ARGS__)
#else
#define dbg(...) void()
#endif // LOCOL
const int N = 505,M = 5e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dis[N][N],W[M];
int len[N];
unordered_map<int,int> g[M];
int main(){
#ifdef LOCAL

#else
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> W[i];
    for (int i = 1;i <= n;i++){
        cin >> len[i];
        for (int j = 1;j <= len[i];j++){
            int v,w;
            cin >> v >> w;
            g[v][i] = w;
        }
    }
    memset(dis,0x3f,sizeof dis);
    for (int i = 1;i <= n;i++) dis[i][i] = 0;
    for (int i = 1;i <= m;i++){
        for (auto p : g[i]){
            for (auto q : g[i]){
                if (p == q) break;
                int u = p.first,v = q.first,w1 = p.second,w2 = q.second;
                dis[u][v] = dis[v][u] = min(dis[u][v],(long long)w1 + w2);
            }
        }
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++) if (dis[i][k] != inf)
            for (int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while (q--){
        int x,y;
        cin >> x >> y;
        long long ans = inf;
        for (auto p : g[x])
            for (auto q : g[y]){
                int u = p.first,v = q.first,w1 = p.second,w2 = q.second;
                ans = min(ans,w1 + dis[u][v] + w2);
            }
        cout << ans + W[x] + W[y] << '\n';
    }
    return 0;
}
