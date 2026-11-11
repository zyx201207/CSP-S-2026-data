#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int n , m , a[N] , c[N] , s[N] , ans , cc;
bool t = true , tt = true;

bool check(int i , int j) {
    int sum = s[i] - s[j];
    if (sum > m) return false;
    return true;
}

signed main() {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    scanf ("%lld%lld" , &n , &m);
    for (int i=1; i<=n; i++) {
        scanf ("%lld" , &a[i]);
        if (a[i] != i) t = false;
    }
    if (t) {
        for (int i=1; i; i++) {
            s[i+1] = s[i] + i;
            if (s[i+1] > m){
                printf ("%lld" , i);
                return 0;
            }
        }
    }
    sort (a+1 , a+1+n);
    cc = c[1] = a[2] - a[1];
    for (int i=2; i<n; i++) {
        c[i] = a[i+1] - a[i];
        if (c[i] != cc) tt = false;
    }
    if (tt) {
        for (int i=1; i; i++) {
            s[i+1] = s[i] + i*cc;
            if (s[i+1] > m){
                printf ("%lld" , i);
                return 0;
            }
        }
    }
    for (int i=1; i<n; i++) s[i] = s[i-1] + c[i];
    for (int i=1; i<n; i++) {
        int l = 0 , r = i;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (check(i , mid)) r = mid - 1;
            else l = mid + 1;
        }
        if (i - r > ans) ans = i-r;
    }
    printf ("%lld" , ans);
    return 0;
}
