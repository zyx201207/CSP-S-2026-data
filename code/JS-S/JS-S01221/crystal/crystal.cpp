#include <bits/stdc++.h>
#define cyn cin
using namespace std;

const int N = 510000;

long long a[N], s[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cyn.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cyn >> n >> k;
    for (int i = 1; i <= n; i++)
        cyn >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l, r, m, ans, mx = 0;
    long long cu;
    for (int i = 1; i <= n; i++)
    {
        l = 0;
        r = i - 1;
//        cerr << "i: " << i << endl;
        while (l <= r)
        {
            m = l + r >> 1;
            cu = s[i - 1] - s[i - m - 1];
//            cerr << m << " " << cu << endl;
            if (a[i] * m - cu <= k)
                ans = m,
                l = m + 1;
            else
                r = m - 1;
        }
        mx = max(mx, ans);
    }
    cout << mx + 1 << endl;
    return 0;
}