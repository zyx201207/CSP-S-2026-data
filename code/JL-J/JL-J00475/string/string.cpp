

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, len, ans;
string s;
signed main ()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        char c;
        cin >> x >> c;
        len +=  x;
        for (int j = 1; j <= x; ++ j)
            s += c;
    }
    s = ' ' + s;
    for (int i = 1; i <= len / 2; ++ i)
    {
        if (s[i] != s[len + 1 - i])
            ++ ans;
    }
    cout << ans;
    return 0;
}

