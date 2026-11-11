#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m,a[N],dp[N],mx,num[N],mxc;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    long long dc = a[2] - a[1],i;
    for(i = 3;i <= n;i ++) {
        if(a[i] - a[i - 1] != dc) {
            break;
        }
    }
    num[0] = 1;
    if(i == n + 1){
        long long ds = 0;
        while(ds * (ds + 1) / 2 * dc <= m){
            ds ++;
        }
        cout << ds;
        return 0;
    }
    long long ans = 1;
    for(long long i = 1;i <= n;i ++){
        long long sum = 0,j;
        for(j = i - 1;j >= 1;j --) {
            if(sum + (a[i] - a[j]) > m){
                break;
            } else {
                sum += (a[i] - a[j]);
            }
        }
        j ++;
        ans = max(ans,i - j + 1);
    }
    cout << ans;
    return 0;
}
