#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n, m, cnt;
int ans;
ll a[N],b[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen( "crystal.in" , "r" , stdin );
    freopen( "crystal.out" , "w" , stdout );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    sort ( a+1 , a+n+1 );
    for ( int i = 1; i <= n; i++ ){
        b[i] = a[i] + b[i - 1];
    }
    for ( int i = 2; i <= n; i++ ){
        for ( int j = 1 ; j <= i ; j++ ){
            cnt = a[i] * ( i - j + 1 ) - ( b[i] - b[j - 1] );
            if ( cnt <= m ) ans = max( i - j + 1, ans );
        }
    }
    cout << ans;
    return 0;
}
