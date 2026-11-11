#include<bits/stdc++.h>
#define int long long
using namespace std;

int c , n , m , d , q;
int w[500005] , f[505][505];
vector<pair<int , int> > g[500005];
signed main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for( int i = 1 ; i <= m ; i++ ) cin >> w[i];
    for( int i = 1 ; i <= n ; i++ ){
        int k;
        cin >> k;
        for( int j = 1 , x , y ; j <= k ; j++ ) cin >> x >> y , g[x].push_back({i , y});
    }
    memset(f , 0x3f , sizeof(f));
    for( int i = 1 ; i <= n ; i++ ) f[i][i] = 0;
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 0 ; j < g[i].size() ; j++ ){
            for( int k = j + 1 ; k < g[i].size() ; k++ ){
                int tmp = g[i][j].first , Tmp = g[i][k].first;
                f[tmp][Tmp] = f[Tmp][tmp] = min( f[tmp][Tmp] , g[i][j].second + g[i][k].second );
            }
        }
    }
    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                f[i][j] = min( f[i][j] , f[i][k] + f[k][j] );
            }
        }
    }
    while(q--){
        int x , y;
        cin >> x >> y;
       // cout << x<< " " <<y << " " << w[x] << " " <<w[y] << "\n";
        int ans1 = w[x] + w[y];
        int ans2 = 1e18;
        for( int i = 0 ; i < g[x].size() ; i++ ){
            for( int j = 0 ; j < g[y].size() ; j++ ){
                int tmp = g[x][i].first , Tmp = g[y][j].first;
                ans2 = min(ans2 , g[x][i].second + g[y][j].second + f[tmp][Tmp]);
            }
        }
        cout << ans1 + ans2 << "\n";
    }
    return 0;
}
