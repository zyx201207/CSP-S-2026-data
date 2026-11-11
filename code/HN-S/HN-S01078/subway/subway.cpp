#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500005],dis[505][505];
vector<pair<int,int> > v[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1,k,x,y; i <= n; i++){
        fill(dis[i] + 1,dis[i] + n + 1,1e18);
        dis[i][i] = 0;
        for (cin >> k; k--; ){
            cin >> x >> y;
            v[x].push_back({i,y});
        }
    }
    for (int i = 1; i <= m; i++) for (int j = 0; j < v[i].size(); j++) for (int k = j + 1; k < v[i].size(); k++) dis[v[i][j].first][v[i][k].first] = dis[v[i][k].first][v[i][j].first] = min(dis[v[i][j].first][v[i][k].first],v[i][j].second + v[i][k].second);
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[k][j]);
    for (int x,y; q--; ){
        cin >> x >> y;
        int ans = 1e18;
        for (int i = 0; i < v[x].size(); i++) for (int j = 0; j < v[y].size(); j++) ans = min(ans,a[x] + a[y] + v[x][i].second + v[y][j].second + dis[v[x][i].first][v[y][j].first]);
        cout << ans << '\n';
    }
    return 0;
}//简单题，比 road 简单