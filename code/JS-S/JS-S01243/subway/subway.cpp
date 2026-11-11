#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 505;
const int MAXM = 1e3 + 5;
const int MAXQ = 1e5 + 5;
int c;
int n, m, d, q;
int k[MAXN];
int w[MAXM];

vector<pair<int, int>> G[MAXM];
bool vis[MAXN][MAXN];
ll dis[MAXM][MAXM];

void init(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];//2

        int a1, t1, a2, t2;
        cin >> a1 >> t1 >> a2 >> t2;
        dis[a1][a2] = dis[a2][a1] = t1 + t2;
    }
    return;
}

int main(){
    init();
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] + w[x] + w[y];
    }
    return 0;
}
