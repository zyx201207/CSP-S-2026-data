#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], ans[N], last[N];
bool vis[N], flag1;
stack<int> st;

void solve(int x)
{
    for (int i = x; i <= n; i++) ans[a[i]]++, i = last[a[i]];
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], flag1 = (a[i] >= a[i - 1] ? flag1 : 0), last[a[i]] = i;
    if (flag1)
    {
        for (int i = 1; i <= n; i++) if (a[i] != a[i + 1]) cout << i << " ";
        return 0;
    }
    for (int i = 1; i <= n; i++) solve(i);
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
