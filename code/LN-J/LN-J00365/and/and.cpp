#include<bits/stdc++.h>
using namespace std;
long long n,m;
int dp[20005][20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        for(long long j=1;j<=m;j++){
            if(i<j){
                dp[i][j]=0;
            }else if(j==1){
                dp[i][j]=max(dp[i-1][j],tmp);
            }else{
                dp[i][j]=max(dp[i-1][j],tmp&dp[i-1][j-1]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
