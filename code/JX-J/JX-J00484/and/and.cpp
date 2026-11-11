#include<bits/stdc++.h>
using namespace std;
long long a[200010],dp[21010][12010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        dp[i][1]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],a[i]&dp[i-1][j-1]);
        }
    }
    long long maxn=0;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,dp[i][m]);
    }
    cout<<maxn;
    return 0;
}
