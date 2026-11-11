#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int a[200005];
int dp[10005][10005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dp[i][1]=max(dp[i-1][1],a[i]);
            for(int j=2;j<=m;j++){
                for(int k=1;k<i;k++){
                    dp[i][j]=max(dp[i][j],max(dp[k][j],dp[k][j-1]&a[i]));
                }
            }
        }
        cout<<dp[n][m];
        return 0;
    }else if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++)ans=max(ans,a[i]);
            cout<<ans;
            return 0;
        }else if(m==2){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
            return 0;
        }else{
            ans=a[1];
            for(int i=2;i<=n;i++)ans=ans&a[i];
            cout<<ans;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
