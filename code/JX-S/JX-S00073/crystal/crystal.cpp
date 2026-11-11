#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;

int n;
ll m;
ll a[MAXN];
ll last_cnt = 0;
ll l_cnt = 0;
bool check(ll mid)
{
    l_cnt = 0;
    ll m_left = 0;

    for (int i = mid; i >= 1; --i)
    {
        if (m_left + a[mid] - a[i] > m)
        {
            break;
        }
        m_left += a[mid] - a[i];
        l_cnt++;
    }
    ll tmp = last_cnt;
    last_cnt = l_cnt;
    return tmp < l_cnt;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    ll l = 1, r = n, mid;

    ll ans1 = -1;

    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans1 = max(ans1, max(l_cnt, last_cnt));
            l = mid + 1;
        }
        else
        {
            ans1 = max(ans1, max(l_cnt, last_cnt));
            r = mid - 1;
        }
    }

    cout << ans1;

    return 0;
}
