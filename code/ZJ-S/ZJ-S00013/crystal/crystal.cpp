#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 500010;

int n;
LL m;
LL a[N], s[N];

bool check(int x)
{
    for (int l = 1, r = x; r <= n; l ++ , r ++ )
    {
        LL t = a[r] * x - (s[r] - s[l - 1]);
        if (t <= m) return true;
    }
    return false;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << "\n";

    return 0;
}
