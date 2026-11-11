#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int dp[N][N];
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],dp[i][1]=max(dp[i-1][1],a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,m);j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
    //5 3
    //31 3 1 15 7
    //31 15 7;

    return 0;
}
