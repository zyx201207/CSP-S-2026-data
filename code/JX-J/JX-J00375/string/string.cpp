#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
ll a[2 * N];
char c[2 * N];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> c[i];
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += a[i];
    ll ans = 0;
    int h = 1;
    int w = n;
    int i = n / 2;
    if (n % 2 == 1)
        i ++;
    while (true)
    {
        if (a[h] == sum || a[w] == sum)
            break;
        if (h >= i && w <= i)
            break;
        if (c[h] != c[w])
        {
            ans += min(a[h], a[w]);
        }
        if (a[h] == a[w])
        {
            sum -= a[h];
            sum -= a[w];
            h ++;
            w --;
        }
        else if (a[h] < a[w])
        {
            sum -= 2 * a[h];
            a[w] -= a[h];
            h ++;
        }
        else
        {
            sum -= 2 * a[w];
            a[h] -= a[w];
            w --;
        }
    }
    cout << ans;
    return 0;
}
