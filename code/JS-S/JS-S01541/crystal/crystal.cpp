#include <bits/stdc++.h>
#define int __int128
#define x0 rp
#define x1 Rp
#define y0 rP
#define y1 RP
#define endl '\n'
#define pll pair <int , int>
#define LLMI (int)(-1e18)
#define LLMA (int)(1e18)
using namespace std;

const int N = 5e5 + 5;
int a[N], sum[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    int minn = LLMA;
    for (int i = 1; i <= n; i ++)
    {
        long long x;
        cin >> x;
        a[i] = x;
        minn = min(minn, a[i]);
    }
    if (minn < 0)
    {
//        minn -= 100;
        for (int i = 1; i <= n; i ++) a[i] -= minn;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    int ans = 1, l = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] * (i - l) - (sum[i] - sum[l]) > m)
        {
            ans = max(ans, i - 1 - l);
//            cout << i << ' ' << l << endl;
            int L = l, R = i;
            while (L < R)
            {
                int mid = (L + R) >> 1;
                if (a[i] * (i - mid) - (sum[i] - sum[mid]) <= m) R = mid;
                else L = mid + 1;
            }
            l = L;
//            while (a[i] * (i - l) - (sum[i] - sum[l]) > m) l ++;
        }
    }
    cout << (long long)ans;
    return 0;
}
