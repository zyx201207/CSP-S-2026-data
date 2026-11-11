#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505,M=5e5+10;
vector<pair<int,int>> to[N];
int c,n,m,d,q,www[N],k,a,t,dis[N][N],asu,asv;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> www[i];
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++) {
            cin >> a >> t;
            for(auto pl : to[a]) {
                dis[i][pl.first] = dis[pl.first][i] = pl.second+t;
                cerr << i << " " << pl.first << " " << pl.second+t <<endl;
            }
            to[a].push_back({i,t});
        }
    }
    for(int k = 1;k <= n;k++){
        for(int u = 1;u <= n;u++){
            for(int v = 1;v <= n;v++){
                dis[u][v] = min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> asu >> asv;
        int ans =  1e18 ;
        for(auto aaa : to[asu]){
            for(auto bbb : to[asv]){
                ans = min(ans,www[asu]+www[asv]+dis[aaa.first][bbb.first]+aaa.second+bbb.second);
                cerr << aaa.first << " " << bbb.first << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
