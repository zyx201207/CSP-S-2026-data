#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    int64_t step = 0, ans = 0;
    for (int64_t i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int64_t j = 1; j < n; ++j)
    {
        step = 0;
        for (int64_t i = j; i < n; ++i)
        {
            step += (i - j + 1) * (a[i] - a[i - 1]);
            if (step > m)
                break;
            ans = max(ans, i - j + 2);
        }
    }
    cout << ans;
    return 0;
}