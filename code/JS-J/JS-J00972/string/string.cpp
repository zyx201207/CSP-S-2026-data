#include <bits/stdc++.h>
using namespace std;

long long n, m, ans;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    char c;
    cin >> n;
    string s = "";
    for (long long i = 1; i <= n; i++)
    {
        cin >> m >> c;
        while(m--)
            s += c;
    }
    for (long long i = 0; i <= s.size() / 2; i++)
        if (s[i] != s[s.size() - i - 1])
            ans++;
    cout << ans;
    return 0;
}
