#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], n;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    long long l = 1, r = n, res = 0;
    while(l < r){
        if(a[l] > a[r]){
            if(c[l] != c[r]) res += a[r];
            a[l] -= a[r];
            r--;
        }
        else if(a[l] < a[r]){
            if(c[l] != c[r]) res += a[l];
            a[r] -= a[l];
            l++;
        }
        else{
            if(c[l] != c[r]) res += a[l];
            l++, r--;
        }
    }
    cout << res;
    return 0;
}
