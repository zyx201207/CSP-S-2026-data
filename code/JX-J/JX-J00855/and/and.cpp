#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int dp[10005][10005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int x=1;x<i;i++){
                dp[i][j]=max(dp[i][j],dp[i-x][j-1]&a[i]);
            }
            if(j+1<m){
                dp[i][j]=max(dp[i][j],(dp[i-1][j])&(a[i]));
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}
