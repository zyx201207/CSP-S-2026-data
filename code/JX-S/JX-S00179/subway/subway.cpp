#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
int c, n, m, d, q;
const int N = 505;
const int M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
vector<pii> ve[M];
void chkmin(ll &a, ll b){
    a = (a > b ? b : a);
}
ll ma[N][N];
ll val[M];
void floyd(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            if(ma[i][k] == INF) continue;
            for(int j = 1;j <= n;j++){
                chkmin(ma[i][j], ma[i][k] + ma[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> val[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        while(k--){
            ll a, w;
            cin >> a >> w;
            ve[a].push_back({i, w});
        }
    }
    memset(ma, 0x3f, sizeof(ma));
    for(int i = 1;i <= m;i++){
        for(int p = 0;p < ve[i].size();p++){
            for(int q = p + 1;q < ve[i].size();q++){
                chkmin(ma[ve[i][p].first][ve[i][q].first], ve[i][p].second + ve[i][q].second);
                chkmin(ma[ve[i][q].first][ve[i][p].first], ve[i][p].second + ve[i][q].second);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        ma[i][i] = 0;
    }
//    for(int i = 1;i <= n;i++){
//        for(int j = 1;j <= n;j++){
//            cout << "ma::" << i << ' ' << j << ' ' << ma[i][j] << '\n';
//        }
//    }
    floyd();
    while(q--){
        int x, y;
        cin >> x >> y;
        ll ans = INF;
        for(pii p1 : ve[x]){
            for(pii p2 : ve[y]){
                chkmin(ans, ma[p1.first][p2.first] + p1.second + p2.second);
            }
        }
        cout << ans + val[x] + val[y] << '\n';
    }
    return 0;
}
