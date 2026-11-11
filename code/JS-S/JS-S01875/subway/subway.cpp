#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int t[1005][1005];
int w[1005];
int main(){
    int c,n,m,d,q;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = 191981024;
            t[i][j] = 191981024;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        int aij, kij;
        for(int j=1;j<=k;j++){
            cin >> aij >> kij;
            t[i][aij] = kij;
        }
    }
    for(int i=1;i<=m;i++){
        dp[i][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                dp[i][j] = min(dp[i][j], t[k][i] + t[k][j]);
            }
        }
    }
    for(int sb=1;sb<=n-1;sb++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    dp[i][j] = min(dp[i][j], dp[k][i] + dp[k][j]);
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int xr, yr;
        cin >> xr >> yr;
        cout << dp[xr][yr] + w[xr] + w[yr] << "\n";
    }
    return 0;
}
