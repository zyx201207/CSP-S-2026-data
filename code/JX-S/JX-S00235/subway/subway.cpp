#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 1e6 + 10;
const int M = 1e3 + 10;
ll c , n , m , d , q;
ll w[N];
struct node {
    ll a , t;
};
vector <node> b[M];
vector <pair <ll , ll> > edge[N];
ll dis[N];
bool vis[N];
ll dijkstra (int x , int y) {
    memset (dis , 0x3f , sizeof dis);
    memset (vis , 0 , sizeof vis);
    priority_queue <pair <ll , int> , vector <pair <ll , int> > , greater <pair <ll , int> > > q;
    dis[x] = 0;
    q.push ({0 , x});
    while (!q.empty ()) {
        int now = q.top ().second;
        q.pop ();
        if (vis[now]) continue;
        vis[now] = 1;
        for (auto _ : edge[now]) {
            int to = _.second;
            ll val = _.first;
            if (dis[to] > dis[now] + val) {
                dis[to] = dis[now] + val;
                q.push ({dis[to] , to});
            }
        }
    }
    return dis[y];
}
int main () {
    IOS
    freopen ("subway.in" , "r" , stdin);
    freopen ("subway.out" , "w" , stdout);
    cin >> c >> m >> n >> d >> q;
    for (int i = 1 ; i <= n ; i ++ ) cin >> w[i];
    for (int k , i = 1 ; i <= m ; i ++ ) {
        cin >> k;
        for (int a , t , j = 1 ; j <= k ; j ++ ) {
            cin >> a >> t;
            edge[n + i].push_back ({t , a});
            edge[a].push_back ({t , n + i});
        }
    }
    for (int x , y , i = 1 ; i <= q ; i ++ ) {
        cin >> x >> y;
        cout << dijkstra (x , y) + w[x] + w[y] << endl;
    }
    return 0;
}
