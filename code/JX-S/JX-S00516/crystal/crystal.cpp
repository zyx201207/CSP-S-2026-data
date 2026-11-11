#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[n+1];
    for (long long i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long ans[n+5];
    for (long long i = 1; i <= n; i++)
    {
        ans[i] = 1;
    }
    for (long long i = n; i >= 2; i--)
    {
        long long k = m;
        for (long long j = 1; j <= i - 1; j++)
        {
            k = k - (a[i] - a[i-j]);
            if (k >= 0)
            {
                ans[n-i+1]++;
            }
            else
            {
                break;
            }
        }
    }
    long long t = -1;
    for (long long i = 1; i <= n; i++)
    {
        t = max(t, ans[i]);
    }
    cout << t;
    return 0;
}
