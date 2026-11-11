#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<char> c(n + 1);
    vector<ll> sum(n + 1);

    ll L = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> c[i];
        L += a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector<char> s(L + 2);
    for (int i = 1; i <= n; ++i)
    {
        s[sum[i - 1] + 1] += c[i];
        s[sum[i] + 1] -= c[i];
    }

    for (int i = 1; i <= L; ++i)
    {
        s[i] += s[i - 1];
    }
    
    // for (int i = 1; i <= L; ++i) cout << s[i];
    // cout << '\n';

    ll ans = 0;

    for (int i = 1; i <= L; ++i)
    {
        if (s[i] != s[L + 1 - i]) ++ans;
    }

    cout << ans / 2 << '\n';

    return 0;
}