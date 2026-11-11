#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal1.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<int>a(n+1);
    vector<int>v(n+1);
    vector<int>dp(n+1);
    int ans=INT_MIN;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        cout<<"v[j]:\n";
        for(int j=1;j<=i;j++) {
            v[j]=a[i]-a[j];
            cout<<v[j]<<' ';
        }
        cout<<'\n';
        for(int j=1;j<=m;j++) {
            dp[j]=0;
        }
        cout<<"dp[k]:\n";
        for(int j=0;j<=m;j++) {
            cout<<j<<' ';
        }
        cout<<'\n';
        for(int j=1;j<=i;j++) {
            for(int k=m;k>=v[j];k--) {
                if(max(dp[k],dp[k-v[j]]+1)==3) {
                    cout<<'\n'<<dp[k]<<' '<<dp[k-v[j]]+1<<'\n';
                }
                dp[k]=max(dp[k],dp[k-v[j]]+1);
            }
            for(int k=v[j];k<=m;k++) {
                cout<<dp[k]<<' ';
            }
            cout<<'\n';
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;

}
