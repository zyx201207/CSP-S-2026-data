#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[n+5];
    for (long long i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    long long k = a[n];
    if (m == 2)
    {
        k = a[n] & a[n-1];
        cout << k;
        return 0;
    }
    for (long long i = n - 1; i >= n - m + 1; i--)
    {
        k = k & a[i];
    }
    cout << a[n] << a[n-1] << endl;
    cout << k;
    //long long n, m;
    //cin >> n >> m;
    //long long a[n+5];
    //for (long long i = 1; i <= n; i++)
    //{
    //     cin >> a[i];
    //}
    //long long b[n*(n-1)/2+5];
    //long long ans = 0;
    //for (kong long i = 1; i <= n - 1; i++)
    //{
    //    for (long long j = i + 1; j <= n; j++)
    //    {
    //        ans++;
    //        b[ans] = a[i] & a[j];
    //    }
    //}
    //long long t = -1;
    //for (long long i = 1; i <= ans; i++)
    //{
    //    t = max(t, b[i]);
    //}
    //cout << t;
    return 0;
}
