#include<bits/stdc++.h>
using namespace std;
const int R = 200010;
int dp[R],a[R];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    dp[0] = 2147483647;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 1;j--){
            dp[j] = max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
