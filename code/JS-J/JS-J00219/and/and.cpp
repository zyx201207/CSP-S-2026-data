#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = a[1];
    for (int i = 1; i <= m; i++)
    {
        ans = ans & a[i];
    }
    cout << ans << endl;
    return 0;
}
