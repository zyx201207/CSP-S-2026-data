#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
bool tsa = true;
long long ans[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i - 1] > a[i]) tsa = false;
    }
    if (tsa)
    {
        for (int i = n; i >= 1; i--)
        {
            if (a[i + 1] != a[i]) ans[a[i]] += i;
        }
        for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> cnt(n + 5);
        vector<int> dsk;
        dsk.reserve(m + 5);
        for (int j = i; j <= n; j++)
        {
            dsk.push_back(a[j]);
            cnt[a[j]]++;
            if (cnt[a[j]] == 2)
            {
                dsk.pop_back();
                cnt[a[j]]--;
                while (dsk.back() != a[j])
                {
                    cnt[dsk.back()]--;
                    dsk.pop_back();
                }
            }
        }
        for (int j : dsk)
        {
            ans[j]++;
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
