#include <bits/stdc++.h>
using namespace std;
int max_;
int n, m;
vector<int> a;
void dfs(int cur, int x, int res)
{
    if (x >= m)
    {
        max_ = max(max_, res);
        return;
    }
    if (cur >= n)
        return;
    if (!res)
        return;
    if (res & a[cur])
        dfs(cur + 1, x + 1, res & a[cur]);
    dfs(cur + 1, x, res);
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    a.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    if (m <= 20)
        dfs(0, 0, (1 << 30) - 1);
    else
    {
        max_ = (1 << 30) - 1;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < m; i++)
        {
            max_ &= a[i];
        }
    }
    cout << max_;
}