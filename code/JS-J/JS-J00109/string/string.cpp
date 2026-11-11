#include<bits/stdc++.h>
using namespace std;
int a[200005],n,dp[200000005],cnt;
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i =1;i <= n;i++){
        cin >> a[i] >> b[i];
        cnt += a[i];
    }
    int t = ceil(n /2.0);
    int he = t * 2;
    for(int i = 1;i <= n;i++){
        for(int j = cnt;j >= a[i];j--){
            if (b[i] != b[he + 1 - i]){
                dp[j] = max(dp[j],dp[j - a[i]] + a[i]);
            }
            else{
                dp[j] = 0;
            }
        }
    }
    cout << dp[n];
    return 0;
}
