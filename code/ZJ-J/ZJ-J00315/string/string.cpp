#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 2e5 + 100;

int pre[maxn];
int stpos[maxn];
int a[maxn];
char c[maxn];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    scanf("%lld", &n);

    int sum = 0;

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld %c", &a[i], &c[i]);
        sum += a[i];
        pre[i] = pre[i-1] + a[i];
        stpos[i] = pre[i] - a[i] + 1;
    }

    int l = 1, r = sum;

    int ans = 0;

    while(l < r)
    {
        int L_belong = lower_bound(pre + 1, pre + 1 + n, l) - pre;
        int R_belong = lower_bound(pre + 1, pre + 1 + n, r) - pre;
        if(L_belong == R_belong) break;
        int L_len = pre[L_belong] - l + 1;
        int R_len = r - stpos[R_belong] + 1;

        int mnlen = min(L_len, R_len);
        if(c[L_belong] == c[R_belong])
        {
            l += mnlen, r -= mnlen;
        }
        else
        {
            ans += mnlen;
            l += mnlen, r -= mnlen;
        }
    }

    printf("%lld\n", ans);

    return 0;
}