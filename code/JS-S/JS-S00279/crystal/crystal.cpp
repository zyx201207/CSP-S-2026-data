#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
ll a[N], s[N], n, m;

bool check(ll mid)
{
    for (ll i = mid; i <= n; i++)
    {
        if (1ll * a[i] * mid - (s[i] - s[i - mid]) <= m)
            return true;
    }
    return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    ll lft = 0, rgh = n + 1;
    while (lft + 1 < rgh)
    {
        ll mid = (lft + rgh) >> 1;
        if (check(mid) == true) lft = mid;
        else rgh = mid;
    }
    cout << lft << '\n';
    return 0;
}
/*
5 5
1 2 4 8 9*/
