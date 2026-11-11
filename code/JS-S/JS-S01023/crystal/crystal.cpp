#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int n,m,a[N],sum[N],ans;
bool check(int x){
    for (int i = x;i <= n;i++){
        int j = i - x + 1;
        if (a[i] * x - (sum[i] - sum[j - 1]) <= m) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",a + i);
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    int l = 1,r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid,l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n",ans);
    return 0;
}