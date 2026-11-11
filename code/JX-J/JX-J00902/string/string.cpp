#include <bits/stdc++.h>
using namespace std;
long long n, a[200001] = {}, fa, p = 0, cen = 0, l = 1, r = 0;
char c[200001] = {}, fc;
long long ans = 0;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i = 1;i <= n;i++){
        fa = 0; fc = ' ';
        cin >> fa >> fc;
        if(i != 1 and fc == c[p]){
            a[p] += fa;
        }
        else{
            p++;
            a[p] = fa;
            c[p] = fc;
        }
    }

    r = n;

    while(1){
        if(a[l] > a[r]){
            if(c[l] != c[r]) ans += a[r];
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }
        else if(a[l] < a[r]){
            if(c[l] != c[r]) ans += a[l];
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
        else{
            if(c[l] != c[r]) ans += a[r];
            a[l] = 0;
            a[r] = 0;
            l++;
            r--;
        }
        if(l > r) break;
    }

    cout << ans;

    return 0;
}
