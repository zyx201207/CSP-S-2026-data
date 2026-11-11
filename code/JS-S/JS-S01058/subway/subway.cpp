#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500003], ti[500003][503];
vector<pair<int, int>>g[500003];
int G[503][503];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++)scanf("%lld", &w[i]);
    for(int i = 1;i <= n;i++){
        int k;scanf("%lld", &k);
        for(int j = 1;j <= k;j++){
            int a, t;scanf("%lld%lld", &a, &t);
            ti[a][i] = t;
            g[a].push_back({i, t});
        }
    }
    memset(G, 0x3f, sizeof(G));
    for(int i = 1;i <= m;i++){
        for(auto line1 : g[i]){
            for(auto line2 : g[i]){
                if(line1.first == line2.first)continue;
                G[line1.first][line2.first] = min(G[line1.first][line2.first], line1.second + line2.second);
                G[line2.first][line1.first] = min(G[line2.first][line1.first], line1.second + line2.second);
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j)G[i][j] = 0;
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    while(q--){
        int x, y;scanf("%lld%lld", &x, &y);
        int ans = 1e18;
        for(auto line1 : g[x]){
            for(auto line2 : g[y]){
                int cur = G[line1.first][line2.first];
                ans = min(ans, cur + ti[x][line1.first] + ti[y][line2.first]);
            }
        }
        printf("%lld\n", ans + w[x] + w[y]);
    }
}
