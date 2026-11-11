#include<bits/stdc++.h>
using namespace std;

long long n, a[400000], x, maxx, ans;

char c;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout)

    cin >> n;
    for(int i = 0; i < n; i++){
       cin >>  x >> c;
       a[c - 96] += x;
       ans += x;
    }
    maxx = a[0];
    for(int i = 0; i < 26; i ++){
        maxx = max(a[i], maxx);
    }
    if(ans == maxx){
        cout << '0';
        return 0;
    }
    if(ans % 2 == 0){
        cout << ans - maxx;
        return 0;
    }
    else if(ans % 2 == 1){
        cout << ans - maxx - 1;
    }
    return 0;
}
