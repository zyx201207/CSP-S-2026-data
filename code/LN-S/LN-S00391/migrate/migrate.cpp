#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int c,t,n,d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
   cin >> c >> t;
   for(int i = 1;i <= t;i++){
       cin >> n >> d;
       for(int i = 1;i <= n;i++){
            cin >> a[i];
       }
       if(n == 0) {
            cout << 0 <<'\n';
            continue;
       }
       int k = a[2]-a[1];
       bool f = false;
       for(int i = 1;i <= n;i++){
            if(k != a[i + 1] - a[i]){
                f = true;
            }
       }
     //  if(f == true){
            int ans = 0;
            for(int i = 1;i <= n;i++){
                if(i % 2 == 0 && i / 2 + 1 == d){
                    ans++;
                }
            }
            if(n % 2 == 1){
                ans *= 2;
            }
            cout << ans <<'\n';
       //}
   }
    return 0;
}
