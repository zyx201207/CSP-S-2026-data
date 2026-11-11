#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N], s[N];
int n, m;
int l = 1, r = 1;
int ans = 1;
long long num = 0;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = a[i + 1] - a[i];
    }
    while (num <= m && r <= n)
    {
        ans = r;
        num += (r - l + 1) * s[r];
        r++;
    }
    while (r <= n)
    {
        while (num > m)
        {
            num = num - a[l] + a[r];
            l++;
        }
        ans = max(ans, r - l + 1);
        num += (r - l + 1) * s[r];
        r++;
    }
    cout << ans;
    return 0;
}
