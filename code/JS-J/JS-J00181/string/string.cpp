#include<bits/stdc++.h>
using namespace std;
string s1, s2;
long long n, l, ans;
int main()
{
    freopen( "string.in", "r", stdin );
    freopen( "string.out", "w", stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ), cout.tie( 0 );
    cin >> n;
    for( long long i = 1; i <= n; i++ )
    {
        long long x;
        char c;
        cin >> x >> c;
        while( x-- )
        {
            s1 += c;
            s2 = c + s2;
        }
    }
    l = s1.size();
    for( long long i = 0; i < l / 2; i++ )
    {
        if( s2[i] != s1[i] ) ans++;
    }
    cout << ans << endl;
    return 0;
}