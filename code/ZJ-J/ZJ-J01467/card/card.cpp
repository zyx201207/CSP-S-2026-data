#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
vector<int> lst;
vector<int> cnt;
vector<int> ans;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    a.resize(n + 1);
    lst.resize(m + 1, -1);
    cnt.resize(m + 1, 0);
    ans.resize(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int c = 0;
    for (int i = n; i >= 1; i--)
    {
        if (c == m)
            break;
        if (lst[a[i]] == -1)
        {
            lst[a[i]] = i;
            for (int j = i; j <= n;)
            {
                ans[a[j]] += cnt[a[i]];
                j = lst[a[j]] + 1;
            }
            c++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}