#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> a;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int k = 0; k <= 29; k++)
        {
            a[{i,k}] = s & 1;
            s >>= 1;
        }
    }
    bool b[n+1];
    memset(b, 1, sizeof b);
    int ans = 0;
    for(int k = 29; k >= 0; k--)
    {
        int num = 0;
        for(int i = 1;i <= n; i++)
            if(a[{i,k}] && b[i])
                num++;
        if(num >= m)
        {
            ans += 1 << k;
            for(int i = 1;i <= n; i++)
                b[i] = a[{i,k}] & b[i];
        }
    }
    cout << ans;
    return 0;
}
