#include <bits/stdc++.h>
using namespace std;

long long n, a[325799], cnt, ans, s[325799];
char c[325799];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i] >> c[i];
    if (n == 1){
        cout << 0;
        return 0;
    }
    for (long long i=1; i<=ceil(n/2); i++){
        if (ans == 0){
            if (c[i] != c[n-i+1]){
                cnt += min(a[i], a[n-i+1]);
                ans = a[i]-a[n-i+1];
            }
            else{
                ans = a[i]-a[n-i+1];
            }
        }
        else if (ans > 0){
            a[i-1] = ans;
            if (c[i] != c[n-i]){
                cnt += min(a[i], a[n-i]);
                ans = a[i]-a[n-i];
            }
            else{
                ans = a[i]-a[n-i];
            }
        }
        else if (ans < 0){
            a[n-i+2] = abs(ans);
            if (c[i] != c[n-i+2]){
                cnt += min(a[i], a[n-i+2]);
                ans = a[i]-a[n-i+2];
            }
            else{
                ans = a[i]-a[n-i+2];
            }
        }
    }
    cout << cnt;

    return 0;
}
