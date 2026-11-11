#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        int mx = -114514;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >>x;
            mx = max(mx, x);
        }
        cout << mx;
    }
    else if (n == m)
    {
        int x, ans;
        cin >> ans;
        for (int i = 2; i <= n; i++)
        {
            cin >>x;
            ans = ans & x;
        }file:

        cout << ans;
    }
    else     if (n-1 == m)
    {
        int x, ans;
        cin >> ans;
        for (int i = 2; i <= n; i++)
        {
            cin >>x;
            ans = ans & x;
        }
        cout << ans;
    }
    for (int i = 1; i <= n; i++)
    {

        cin >> a[i];
    }
    sort(a + 1, a + 1 +n);
    cout<<a[n-m+1];
    return 0;
}
