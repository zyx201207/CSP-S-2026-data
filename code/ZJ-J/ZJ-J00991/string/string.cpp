#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxl = 2e8 + 10;
#define _for(i, n) for (int i = 0; i < n; i++)
char str[maxl];
int rev(int n, int x)
{
    return n - x - 1;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int pos = 0;
    _for(i, n)
    {
        int a;
        char c;
        cin >> a >> c;
        _for(i, a) str[pos++] = c;
    };
    int ans = 0;
    _for(i, pos / 2)
    {
        if (str[i] != str[rev(pos, i)])
            ans++;
    }
    cout << ans << '\n';
}
