#include<bits/stdc++.h>
using namespace std;
long long n, a[200010], ans;
char c[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(long long i = 1; i <= n; i++) cin >> a[i] >> c[i];
    long long l = 1, r = n;
    while(l < r){
        long long t = min(a[l], a[r]);
        if(c[l] != c[r]) ans += t;
        a[l] -= t, a[r] -= t;
        while(a[l] == 0) l += 1;
        while(a[r] == 0) r -= 1;
    }
    cout << ans;

    return 0;
}
