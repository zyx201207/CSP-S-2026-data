#include <bits/stdc++.h>
using namespace std;
const int N = 5*1e5+5;
int c, n, m, d, q, x, y;
int w[N], a[505][1005], t[505][1005], zs[505];
long long ans;
bool flag;
struct gongdian{
    int z, x1, x2;
};
vector<int> kx, cx;
vector<gongdian> gd;
void findch(int i, int j){
    for (int f = 1; f <= m; f++){
        for (int g = 1; g <= f; g++){
            if (a[i][f] == a[j][g])
                gd.push_back({a[i][f], i, j});
        }
    }
    if (gd.empty()) flag = false;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> zs[i];//ixiande-zhanshu
        for (int j = 1; j <= zs[i]; j++)
            cin >> a[i][j] >> t[i][j];
    }
    while (q--){
        cin >> x >> y;
        kx.clear();
        ans = w[x]+w[y];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= zs[i]; j++){
                if (y == a[i][j]) kx.push_back(i);//keyidaodadexian
                if (x == a[i][j]) cx.push_back(i);//chudafashidexian
            }
        }
        for (auto v1 : kx){//find:v1 and v2 de gongzhan
            for (auto v2 : cx){
                findch(v1, v2);//v1xian yu v2xian
            }
        }

        if (flag){
            for (auto i : gd){//i.z, i.x1, i.x2
                ans = max(ans, (long long)w[x]+t[i.x1][x]+t[i.x1][i.z]+t[i.x2][i.z]+t[i.x2][y]+w[y]);
            }
        }
        for (auto i : cx)
            for (auto j : kx)
                if (i == j)
                    ans = max(ans, (long long)w[x]+w[y]+t[i][x]+t[i][y]);
        cout << ans << endl;
    }
    return 0;
}
