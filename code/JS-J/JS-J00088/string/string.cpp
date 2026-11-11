#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);
    int n, sum = 0, ans = 0;
    string s = "";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        char c;
        cin >> num >> c;
        sum += num;
        for (int j = 1; j <= num; j++) s += c;
    }
    for (int i = 0; i < sum; i++)
        if (s[i] != s[sum - i - 1]) ans++;
    cout << ans / 2 << endl;
    return 0;
}
