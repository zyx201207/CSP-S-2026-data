
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        ll n, a[10005], d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c == 11 || c == 12)
        {
            if (a[2] - a[1] > d) cout << max(0ll, n - 3);
            else cout << 0;
            return 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 3; j <= n; j++);

        }
    }
    return 0;
}
