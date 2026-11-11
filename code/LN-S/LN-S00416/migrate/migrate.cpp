#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace SHuxinn{
    int n , d;
    int a[2000010];
    int s[2000010];
    int b[2000010];
    bool tm = 0;
    int ans = 0;
    void Sx5(){
        cin >> n >> d;
        for(int i = 1 ; i <= n ; i ++)
            cin >> b[i];
        memset(a , 0 , sizeof(a));
        a[1] = 1;
        for(int i = 2 ; i <= n ;  i++) {
            a[i] += b[i] + 1 - b[1];
        }
        ans = 0;
        tm = 0;
        for(int i = 1 ; i <= n ; i ++) {
            s[i] = s[i - 1] + a[i] - a[i - 1];
        }
        for(int i = 1 ; i <= n - 3 ; i ++) {
            if((a[i + 2] - a[i] <= d) && (a[i + 3] - a[i] > d) && (a[i + 3] - a[i + 1] > d)) {
                ans ++;
            }
        }
        cout << ans << endl;
        return;
    }
}
signed main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int C , T;
    cin >> C >> T;
    while(T--) SHuxinn::Sx5();
    return 0;
}
