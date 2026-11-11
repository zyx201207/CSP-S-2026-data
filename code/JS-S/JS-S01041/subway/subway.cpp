#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 505, MAXM = 5e5 + 5;
struct Station{
    int t, id;
};
int a[MAXM];
vector<Station> v[MAXM];
long long e[MAXN][MAXN];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(e, 0x3f, sizeof(e));
    int c, n, m, d, q, x, y, z;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        e[i][i] = 0;
        cin >> z;
        for (int j = 1;j <= z;j++){
            cin >> x >> y;
            v[x].push_back({y, i});
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 1;j < v[i].size();j++){
            for (int k = 0;k < j;k++){
                int t1 = v[i][j].id, t2 = v[i][k].id;
                e[t1][t2] = min(e[t1][t2], (long long)v[i][j].t + v[i][k].t);
                e[t2][t1] = e[t1][t2];
            }
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                if (e[i][k] + e[k][j] < e[i][j]){
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }
    for (int k = 1;k <= q;k++){
        cin >> x >> y;
        long long minn = 1e18;
        for (Station tp1 : v[x]){
            for (Station tp2 : v[y]){
                minn = min(minn, tp1.t + tp2.t + e[tp1.id][tp2.id]);
            }
        }
        cout << minn + a[x] + a[y] << '\n';
    }
}
