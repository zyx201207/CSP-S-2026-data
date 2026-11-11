#include <bits/stdc++.h>
using namespace std;

int n, l = 1, r;
long long ans;

struct Node
{
    int a;
    char c;
}s[200010];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    r = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].a >> s[i].c;
    }
    while (l < r)
    {
        if (s[l].a == s[r].a)
        {
            if (s[l].c != s[r].c) ans += s[l].a;
            l++, r--;
        }
        else
        {
            if (s[r].a > s[l].a)
            {
                if (s[r].c == s[l].c)
                {
                    s[r].a -= s[l].a;
                    l++;
                }
                else
                {
                    ans += s[l].a;
                    s[r].a -= s[l].a;
                    l++;
                }
            }
            else
            {
                if (s[r].c == s[l].c)
                {
                    s[l].a -= s[r].a;
                    r--;
                }
                else
                {
                    ans += s[r].a;
                    s[l].a -= s[r].a;
                    r--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
