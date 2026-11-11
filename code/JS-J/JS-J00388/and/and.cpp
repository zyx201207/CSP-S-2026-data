#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],dp[200001];
const int IM=2147483647;
int main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    //cout<<m<<'\n';
    memset(dp,IM,sizeof(dp));
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j]=max(dp[j]==IM?-1:(i<=j?0:dp[j]),dp[j-1]&a[i]);
        }
    }
   // for(int i=1;i<=m;i++){
    //    cout<<dp[i]<<'\n';
    //}
    cout<<dp[m];
    return 0;
}
//hooray for LA lakers!
