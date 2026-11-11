#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[200005],n,m,dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){ cin>>a[i];dp[i]=a[i];}
    if(m==1) {
        sort(dp+1,dp+n+1);
        cout<<dp[n]<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) {
            dp[i]=max(dp[i],dp[i-1]&dp[i]);
    }
    cout<<a[n];
    return 0;
}
