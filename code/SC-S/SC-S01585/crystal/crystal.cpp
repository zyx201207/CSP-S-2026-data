#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,ans,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    for(int i = 1,j = 1,cnt = 0;i <= n;i++){
        cnt += (i - j) * (a[i] - a[i-1]);
        while(j < i && cnt > m) cnt -= a[i] - a[j++];
        ans = max(ans,i - j + 1);
    }
    cout << ans;
    return 0;
}
