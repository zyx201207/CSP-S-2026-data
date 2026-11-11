#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

int n, ans, len[maxn];
char c[maxn];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> len[i] >> c[i];
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    if (n == 2)
    {
        if (c[1] == c[2])
        {
            cout << 0;
            return 0;
        }
        cout << min(len[1], len[2]);
        return 0;
    }
    if (2 < n && n <= 10)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= len[i]; j++)
            {
                s += c[i];
            }
        }
        for (int i = 1, j = s.size(); i <= j; i++, j--)
        {
            if (s[i] != s[j])
            {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    if (10 < n && n <= maxn)
    {
        for (int i = 1, j = n; i <= j; i++, j--)
        {
            if (c[i] == c[j])
            {
                int tmp = abs(len[i] - len[j]);
                while (tmp > 0 && i <= j)
                {
                    i++;
                    if (tmp >= len[i])
                    {
                        tmp -= len[i];
                        ans += len[i];
                        len[i] = 0;
                    }
                    else
                    {
                        ans += tmp;
                        len[i] -= tmp;
                    }
                }
            }
            else
            {

                int tmp = max(len[i], len[j]);
                while (tmp > 0 && i <= j)
                {
                    i++;
                    if (tmp >= len[i])
                    {
                        tmp -= len[i];
                        ans += len[i];
                        len[i] = 0;
                    }
                    else
                    {
                        ans += tmp;
                        len[i] -= tmp;
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}