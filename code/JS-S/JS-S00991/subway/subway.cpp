#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,nx,x,y,d,ans;
long long w[500005];
vector<pair<long long,long long>>a[500005];
long long dp[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    memset(dp,0x3f,sizeof(dp));
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> nx;
        for (int j = 1;j <= nx;j++){
            cin >> x >> y;
            a[x].push_back({i,y});
        }
    }
    for (int i = 1;i <= n;i++)
        dp[i][i] = 0;
    for (int i = 1;i <= m;i++){
            //cout << a[i].size();
        for (int j = 0;j < a[i].size();j++){
            for (int k = 0;k < a[i].size();k++){
                dp[a[i][j].first][a[i][k].first] =
                min(dp[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
            }
        }
    }
    for (int k = 1;k <= n;k++){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= n;j++)
                if (dp[i][k] != dp[0][0] && dp[k][j] != dp[0][0])
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    /*for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }//*/
    for (int i = 1;i <= q;i++){
        cin >> x >> y;
        ans = 1e18;
        for (int j = 0;j < a[x].size();j++){
            for (int k = 0;k < a[y].size();k++)
                ans = min(ans,
                dp[a[x][j].first][a[y][k].first]
                +a[x][j].second+a[y][k].second);
        }
        ans += w[x]+w[y];
        cout << ans << '\n';
    }
    return 0;
}
