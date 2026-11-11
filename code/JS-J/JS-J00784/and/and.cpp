#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long a[N],pre[N],dp[N];
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    if(n == 1){
        cout<<a[n];
        return 0;
    }
    if(m == 1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    pre[1] = a[1];
    for(int i = 2;i<=n;i++) pre[i] = pre[i-1]&a[i];
    dp[1] = a[1];
    for(int i = 2;i<=n;i++){
        for(int j = min(i,m);j>=1;j--){
            dp[j] = max(dp[j],pre[j-1]&a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
