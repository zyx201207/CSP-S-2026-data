#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 505;
const int M = 5e5 + 5;
const int inf = 1e18;

int dis[N][N];

int w[M];

vector<pair<int , int> > in[M];

bool f[N];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> w[i];
    for(int i = 1;i <= n;i ++) {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++) {
            int a,b;
            cin >> a >> b;
            in[a].push_back(make_pair(i , b));
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            dis[i][j] = inf;
            if(i == j) dis[i][j] = 0;
        }
    }
    for(int i = 1;i <= m;i ++) {
        for(auto u : in[i]) {
            for(auto v : in[i]) {
                dis[u.first][v.first] = dis[v.first][u.first] = min(dis[u.first][v.first] , u.second + v.second);
            }
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            for(int t = 1;t <= n;t ++) {
                dis[i][j] = dis[j][i] = min(dis[i][j] , dis[i][t] + dis[t][j]);
            }
        }
    }
    // for(int i = 1;i <= n;i ++) {
    //     for(int j = 1;j <= n;j ++) {
    //         cout << dis[i][j] << " ";
    //     } cout << "\n";
    // }
    for(int i = 1;i <= q;i ++) {
        int x,y,ans = inf;
        cin >> x >> y;
        for(auto u : in[x]) {
            for(auto v : in[y]) {
                ans = min(ans , dis[u.first][v.first] + u.second + v.second);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}