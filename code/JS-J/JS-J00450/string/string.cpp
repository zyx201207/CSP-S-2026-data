#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n, l = 0, ans = 0;
    cin >> n;
    vector <char> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        l += x;
        for (int i = 1; i <= x; i++) a.push_back(y);
    }
    for (int i = 0; i < l / 2; i++) if (a[i] != a[l - i - 1]) ans++;
    cout << ans << endl;
    return 0;
}
