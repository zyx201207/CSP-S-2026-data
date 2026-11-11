#include<bits/stdc++.h>
using namespace std;
string c;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int a[200005], n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        string x;
        cin >> x;
        for (int j = 1; j <= a[i]; j++)
        {
            c += x;
        }
    }
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] != c[c.length() - i - 1])
        {
            cnt++;
            c[i] = c[c.length() - i - 1];
        }
    }
    cout << cnt;
    return 0;
}
