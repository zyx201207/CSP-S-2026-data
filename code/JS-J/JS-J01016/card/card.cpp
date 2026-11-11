#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> cnt(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        vector<int> c;
        for (int j = i; j <= n; ++j)
        {
            if (c.empty()) c.push_back(a[j]);
            else
            {
                bool f = 0;
                for (int k = 0; k < c.size(); ++k)
                {
                    if (c[k] == a[j])
                    {
                        f = 1;
                        break;
                    }
                }
                if (f == 1)
                {
                    while (c.back() != a[j]) c.pop_back();
                }
                else
                {
                    c.push_back(a[j]);
                }
            }
        }
        for (auto& x : c) ++cnt[x];
    }

    for (int i = 1; i <= m; ++i) cout << cnt[i] << ' ';
    cout << '\n';

    return 0;
}