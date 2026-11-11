#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[20005][20005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==n){
        long long ans;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1)
                ans=a[i];
            else{
                ans=ans&a[i];
            }
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j==1){
                    dp[i][j]=a[i];
                }
                else{
                    for(int k=1;k<i;k++){
                        dp[i][j]=max(dp[i-k][j-1]&a[i],dp[i][j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            ans=max(ans,dp[i][m]);
        }
        cout<<ans;
    }
    return 0;
}
