#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pl pair <int, int>
const int N = 1e4 + 5;
int c, n, m, d, q;
int w[N], a[500][N], t[500][N];
int dis[N][N], diss[N][N], vis;
struct node{
    int to;
    int w;
};
vector <node> g[N];
void dij(int u){
    priority_queue < pl, vector<pl>, greater<pl> > q;
    for(int i = 1;i <= m; i++)
        for(int j = 1;j <= m; j++)
            dis[u][u] = 1e18;
    dis[u][u] = 0;
    q.push({1, 0});
    while(!q.empty()){
        int qq = q.top().first;
        q.pop();
        for(auto it : g[u]){
            int v = it.to;
            int w = it.w;
            if(dis[u][v] > dis[u][qq] + w)
//                dis[u][v] = diss[][(v+1)%m] = dis[u][qq] + w;
                q.push({dis[u][v], v});
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m; i++)
        cin >> w[i];
    for(int i = 1;i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k; j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y];
    }
    return 0;
}
