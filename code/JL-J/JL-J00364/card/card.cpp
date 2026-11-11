#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int dp[100005];
    dp[0]=1;dp[1]=2;dp[2]=7;dp[3]=9;
    for(int i=4;i<=n;i++){
        dp[i]=dp[0]+dp[1]+dp[2]+dp[3]+dp[i];
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
