#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[200005];
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for (long long i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        sort (a + 1 , a + n + 1);
        cout << a[n];
    }
    else if (m == n)
    {
        long long r = a[1];
        for (long long i = 2;i <= n;i++)
        {
            r &= a[i];
        }
        cout << r;
    }
    else if (m == 2)
    {
        long long l = 1;
        long long r = 2;
        long long ans = -1;
        while (r <= n)
        {
            while (l < r)
            {
                long long r;
                r = a[l] & a[r];
                ans = max(ans , r);
                l++;
            }
            r++;
        }
        cout << ans;
    }
    else
    {
        long long ans = -10086;
        for (long long q = 1;q <= n;q++)
        {
            long long r = a[1];
            for (long long i = 1;i <= n;i++)
            {
                if (i != q)
                {
                    r &= a[i];
                    ans = max(ans , r);
                }
            }
        }
        cout << ans;
    }
    return 0;
}


