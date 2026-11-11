#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[200010], ans;
char c[200010];
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++)
        {
            s += c[i];
        }
    }
    s = "0" + s;
    for (int i = 1; i <= (s.size()-1) / 2; i++)
    {
        if (s[i] != s[s.size()-1 - i + 1])
            ans++;
    }
    cout << ans;
    return 0;
}
