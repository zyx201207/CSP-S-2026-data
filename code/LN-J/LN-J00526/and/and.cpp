#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int dp[20000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=a[i];
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(j!=k)
                dp[j]=max(dp[j],dp[j]&dp[k]);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
