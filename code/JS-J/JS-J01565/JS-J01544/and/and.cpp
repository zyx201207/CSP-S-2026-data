#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in" , "r" , stdin );
    freopen("and.out" , "w" , stdout );
    int n , m;
    cin >> n >> m;
    long long a[n];
    for( int i=0 ; i<n ; i++ )
    {
        cin >> a[i];
    }
    long long maxn = -9999999999;
    for( int i=0 ; i<n ; i++ )
    {
        for( int j=0 ; j<n ; j++ )
        {
            if( (a[i] | a[j]) >= maxn )
            {
                maxn = a[i] | a[j];
            }
        }
    }
    cout << maxn;
    return 0;
}
