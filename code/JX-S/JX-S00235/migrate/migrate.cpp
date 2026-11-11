#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
const int N = 3e6 + 10;
ll n , m , sum;
ll a[N];
vector <ll> edge[N];
ll dis[N];
ll num[N];
bool vis[N];
void bfs (int start) {
    memset (dis , 0x3f , sizeof dis);
    memset (num , 0 , sizeof num);
    memset (vis , 0 , sizeof vis);
    priority_queue <pair <ll , ll> , vector <pair <ll , ll> > , greater <pair <ll , ll> > > q;
    dis[start] = 0;
    q.push ({0 , start});
    while (!q.empty ()) {
        pair <ll , ll> f = q.top ();
        q.pop ();
        if (f.first > dis[f.second]) continue;
        ll now = f.second;
        for (auto to : edge[f.second]) {
            if (dis[to] > dis[now] + 1) {
                dis[to] = dis[now] + 1;
                num[to] = 1;
                q.push ({dis[to] , to});
            } else if (dis[to] == dis[now] + 1) {
                num[to] += 1;
                q.push ({dis[to] , to});
            }
        }
    }
    for (int i = start ; i <= n ; i ++ )
        if (num[i] == 2) sum += 1;
}
void solve () {
    sum = 0;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    for (int i = 1 ; i <= n ; i ++ ) {
        for (int j = i + 1 ; j <= n ; j ++ ) {
            if (a[j] - a[i] > m) break;
            edge[i].push_back (j);
        }
    }
    for (int i = 1 ; i <= n ; i ++ ) bfs (i);
    cout << sum << endl;
    for (int i = 1 ; i <= n ; i ++ )
        edge[i].clear ();
}
ll c , t;
int main () {
    IOS
    freopen ("migrate.in" , "r" , stdin);
    freopen ("migrate.out" , "w" , stdout);
    cin >> c >> t;
    while (t -- ) solve ();
    return 0;
}
