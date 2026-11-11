#include <bits/stdc++.h>
using namespace std;
int a[500005], ans[300005];
stack<int> s;
set<int> f;
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, fl = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) fl = 0;
    } 
    if (fl)
    {
        a[n + 1] = INT_MAX;
        for (int i = 2; i <= n + 1; i++)
        {
            if (a[i] > a[i - 1]) cout << i - 1 << " ";
        } 
        return 0;
    } 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (f.count(a[j]))
            {
                while (!s.empty() && s.top() != a[j])
                {
                    f.erase(s.top());
                    s.pop();
                } 
            } 
            else
            {
                f.insert(a[j]);
                s.push(a[j]);
            } 
        } 
        while (!s.empty())
        {
            ans[s.top()]++;
            f.erase(s.top());
            s.pop();
        } 
    } 
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    } 
    return 0;
} 