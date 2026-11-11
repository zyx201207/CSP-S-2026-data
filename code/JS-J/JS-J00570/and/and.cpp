#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN=200010,l=1;
int n,m,a[maxN],dp[maxN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0]=9223372036854775807;
    for(int i=1;i<=n;i++){
        for(int j=min(i,m);j>=max(l,m-(n-i+1));j--) dp[j]=max(dp[j],dp[j-1]&a[i]);
    }
    cout<<dp[m];
    return 0;
}