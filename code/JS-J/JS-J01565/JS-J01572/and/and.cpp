#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200100],dp[200100],x;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(dp[1]<a[i]){
            dp[1]=a[i];
            x=i;
        }
    }
    a[x]=0;
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(dp[i]<(dp[i-1]&a[j])){
                x=j;
                dp[i]=dp[i-1]&a[j];
            }
        }
        a[x]=0;
    }
    cout<<dp[m];
    return 0;
}
