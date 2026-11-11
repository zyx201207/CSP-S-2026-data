#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, d, c, t, a[2000010], ans;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(int _ = 1;_ <= t;_++){
        cin >> n >> d;
        for(ll i = 1;i <= n;i++){
            cin >> a[i];
        }
        if(c == 11 || c == 12){
            if(d >= a[2] - a[1]){
                d = d / (a[2] - a[1]);
                for(int i = d + 1;i < d * 2;i++){
                    ans += n - i;
                }

            }
        }
        cout << ans << endl;
    }
    return 0;
}
