#include<bits/stdc++.h>
using namespace std ;

int a[200010] ;
char c[200010] ;
int n ;

int main()
{
    freopen("string.in", "r", stdin) ;
    freopen("string.out", "w", stdout) ;
    long long ans = 0 ;
    scanf("%d", &n) ;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] >> c[i] ;
    }
    for(int i=0; i<n; i++)
    {
        int k = n-i-1 ;
        while(a[i] && k > i)
        {

            if(a[i] >= a[k])
            {
                if(c[i] == c[k])
                {
                    a[i] -= a[k] ;
                    a[k] = 0 ;
                    k-- ;
                }
                else
                {
                    ans += a[k] ;
                    a[i] -= a[k] ;
                    a[k] = 0 ;
                    c[k] = c[i] ;
                    k-- ;
                }
            }
            else
            {
                if(c[i] == c[k])
                {
                    a[k] -= a[i] ;
                    a[i] = 0 ;
                }
                else
                {
                    ans += a[i] ;
                    a[k] -= a[i] ;
                    a[i] = 0 ;
                    c[i] = c[k] ;
                }
            }
        }
    }
    cout << ans ;
    return 0 ;
}
