#include <bits/stdc++.h>
using namespace std; bool _M_membg;
int c, n, m, d, q;
int w[500010];
vector<pair<int, int> > lk[500010];
long long ds[510][510];
bool _M_memed; int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    double _M_use_mem = fabs(&_M_membg - &_M_memed) / 1024 / 1024;
    clog << _M_use_mem << "M" << endl;
    assert(_M_use_mem <= 256);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)cin >> w[i];
    for (int i = 1, k; i <= n; ++i){
        cin >> k;
        while (k--){
            int a, l;
            cin >> a >> l;
            lk[a].emplace_back(i, l);
        }
    }
    memset(ds, 0x3f, sizeof(ds));
    for (int i = 1; i <= n; ++i)ds[i][i] = 0;
    for (int i = 1; i <= m; ++i){
        assert(lk[i].size() <= d);
        int K = lk[i].size();
        for (int a = 0; a < K; ++a)
            for (int b = a + 1; b < K; ++b){
                int u = lk[i][a].first; int l1 = lk[i][a].second;
                int v = lk[i][b].first; int l2 = lk[i][b].second;
                ds[v][u] = ds[u][v] = min<long long>(ds[u][v], l1 + l2);
            }
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (ds[i][j] > ds[i][k] + ds[k][j])ds[i][j] = ds[i][k] + ds[k][j];
    while (q--){
        int x, y;
        cin >> x >> y;
        // clog << x << ">" << y << endl;
        long long rs = 1e18;
        for (int i = 0, _ = lk[x].size(); i < _; ++i)
            for (int j = 0, _ = lk[y].size(); j < _; ++j){
                int u = lk[x][i].first; int l1 = lk[x][i].second;
                int v = lk[y][j].first; int l2 = lk[y][j].second;
               // clog << u << "," << v << ":" << w[x] << "+" << l1 << "+" << ds[u][v] << "+" << l2 << "+" << w[y] << endl;
                rs = min(rs, l1 + ds[u][v] + l2);
            }
        cout << rs + w[x] + w[y] << "\n";
    }
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -static -pedantic
./subway <subway1.in >subway.out
diff subway.out subway1.ans -w
./subway <subway2.in >subway.out
diff subway.out subway2.ans -w
./subway <subway3.in >subway.out
diff subway.out subway3.ans -w
./subway <subway4.in >subway.out
diff subway.out subway4.ans -w
./subway <subway5.in >subway.out
diff subway.out subway5.ans -w
./subway <subway6.in >subway.out
diff subway.out subway6.ans -w
./subway <subway7.in >subway.out
diff subway.out subway7.ans -w
*/