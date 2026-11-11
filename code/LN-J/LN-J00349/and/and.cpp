#include<bits/stdc++.h>
using namespace std;
const int po=2e5+5;
int a[200005],dp[20005][20005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            for(int gs=2;gs<=i;gs++){
                dp[i][gs]=max(dp[i][gs],dp[j][gs-1]&a[i]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
