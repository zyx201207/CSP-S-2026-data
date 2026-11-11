#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
const ll inf = 1e18;
int c, n, m, d, qq;
ll w[maxn], t[maxn], dis[maxn];
int k, a[maxn];
struct edge{
    int v;
    ll ww;
};
vector <edge> e[maxn];
queue <int> q;
void prim(int s){
    for(int i = 1;i <= m;i++){
        dis[i] = inf;
    }
    dis[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < e[u].size();i++){
            int v = e[u][i].v;
            ll ww = e[u][i].ww;
            if(dis[v] > dis[u] + ww){
                dis[v] = dis[u] + ww;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> qq;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int p = 1;p <= n;p++){
        cin >> k;
        for(int i = 1;i <= k;i++){
            cin >> a[i] >> t[i];
        }
        for(int i = 1;i <= k;i++){
            for(int j = i + 1; j <= k;j++){
                int u = a[i];
                int v = a[j];
                ll ww = t[i] + t[j];
                e[u].push_back({v, ww});
                e[v].push_back({u, ww});
            }
        }
    }
    for(int i = 1;i <= m;i++){
        dis[i] = inf;
    }
    while(qq--){
        int x, y;
        cin >> x >> y;
        prim(x);
        cout << dis[y] + w[x] + w[y] << '\n';
    }
    return 0;
}
