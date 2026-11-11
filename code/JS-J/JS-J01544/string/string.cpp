#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen( "string.in" , "r" , stdin );
    freopen( "string.out" , "w" , stdout );
    long long n;
    cin >> n;
    long long a[n];
    string b;
    for( int i=0 ; i<n ; i++ )
    {
        cin >> a[i] >> b[i];
    }
    int m = 1;
    for( int i=0 ; i<n-1 ; i++ )
    {
        if( b[i] != b[i+1] )
        {
            m = 0;
        }
    }
    if( m == 1 )
    {
        cout << "0";
        return 0;
    }
    else
    {
        string new_string;
        for( int i=0 ; i<n ; i++ )
        {
            for( int j=0 ; j<a[i] ; j++ )
            {
                new_string += b[i];
            }
        }
        int x = 0 , cnt = 0;
        if( new_string.length() % 2 == 0 )
        {
            for( int i=new_string.length()/2 ; i<n ; i++ )
            {
                if( new_string[i] != new_string[i-(2*x+1)] )
                {
                    cnt++;
                }
                x++;
            }
        }
        else
        {
            for( int i=new_string.length()/2+1 ; i<n ; i++ )
            {
                if( new_string[i] != new_string[i-(2*x+2)] )
                {
                    cnt++;
                }
                x++;
            }
        }
        cout << cnt;
    }
    return 0;
}
