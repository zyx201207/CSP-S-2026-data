#include <bits/stdc++.h>
using namespace std ;

int n , m , a[500005] , dp[500005] , maxx;

int main()
{
    freopen("ans.in","r",stdin) ;
    freopen("ans.out","w",stdout) ;
    cin >> n >> m ;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] ;
    }
    sort (a+1,a+n+1);
    if(m == 1)
    {
        cout << a[n] ;
    }
    else if (m == 2)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i == j) continue ;

                maxx = max(a[i] & a[j], maxx) ;
            }
        }
        cout << maxx ;
    }
    else{
        maxx = a[n] ;
        for (int i = n; i >= n-m; i--)
        {
            maxx &= a[i] ;
        }
        cout << maxx ;
    }
    return 0 ;
}
