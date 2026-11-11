#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[2005][2005],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)dp[i][1]=a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]&a[i],dp[i-1][j]));
        }
    }
    cout<<dp[n][m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
