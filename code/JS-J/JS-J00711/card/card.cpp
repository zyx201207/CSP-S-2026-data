#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],dp[300005],ans[300005];
int main () {
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i <= n; i++) {
        memset(dp,0,sizeof(dp));
        for (int j=1; j <= n; j++) {
            if(dp[a[j]]){
                for (int k=1; k <= m; k++) {
                    if(dp[k]<j && dp[k]<=dp[]) {
                        dp[k]==0;
                    }
                }
            }
        }
    }
}
