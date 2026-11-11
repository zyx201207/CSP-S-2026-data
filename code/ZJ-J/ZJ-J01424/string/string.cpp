#include<bits/stdc++.h>
using namespace std;

// Oh my god, this programme has made my computer BOOM !!!
//freopen("咕咕嘎嘎", "rw", stdin)
// 哦不不不不不，我怎么连T2都没做出来！！！

unsigned long long n, m, ans, g, a[200005], b[200005];
char c[200005];

char sc(int x)
{
    int u = lower_bound(b + 1, b + n + 1, x) - b;
    return c[u];
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        g = __gcd(g, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        m += a[i] / g;
        b[i] = b[i - 1] + (a[i] / g);
    }
    for(int i = 1; i <= m; i++)
    {
        if(sc(i) != sc(m - i + 1))
        {
            ans++;
        }
    }
    cout << (ans / 2) * g << endl;
    return 0;
}