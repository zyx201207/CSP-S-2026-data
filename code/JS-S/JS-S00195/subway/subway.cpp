#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 503, M = 514514;
int c, n, m,d, q;
int w[M];
struct T{
    int b , w;
};
vector<T> bc[M];
int dis[N][N];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            if(i!=j)dis[i][j] = 1e18;
        }
    }
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++){
        int k,a,t;
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            cin >> a >> t;
            bc[a].push_back({i,t});
        }
    }
    for(int i = 1; i <= m; i++) {
        d = bc[i].size();
        for(int j = 0; j < d; ++j) {
            for(int k = 0; k < d; k++) {
                dis[bc[i][j].b][bc[i][k].b]=min(dis[bc[i][j].b][bc[i][k].b],bc[i][j].w+bc[i][k].w);
            }
        }
    }
    //Floyd

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        int ans = 1e18, tmp = w[x] + w[y];
        int d1 = bc[x].size(), d2 = bc[y].size();
        for(int j = 0; j < d1; j++) {
            for(int k = 0; k < d2; k++) {
                ans = min(ans, bc[x][j].w+bc[y][k].w+dis[bc[x][j].b][bc[y][k].b]);
            }
        }
        cout << ans + tmp << '\n';
    }

    return 0;
}
/*
0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3


*/
