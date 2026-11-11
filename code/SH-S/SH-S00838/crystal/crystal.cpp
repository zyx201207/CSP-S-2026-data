#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

long long a[500010] , s[500010];

int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1 , r = i , mx = i;
        while (l <= r)
        {
            int mid = ((l + r) >> 1);
            if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
            {
                mx = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans , i - mx + 1);
    }
    cout << ans << '\n';
    return 0;
}
