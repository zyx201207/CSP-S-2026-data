#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], s[505][505], t[505][500005];
vector<pair<int, int>>g[500005];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j)s[i][j]=1e9+1;
        }
    }
    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        for(int j=1; j<=k; j++){
            int x, y;
            cin >> x >> y;
            g[x].push_back({i, y});
            t[i][x]=y+w[x];
        }
    }
    for(int i=1; i<=m; i++){
        for(auto u:g[i]){
            for(auto v:g[i]){
                if(u.first!=v.first){
                    s[u.first][v.first]=min(s[u.first][v.first], u.second+v.second);
                }
            }
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                s[i][j]=min(s[i][j], s[i][k]+s[k][j]);
            }
        }
    }
    for(int i=1; i<=q; i++){
        int x, y, ans=1e9+3;
        cin >> x >> y;
        for(auto u:g[x]){
            for(auto v:g[y]){
                ans=min(ans, s[u.first][v.first]+u.second+v.second);
            }
        }
        ans+=(w[x]+w[y]);
        cout << ans << endl;
    }
    return 0;
}