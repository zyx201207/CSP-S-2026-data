#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],d[500005],last = 1;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }sort(a + 1,a + n + 1);
    for(int i = 2;i <= n;i++){
        d[i] = a[i] - a[i - 1];
    }int ans = 1,sum = 0;
    for(int i = 2;i <= n;i++){
        sum += (i - last) * d[i - 1];
        if(sum > m){
            while(sum > m){
                sum -= a[i] - a[last];
                last++;
            }
        }else{
            while(sum <= m && last > 1){
                last--;
                if(sum + a[i] - a[last] <= m){
                    sum += a[i] - a[last];
                }else{
                    last++;
                    break;
                }
            }
        }ans = max(ans,i - last + 1);
    }cout << ans;
    return 0;
}
