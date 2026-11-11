#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[1000001];
int dp[1000001];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            dp[i+1]=max(dp[i],dp[i]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
