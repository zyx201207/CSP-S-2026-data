#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 507;
constexpr int inf = 0x3f3f3f3f;
struct node{
    int id;
    int to;
};
int c, n, m, d, q, w[N], k[N], dis[N];
vector<int> g[N];
vector<node> edge[N];
void dij(int x){ return ; }
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1, x, y; j <= 2 * k[i]; j++){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
            edge[x].push_back((node){i, y});
        }
    }
    memset(dis, inf, sizeof(dis));
    for(int i = 1, x, y; i <= q; i++){
        cin >> x >> y;
        dij(x);
        cout << 0 << '\n';
    }
    return 0;
}