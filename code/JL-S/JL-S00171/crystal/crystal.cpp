#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , m , a[500010] , sum[500010];
bool check(int mid)
{
    int mn = 9e18;
    for(int i = mid ; i <= n ; i ++)
    {
        int all = mid * a[i];
        int S = sum[i] - sum[i - mid];
        mn = min(mn , all - S);
    }
    return mn <= m;
}
signed main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    scanf("%lld%lld" , &n , &m);
    for(int i = 1 ; i <= n ; i ++) scanf("%lld" , &a[i]);
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; i ++) sum[i] = sum[i - 1] + a[i];
    int L = 0 , R = n , ans = 0;
    while(L <= R)
    {
        int mid = (L + R) >> 1;
        if(check(mid)) L = mid + 1 , ans = mid;
        else R = mid - 1;
    }
    printf("%lld" , ans);
    return 0;
}
//238
// 100pts