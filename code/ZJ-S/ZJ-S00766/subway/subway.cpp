#include<bits/stdc++.h>

using i64 = long long;
using pi64 = std:: pair<long long, long long>;
constexpr i64 MAXN = 500;
constexpr i64 MAXM = 500000;
constexpr i64 INF = LLONG_MAX >> 2;

i64 C, N, M, D, Q, W[1 + MAXM];

i64 nxt[1 + MAXN][1 + MAXN], f[2][1 + MAXN][1 + MAXN], nw = 0, wl = 1;

std:: vector<pi64> rem[1 + MAXM];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std:: ios:: sync_with_stdio(false);
    std:: cin.tie(nullptr);
    std:: cin >> C >> N >> M >> D >> Q;
    for (int i = 1 ; i <= M ; i++){
        std:: cin >> W[i];
    }
    for (int i = 1, k ; i <= N ; i++){
        std:: cin >> k;
        for (i64 j = 1, a, b ; j <= k ; j++){
            std:: cin >> a >> b;
            rem[a].emplace_back(i, b);
        }
    }
    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= N ; j++){
            if (i == j) nxt[i][j] = 0;
            else nxt[i][j] = INF;
        }
    }
    for (int i = 1 ; i <= M ; i++){
        for (pi64 p1: rem[i]){
            for (pi64 p2: rem[i]){
                i64 x1 = p1.first, y1 = p1.second;
                i64 x2 = p2.first, y2 = p2.second;
                nxt[x1][x2] = nxt[x2][x1] = std:: min(nxt[x1][x2], y1 + y2);
            }
        }
    }
    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= N ; j++){
            f[nw][i][j] = f[wl][i][j] = nxt[i][j];
        }
    }
    for (int i = 1 ; i <= N ; i++){
        for (int j = 1 ; j <= N ; j++){
            for (int k = 1 ; k <= N ; k++){
                f[wl][k][j] = std:: min(f[wl][k][j], (f[nw][j][i] + f[nw][i][k]));
            }
        }
        std:: swap(wl, nw);
    }
    for (int i = 1, nx, ny ; i <= Q ; i++){
        std:: cin >> nx >> ny;
        i64 ans = INF;
        for (pi64 p1: rem[nx]){
            for (pi64 p2: rem[ny]){
                ans = std:: min(ans, p1.second + p2.second + f[nw][p1.first][p2.first] + W[nx] + W[ny]);
            }
        }
        std:: cout << ans << '\n';
    }
    return 0;
}