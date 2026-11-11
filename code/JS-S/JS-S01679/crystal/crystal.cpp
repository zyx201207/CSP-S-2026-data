#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL m,a;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    cin >> a;
    if(a < 0){
        int ans = 0;
        while(n){
            ans += n / 2;
            if(n &1  && m + a > 0)
                ans++, m += a;
            n /= 2, m /= 2;
        }
        cout << ans;
    }
    else if(a > 0){
        int ans = 0;
        while(n){
            ans += n / 2;
            if(n & 1 && m > a)
                ans++, m += a;
            n /= 2, m /= 2;
        }
        cout << ans;
    }
    else
        cout << n - 1;
    return 0;
}
