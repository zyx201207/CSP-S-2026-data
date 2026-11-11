#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long dp[200010][25];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    if(m==1){
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else if(n<=2000 && m==2){
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else{
        for(int i=1;i<=n;i++){
            for(int k=i-1;k>=1;k--){
                for(int j=2;j<=min(i,m);j++){
                    dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i][m]);
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
