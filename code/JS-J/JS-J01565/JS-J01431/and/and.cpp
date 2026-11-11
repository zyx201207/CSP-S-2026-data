#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n,m;
long long a[N],dp[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        dp[i] = a[i];
        for(int j = m;j >= 1;j--){
           dp[j] = max(dp[j],dp[j - 1] & a[i]);
        }
    }
    cout << dp[m];
    return 0;
}
