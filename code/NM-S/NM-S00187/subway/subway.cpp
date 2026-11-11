// 3/7 24~32pts
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
int c, n, m, d, Q;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
struct qw
{
    int to, ne, w;
}ls[2000010];
int head[1000010], idx = 1;
int w[500010], dis[500010], vis[500010];
void add(int u, int v, int w){
    ls[idx] = {v, head[u], w};
    head[u] = idx;
    idx++;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++)
        cin >> w[i];
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        int lst = 0;
        while(k--){
            int a, t;
            cin >> a >> t;
            add(a, m + cnt, t);
            add(m + cnt, a, t);
            if(lst != 0){
                add(m + cnt, lst, 0);
                add(lst, m + cnt, 0);
            }
            lst = m + cnt;
            cnt++;
        }
    }

    while(Q--){
        int U, V;
        cin >> U >> V;
        int ans = w[U] + w[V];
        memset(dis, 0x3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        dis[U] = 0;
        q.push({0, U});
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u])
                continue;
            vis[u] = 1;
            for(int i = head[u]; i; i = ls[i].ne){
                int v = ls[i].to;
                int w = ls[i].w;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        cout << ans + dis[V] << endl;
    }
}