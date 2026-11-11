#include <bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],dp[20005][20005];
bool cmp(int a,int b){
return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
if(n==m){
        ans=a[1];
    for(int i=1;i<=n;i++){
        ans&=a[i];
    }
cout<<ans<<" ";
return 0;
}
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++){
    dp[i][1]=a[i];
}
for(int i=2;i<=n;i++){
    for(int j=2;j<=min(i,m);j++){
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        //cout<<dp[i][j]<<" ";
    }
    //cout<<endl;
}
for(int i=2;i<=n;i++){
    ans=max(ans,dp[i][m]);
    //cout<<ans<<" ";
}
cout<<ans<<" ";
    return 0;

}
