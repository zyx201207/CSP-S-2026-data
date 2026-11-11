#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int dp[N]={0};

int main() {
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int m,n;
    cin>>n>>m;
    vector<int>a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
    for(int i=1;i<=m;i++) for(int j=n;j>=1;j--) dp[i]=max(dp[i],dp[i-1]&a[i]);
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
