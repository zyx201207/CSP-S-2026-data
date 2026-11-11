#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int a[200005];

char c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int l = 1, lenl = a[1], r = n, lenr = a[n];
    while (l <= r)
    {
        if (lenl < lenr)
        {
            if (c[l] != c[r]) ans += lenl;
            lenr -= lenl;
            lenl = a[++l];
        }
        else if (lenl > lenr)
        {
            if (c[l] != c[r]) ans += lenr;
            lenl -= lenr;
            lenr = a[--r];
        }
        else
        {
            if (c[l] != c[r]) ans += lenl;
            lenl = a[++l];
            lenr = a[--r];
        }
    }
    cout << ans;
    return 0;
}
