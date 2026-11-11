#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a[200005], sum, ans, cnt;
char c[200005];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    for (int i = 1; cnt < (sum>>1); i++)
    {
        cnt += a[i];
        int x = a[i];
        int y = 0;
        for (int j = n; j >= 1; j--)
        {
            if (y+a[j]<=a[i])
            {
                y += a[j];
                n--;
                if (c[i] == c[j]) x -= a[j];
            }
            else
            {
                int z = a[i]-y;
                a[j] -= z;
                if (c[j] == c[i]) x -= z;
                break;
            }
        }
        ans += x;
    }
    cout << ans;
    return 0;
}
