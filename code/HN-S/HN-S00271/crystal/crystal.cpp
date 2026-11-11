#include<bits/stdc++.h>
#define int long long
using namespace std;

int n , m , a[500005] , s[500005] , ans;
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    sort(a + 1 , a + n + 1);
    for( int i = 1 ; i <= n ; i++ ) s[i] = s[i - 1] + a[i];
    for( int i = 1 ; i <= n ; i++ ){
        int l = 1 , r = i;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if( a[i] * mid - ( s[i] - s[i - mid] ) <= m ) l = mid;
            else r = mid - 1;
           // cout << mid << " ";
        }
        ans = max( ans , l );
       // cout << l << "\n";
    }
    cout << ans;
    return 0;
}
