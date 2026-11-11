#include <bits/stdc++.h>
using namespace std;
int a, b, er[31], vis[31], ans = 0;
string wj(int n)
{
    string x;
    int i = 30;
    for (; i >= 0; i--)
        if (n >= er[i])
        {
            x.push_back('1');
            n -= er[i];
            vis[i]++;
        }
        else x.push_back('0');
    return x;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> a >> b;
    int n[a];
    er[0] = 1;
    string s[a];
    for (int i = 1; i < 31; i++)
        er[i] = er[i - 1] * 2;
    for (int i = 0; i < a; i++)
        cin >> n[i];
    for (int i = 0; i < a; i++)
        s[i] = wj(n[i]);
    for (int i = 0; i < a; i++)
        if (vis[i] >= b) ans += er[i];
    cout << ans;
    return 0;
}
