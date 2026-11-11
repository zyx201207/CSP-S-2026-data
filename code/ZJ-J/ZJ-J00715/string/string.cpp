#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pre[200005];
pair<int, char> a[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    ll total = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        total += a[i].first;
        pre[i] = pre[i - 1] + a[i].first;
    }

    ll ans = 0;
    ll mid = total / 2;

    ll l = 1, r = n;
    while (l < r)
    {
        bool flag = false;
        if (a[l].second != a[r].second)
        {
            ans += min(a[l].first, a[r].first);
            flag = true;
        }
        if (a[l].first > a[r].first)
        {
            a[l].first -= a[r].first;
            r--;
        }
        else if (a[l].first < a[r].first)
        {
            a[r].first -= a[l].first;
            l++;
        }
        else
        {
            a[l].first = a[r].first = 0;
            l++;
            r--;
        }
    }

    cout << ans;

    return 0;
}
