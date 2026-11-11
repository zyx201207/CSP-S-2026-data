#include<bits/stdc++.h>
using namespace std ;

int a[100010] ;

int main()
{
    freopen("crystal", "r", stdin) ;
    freopen("crystal", "w", stdout) ;
    int n, m, maxn = -1e9 ;
    scanf("%d%d", &n, &m) ;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]) ;
    }
    sort(a, a+n) ;
    for(int i=1; i<n; i++)
    {
        int h = a[i] ;
        int l = m ;
        int k = 0;
        for(int j=i-1; j>=0; j++)
        {
            l -= h + a[j] ;
            k++ ;
            if(l == 0)
            {
                break ;
            }
            if(l < 0)
            {
                k-=1 ;
                break;
            }
        }
        maxn = max(maxn, k+1) ;
    }
    cout << maxn ;
    return 0 ;
}
