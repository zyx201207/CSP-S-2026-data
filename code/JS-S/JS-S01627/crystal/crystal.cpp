#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, x, maxn=-1;
    long long a[500005], ans[500005] = {};
    cin >> n >> m;
    x = m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        ans[i] = 1;
    }
    sort(a+1, a+n+1);
    for(int i=2; i<=n; i++)
    {
        for(int j=i-1; j>=1; j--)
        {
            if(a[i] - a[j] <= x)
            {
                x -= a[i] - a[j];
                ans[i]++;
            }
            else
            {
                break;
            }
        }
        x = m;
        if(ans[i] > maxn)
        {
            maxn = ans[i];
        }
    }
    cout << maxn;
    return 0;
}