#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
long long a[N];
long long dp[2][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    dp[0][0]=a[1];
    for(int i=1;i<=n;i++){
        dp[i&1][0]=a[i];
        for(int j=1;j<=m;j++){
            dp[i&1][j]=max(dp[(i-1)&1][j],(dp[(i-1)&1][j-1] & a[i]));
        }
        //for(int j=0;j<=m;j++){
            //cout<<dp[i&1][j]<<" ";
        //}
        //cout<<endl;
    }
    ans=max(dp[1][m],dp[0][m]);
    cout<<ans<<"\n";
    return 0;
}
