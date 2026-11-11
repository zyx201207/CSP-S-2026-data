#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i ++)
    {
        int num;
        char c;
        cin >> num >> c;
        for (int j = 1; j <= num; j ++) s += c;
    }
    int ans = 0;
    for (int i = 0; i < s.size() / 2; i ++)
    {
        if (s[i] != s[s.size() - 1 - i]) ans ++;
    }
    cout << ans;
    return 0;
}