#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d, q, w[500005];
ll f[505][505];
vector<pair<int, int> > edge[500005];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;

    for (int i=1; i<=m; i++) cin>>w[i];
       /*
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        for (int j=1; j<=x; j++) {
            cin>>y>>ty;
            edge[2*y].push_back({y, ty});
            edge[y].push_back({2*y, ty});
        }
    }*/
    while (q--) {
        int x, y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<"\n";
    }
    return 0;
}
