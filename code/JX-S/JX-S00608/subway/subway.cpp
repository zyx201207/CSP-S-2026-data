#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a;
    int xian;
};
int c, n, m, d, q;
int w[600005];
int k[505];
int ac[2005][505];
int ak[2005];
vector<Node> v[2005];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
                cin >> ac[j][i] >> ak[ac[j][i]];
        }
    }
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        int ans = 0;
        ans += w[u];
        ans += w[v];
        ans += ak[u];
        ans += ak[v];
        cout << ans;
    }
    return 0;
}
