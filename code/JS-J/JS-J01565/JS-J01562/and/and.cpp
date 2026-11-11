#include <bits/stdc++.h>
using namespace std;
long long a[100005] ;
int main()
{
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    int n,m,maxai = -1 ;
    cin >> n >> m ;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] ;
    }
    if (m == 1)
    {
        sort(a + 1,a + n + 1) ;
        maxai = a[n] ;
        cout << maxai ;
    }
    else if(m == 2)
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = i + 1;j <= n;j++)
            {
                int t = a[i] & a[j] ;
                if (maxai < t)
                    maxai = t ;
            }
        }
        cout << maxai ;
    }
    else if(m == n)
    {
        maxai = a[1] ;
        for (int i = 2;i <= n;i++)
        {

            maxai = maxai & a[i] ;
            cout << maxai ;
        }
    }
    return 0 ;
}
