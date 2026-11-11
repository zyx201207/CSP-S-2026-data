#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
int a[N], p[N];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read(), m = read(), maxn = 0;
    for(int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
    {
        int l = 0, r = i;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(a[i] * mid - (p[i] - p[i - mid]) <= m) l = mid + 1;
            else r = mid - 1;
        }
        maxn = max(maxn, l - 1);
    }
    cout << maxn << endl;
    return 0;
}
/*
lg uid:846327
hui yin ma*/
