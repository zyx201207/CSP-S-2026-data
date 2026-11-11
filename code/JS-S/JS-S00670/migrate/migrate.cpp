#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e17;

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c, T;
    cin >> c >> T;
    while(T--){
        int n, b;
        cin >> n >> b;
        vector<int>z(n+5);
        for(int i=1;i<=n;i++){
            cin >> z[i];
        }
        vector <vector<int> >dp(n+5,vector <int>(n+5,inf));
        vector<vector<int> >zx(n+5,vector<int>(n+5,0));
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
        }

        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){
                if(z[j]-z[i]<=b){
                    dp[i][j]=1;
                }
            }

        }

        for(int i=1;i<=n;i++){

            for(int j=i+1;j<=n;j++){

                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }

            }

        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(dp[i][k]+dp[k][j] == dp[i][j]){
                        zx[i][j]++;
                    }
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(zx[i][j]==2){
                    ans++;
                }
            }
        }

        cout << ans << '\n';

    }
    return 0;
}
