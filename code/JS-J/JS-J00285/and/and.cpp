#include<bits/stdc++.h>//bu shi ge men zen me dou shi mo ni ti a. ma liang hai zhe me da
using namespace std;

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long>a(n+5);//wei le shao xie bian jie er xie 1-based de xue kao sheng qwq
    vector<vector<long long>>dp(n+5,vector<long long>(m+5));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=0;
        }
        dp[i][m]=(1<<31)-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[i][j]=max(dp[i][j],dp[i-1][j]*(dp[i-1][j]!=2147483647));
            dp[i][j-1]=max((dp[i-1][j]&a[i]),dp[i-1][j-1]);
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][0]*(dp[i][0]!=2147483647)+0ll);
    }
    cout<<ans;
    //aaaaaaa wo zen me wang le O(n)de bei bao dp le aaaaaaaaaaaa
    // cout<<'\n';
    // for(int j=m;j>=0;j--){
    //     for(int i=0;i<=n;i++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }aaaaaaaaaaaaaaaaaaaaaaaaaaa zhong yu ba O(nm)tiao guo qu le hua le zheng zheng 1hour aaaaaaaaaa
    return 0;
}
