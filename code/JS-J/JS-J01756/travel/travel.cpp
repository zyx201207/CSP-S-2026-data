#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string k1, k2, b, d;
    cin >> k1 >> b >> k2 >> d;
    int a = (k1[0] - '0') * 10 + (k1[1] - '0');
    int c = (k2[0] - '0') * 10 + (k2[1] - '0');
    int l1 = (b[0] - '0') * 10 + (b[1] - '0');
    int l2 = (d[0] - '0') * 10 + (d[1] - '0');
    bool f1 = false, f2 = false, f3 = false;
    string ans = "";
    if (a == c)
    {
        f1 = true;
        ans += "1";
    }
    else
    {
        ans += "0";
    }
    if (l1 == l2 && f1 == true)
    {
        f2 = true;
        ans += "1";
    }
    else
    {
        ans += "0";
    }
    if (((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F')) && f2)
    {
        f3 = true;
        ans += "1";
    }
    else
    {
        ans += "0";
    }
    if (abs(b[2] - d[2]) == 1 && f3)
    {
        ans += "1";
    }
    else
    {
        ans += "0";
    }
    cout << ans << endl;
    return 0;
}
