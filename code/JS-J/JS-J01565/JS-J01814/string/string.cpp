#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;
int ans;
int a[N];
char c[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int idx = n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int i = 1;
    while (1) {
        if (c[i] == c[idx]) {
            if (a[idx] > a[i]) {
                a[idx] -= a[i];
                i++;
            } else  if (a[idx] < a[i]){
                a[i] -= a[idx];
                idx--;
            } else {
                a[i] -= a[idx];
                idx--;
                i++;
            }
        } else{
            if (a[idx] > a[i]) {
                a[idx] -= a[i];
                ans += a[i];
                i++;
            } else  if (a[idx] < a[i]){
                a[i] -= a[idx];
                ans += a[idx];
                idx--;
            } else {
                a[i] -= a[idx];
                ans += a[idx];
                idx--;
                i++;
            }
        }
        if (i == idx || i > n)
            break;
    }
    cout << ans;
    return 0;
}
