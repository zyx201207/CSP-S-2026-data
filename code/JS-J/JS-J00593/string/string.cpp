#include <bits/stdc++.h>
using namespace std;

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s = "";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++) s += c;
    }
    int ans = 0;
    if (s.size() % 2)
    {
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - i - 1]) ans++;
        }
    }
    else
    {
        int len = s.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - i - 1]) ans++;
        }
    }
    cout << ans;
    return 0;
}
