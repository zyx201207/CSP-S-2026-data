#include <bits/stdc++.h>
using namespace std;
long long n,m,a,dp[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=m;j>=2;j--) dp[j]=max(dp[j],dp[j-1]&a);
        dp[1]=max(dp[1],a);

    }
    cout<<dp[m];
}
