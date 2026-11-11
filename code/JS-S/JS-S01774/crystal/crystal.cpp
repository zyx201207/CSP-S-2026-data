#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
long long ans, n, m;
long long calc (long long x)
{
    long long l = x, sum = m, cnt = 0;
    while (sum >= 0 && l > 0)
    {
        if (a[x] - a[l] <= sum)
        {
            cnt++;
            sum -= (a[x] - a[l]);
            l--;
        }
        else
        {
            break;
        }
    }
    return cnt;
}
int main()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    long long l = 1, r = n;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long k = calc (mid);
        if (k > ans)
        {
            ans = k;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
