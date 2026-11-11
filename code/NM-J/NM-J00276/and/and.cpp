#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[200005],dp[200005];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            dp[1]=max(dp[1],a[i]);
        }
        cout<<dp[1];
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                dp[2]=max(dp[2],a[i]&a[j]);
            }
        }
        cout<<dp[2];
    }else if(m==n){
        dp[1]=a[1];
        for(int i=2;i<=n;i++){
            dp[1]&=a[i];
        }
        cout<<dp[1];
    }else if(m==n-1){
        dp[1]=a[2];
        for(int i=3;i<=n;i++){
            dp[1]&=a[i];
        }
        for(int i=2;i<=n;i++){
            dp[2]=a[1];
            for(int j=2;j<=n;j++){
                if(i==j)continue;
                dp[2]&=a[j];
            }
            dp[1]=max(dp[1],dp[2]);
        }
        cout<<dp[1];
    }else{
        sort(a,a+n);
        cout<<a[n-m+1];
    }
    return 0;
}
