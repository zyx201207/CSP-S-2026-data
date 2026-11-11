#include <bits/stdc++.h>
using namespace std;

long long n, cnt;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long x = 0;
        char c;
        cin >> x >> c;
        for (int j = 1; j <= x; j++)
        {
            s += c;
        }
    }


    for (int i = 0; i <= s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
