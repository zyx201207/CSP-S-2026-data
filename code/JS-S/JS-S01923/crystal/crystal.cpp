#include <bits/stdc++.h>

using namespace std;

const long long N = 1e12, N2 = 1e18;
long long a[500005], b[500005], M = N + N2;

bool cmp(long long x, long long y)
{
    return x > y;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = N - x;
    }
    sort(a + 1, a + n + 1, cmp);
    for(long long i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    long long l = 1, r = 1, ans = 0;
    while(l <= r && r <= n)
    {
        long long tmp = b[r] - b[l - 1] - a[r] * (r - l + 1);
        if(tmp <= m)
        {
            ans = max(ans, r - l + 1);
            r++;
        }
        else
        {
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}

//100000000
//110000000
//111100000
//111111110
//111111111
