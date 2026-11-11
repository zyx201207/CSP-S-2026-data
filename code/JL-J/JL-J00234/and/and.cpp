#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[20005][20005],a[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=a[i];
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){

            dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));

        }

    }
    cout<<dp[n][m];
    return 0;
    //今游CCF非专业级软件能力认证，感慨万千，故作此文；
    //T1者，麻烦亦力竭也。
    //T2者，TLE也
    //T3者，没做出来也
    //T4者，？？？
    //此年一等极难也
    //吾必于次年重游故地也！
}
