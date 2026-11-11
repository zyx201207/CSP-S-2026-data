// 一定要过这道题啊！--14:53
// 这么喜欢地铁。。 --15:00
// !!!!winwinwin!!!\o/\o/\o/\o/???

// 15:55 Done.
// CCF/qiang/qiang

// 大样例都过了，还有必要检查吗（

// 不知道该检查啥，现在也没时间写对拍了

// 目前也读不出来会有什么坑

// 你说我总不会把最短路写错了吧

// 话说这题 n^3 + q*d^2 能过吗

#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 505, M = 500005; 
// 这英语写给自己看的，别喷我
int c;  // point id
int n;  // line count
int m;  // station count
int d;  // max line count in a station
int q;  // query count
int w[M]; // time 1  // !!!wm???
int k[N]; // station count of line i
vector<int> a[N]; // station list of line i
vector<int> t[N]; // time of line i platform to station a[i][j]
//------------------------------------------------------------//
int dis[N][N]; // time of line i to line j
struct LineInfo {
    int id;  // line id
    int rk;  // station's rank in line id
} ;
vector<LineInfo> line_list[M]; // station i 's line list
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            dis[i][j] = dis[j][i] = 1e17;
        }
    }
    for(int i = 1; i <= n; i ++) {
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j ++) {
            int aa, tt;
            cin >> aa >> tt;
            line_list[aa].push_back({i, j});
            a[i].push_back(aa);
            t[i].push_back(tt);
        }
    }

    for(int i = 1; i <= m; i ++) {
        int line_count = line_list[i].size();
        for(int x = 0; x < line_count; x ++) {
            for(int y = x + 1; y < line_count; y ++) {
                int idx = line_list[i][x].id;
                int idy = line_list[i][y].id;
                int rkx = line_list[i][x].rk;
                int rky = line_list[i][y].rk;
                if(t[idx][rkx] + t[idy][rky] < dis[idx][idy]) {
                    dis[idy][idx] = dis[idx][idy] = t[idx][rkx] + t[idy][rky];
                }
            }
        }
    }

    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(int i = 1; i <= q; i ++) {
        int x, y;
        cin >> x >> y;
        int line_count_x = line_list[x].size();
        int line_count_y = line_list[y].size();
        int ans = 1e17;
        for(int i = 0; i < line_count_x; i ++) {
            for(int j = 0; j < line_count_y; j ++) {
                int idx = line_list[x][i].id;
                int idy = line_list[y][j].id;
                int rkx = line_list[x][i].rk;
                int rky = line_list[y][j].rk;
                int res = dis[idx][idy] + t[idx][rkx] + t[idy][rky];
                ans = min(ans, res);
            }
        }
        ans += w[x] + w[y];
        cout << ans << "\n";
    }
    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
    return 0;
}