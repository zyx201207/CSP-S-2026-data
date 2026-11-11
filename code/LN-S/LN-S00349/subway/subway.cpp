#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int m[500000];
int a[500][500000],t[500][500000],k[500];
int x[100000],y[100000];
int dp[500][500] = {0};
void dpdp(){
    for(int i = 0;i < n;i++){
        for (int j = 0;j < k[i]-1;j++){
            for (int k = j+1;k < k[i];k++){
                if (dp[j][k] == 0){
                    dp[j][k] = t[i][j] + t[i][k];
                    dp[k][j] = t[i][j] + t[i][k];
                }
                else if(dp[j][k] > t[i][j] + t[i][k]){
                    dp[j][k] = t[i][j] + t[i][k];
                    dp[k][j] = t[i][j] + t[i][k];
                }
            }
        }
    }
    for (int i = 0;i < n;i++){
        for (int j = i+1;j<n;j++){
            for (int k = 0;k < n;k++){
                if (dp[i][j] > dp[i][k] + dp[k][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                    dp[j][i] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 0;i < m;i++){
        cin >> m[i];
    }
    for (int i = 0;i < n;i ++){
        cin >> k[i];
        for (int j = 0;j < k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 0;i < q;i ++){
        cin >> x[i] >> y[i];
    }
    dpdp();
    for (int i = 0;i < q;i ++){
        cout << dp[x[i]][y[i]] + m[x[i]] + m[y[i]];
    }
    return 0;
}
