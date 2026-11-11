#include<bits/stdc++.h>
using namespace std;
long long n,m,qwe,ans;
long long a[200010];
long long dp[20010][2010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qwe=max(qwe,a[i]);
        dp[i][1]=qwe;
    }
    if(m==1){
        cout<<qwe;
        return 0;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(n<=20){
        cout<<a[1];
        for(int i=2;i<=n;i++)
            for(int j=2;j<=i&&j<=m;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
        }
        ans=dp[n][m];
    }
    else {
        sort(a+1,a+n+1);
        ans=a[n-2];
    }
    cout<<ans;
    return 0;
}
