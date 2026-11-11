#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int n,m,a[N],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",a + i);
    for (int i = 30;~i;i--){
        int cnt = 0;
        for (int j = 1;j <= n;j++){
            if ((a[j] >> i & 1) && (ans == 0 || ((a[j] & ans) >= ans))) cnt++;
        }
        if (cnt >= m) ans |= (1 << i);
    }
    printf("%lld\n",ans);
    return 0;
}