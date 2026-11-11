#include <bits/stdc++.h>
using namespace std;
bool func(char s[], int x)
{
    for (int i = 1; i < x; i++)
    {
        if (s[i] != s[x-i])
            return 0;
    }
    return 1;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a;
    char c;
    char s[1000005];
    s[0] = 0;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> c;
        memset(s+x, c, a);
        x += a;
    }
    int ans = 0;
    if (func(s, x))
    {
        cout << 0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for (int i = 1; i < x; i++)
    {
        if (s[i] != s[x-i])
        {
            s[i] = s[x-i];
            ans++;
            if (func(s, x)) break;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
