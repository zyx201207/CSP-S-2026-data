#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int d,q[200005],n,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>q[i];
        dp[i]=q[i];
    }
    for(int i=1;i<=n;i++)
    for(int j=d;j>=1;j--){
        dp[j]=max(dp[j-1]&q[i],dp[j+1]&q[i]);
    }
    cout<<dp[d];
    return 0;
    }
