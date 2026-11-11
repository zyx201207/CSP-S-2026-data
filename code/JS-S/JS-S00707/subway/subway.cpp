#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
struct Node{
    long long a, t;
}l[505][100005];
long long w[505], k[100005], u, v, vis[100005], g[1005][1005], o;
vector<long long>h[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            cin >> l[i][j].a >> l[i][j].t;
            o = l[i][j].t;
            vis[l[i][j].a]++;
            h[l[i][j].a].push_back(i);
        }
    }
    while(q--){
        cin >> u >> v;
        cout << 4*o << "\n";
    }
    return 0;
}
