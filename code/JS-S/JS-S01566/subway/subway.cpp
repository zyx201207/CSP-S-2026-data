#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 9;
const int INF = 1e17 + 9;

int c , n , m , d , q;
int w[N] , dis[509][509];
vector<pair<int , int>> g[N];
signed main()  {
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);  cin.tie(0);
    memset(dis , 0x3f , sizeof dis);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i ++) {
        cin >> w[i];
    }
    for (int i = 1;i <= n;i ++) {
        int k;
        cin >> k;
        for (int j = 1;j <= k;j ++) {
            int a , t;
            cin >> a >> t;
            g[i + m].push_back({a , t});
            g[a].push_back({i + m , t});
        }
        dis[i][i] = 0;
    }

    for (int i = 1;i <= n;i ++) {
        for (pair<int , int> p1 : g[i + m]) {
            int a = p1.first , t1 = p1.second;
            for (pair<int , int> p2 : g[a]) {
                int j = p2.first - m , t2 = p2.second;
                dis[i][j] = min(dis[i][j] , t1 + t2);
            }
        }
    }

    for (int mid = 1;mid <= n;mid ++) {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                dis[i][j] = min(dis[i][j] , dis[i][mid] + dis[mid][j]);
            }
        }
    }

    // for (int i = 1;i <= n;i ++) {
    //     for (int j = 1;j <= n;j ++) {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    while (q--) {
        int x , y;
        cin >> x >> y;

        int res = INF;
        for (pair<int , int> p1 : g[x]) {
            for (pair<int , int> p2 : g[y]) {
                int u = p1.first - m , v = p2.first - m , t1 = p1.second , t2 = p2.second;
                res = min(res , t1 + t2 + dis[u][v]);
            }
        }
        cout << w[x] + w[y] + res << endl;

    }
    return 0;
}