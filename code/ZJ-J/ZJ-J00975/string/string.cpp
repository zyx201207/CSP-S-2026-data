#include <bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, cnt = 0;
    long long ans = 0;
    cin >> n;
    while (n--)
    {
        long long x;
        char y;
        cin >> x >> y;
        if (c[cnt] == y)
        {
            a[cnt] += x;
        }
        else
        {
            a[++cnt] = x;
            c[cnt] = y;
        }
    }
    int l = 1, r = cnt;
    while (l < r)
    {
        if (c[l] != c[r])
        {
            ans += min(a[l], a[r]);
        }
        if (a[l] < a[r])
        {
            a[r] -= a[l];
            l++;
        }
        else if (a[l] > a[r])
        {
            a[l] -= a[r];
            r--;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}
