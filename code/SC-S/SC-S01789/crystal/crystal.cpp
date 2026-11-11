#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
long long a [N], sum [N];
int n;
long long m;

bool check (int len)
{
    long long ans = 9e18;
    for (int i = len; i <= n; i++)
    {
        ans = min (ans, len * a [i] - (sum [i] - sum [i - len]));
    }
    return ans <= m;
}

int main ()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    scanf ("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%lld", a + i);
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum [i] = sum [i - 1] + a [i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check (mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf ("%d\n", l);
    return 0;
}