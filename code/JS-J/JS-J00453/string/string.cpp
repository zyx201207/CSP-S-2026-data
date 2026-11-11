#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
    }
    ll ans = 0;
    int l = 1, r = n;
    while (1)
    {
        if (l >= r) break;
        if (c[l] != c[r]) ans += min(a[l], a[r]);
        /*if (a[l] == a[r])
        {
            a[l] = 0;
            a[r] = 0;
            l++;
            r--;
        }
        else */if (a[l] > a[r])
        {
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }
        else
        {
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
    }
    cout << ans;
    return 0;
}
