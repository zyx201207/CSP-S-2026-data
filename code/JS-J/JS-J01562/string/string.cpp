#include <bits/stdc++.h>
using namespace std;
long long a[200005],sum[200005],ans ;
char c[200005] ;
int main()
{
    freopen("string.in","r",stdin) ;
    freopen("string.out","w",stdout) ;
    string s ;
    int n ;
    cin >> n ;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i] ;
        sum[i] = sum[i - 1] + a[i] ;
    }
    for (int i = 1;sum[i] <= sum[n] / 2;i++)
    {
        if (a[i] == a[n - i + 1])
        {
            if (c[i] != c[n - i + 1])
            {
                ans += a[i] ;
            }
        }
        else
        {
            if (c[i] == c[n - i + 1])
            {
                ans = ans + abs(a[i] - a[n - i + 1]) ;
            }
            else
            {
                ans += a[i] ;
            }
        }
    }
    cout << ans ;
    return 0 ;
}
