#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], mx, sum[N];
signed main()
{
    freopen("crystal.in","r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i ++)//右端点
    {
        int l = 1, r = i, ans = i;//二分左端点
        while(l <= r)
        {
            int mid = l + r >> 1;
            int res = (i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]);
            if(res <= m) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        mx = max(mx, i - ans + 1);
    }
    printf("%lld\n", mx);
    return 0;
}
//曾许下心愿 等待你 的出现 褪色的秋千 有本书 会纪念
//我循着时间 捡起梦 的照片 童话还没有兑现 却需要说再见