#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500050],k[500050],dd[550][550][2];
map <long long,long long> mp;
vector <pair <long long,long long> > mt[500050];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++) if (i != j) dd[i][j][0] = 1e16;
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            long long a,t;
            cin >> a >> t;
            mt[a].push_back({i,t});
        }
    }
    for (int i = 1;i <= m;i++){
        for (auto u : mt[i]){
            for (auto v : mt[i]){
                if (u.first == v.first) continue;
                if (dd[u.first][v.first][0] > u.second + v.second){
                    dd[u.first][v.first][0] = u.second + v.second;
                    dd[u.first][v.first][1] = i;
                }
            }
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++){
                if (i == j || i == k || j == k) continue;
                if (dd[i][j][0] > dd[i][k][0] + dd[k][j][0]){
                    dd[i][j][0] = dd[i][k][0] + dd[k][j][0];
                    dd[i][j][1] = k;
                }
            }
        }
    }
    for (int i = 1;i <= q;i++){
        long long a,b,ans = 1e16;
        cin >> a >> b;
        if (a == b){
            cout << "0\n";
            continue;
        }
        for (auto u : mt[a]){
            for (auto v : mt[b]){
                if (a != dd[u.first][v.first][1] && b != dd[u.first][v.first][1]) ans = min(ans,w[a] + w[b] + u.second + v.second + dd[u.first][v.first][0]);
                else{
                    if (a == dd[u.first][v.first][1]) ans = min(ans,w[a] + w[b] + v.second + dd[u.first][v.first][0]);
                    else ans = min(ans,w[a] + w[b] + u.second + dd[u.first][v.first][0]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
