#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, ans = 0;
    string s = "";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        for (int j = 1; j <= t; j++)
        {
            s += c;
        } 
    } 
    string s1 = s.substr(s.size() / 2);
    reverse(s1.begin(), s1.end());
    for (int i = 0; i < int(s.size() / 2); i++)
    {
        if (s[i] != s1[i]) ans++;
    } 
    cout << ans;
    return 0;
} 