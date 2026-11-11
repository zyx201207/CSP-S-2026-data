#include<bits/stdc++.h>
using namespace std;
long long dp[200005],n,m,a[200005];
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a+1,a+1+n);
    dp[1]=a[1];
    for(long long i = 2 ; i <= n ; i++){
        for(int j = min(m,i) ; j >= 2 ; j--){
            dp[j]=max((dp[j-1]&a[i]),dp[j]);
        }
        dp[1]=max(dp[1],a[i]);
    }
    cout << dp[m];
    fclose(stdin);
    fclose(stdout);

    return 0;
}
