#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200010];
char c[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int l = 1, r = n, ll = a[1], rr = a[n];
    while(l < r){
        if(c[l] == c[r]){
            if(ll > rr){
                ll -= rr;
                r--;
                rr = a[r];
            } else if(ll < rr){
                rr -= ll;
                l++;
                ll = a[l];
            } else {
                l++;
                r--;
                ll = a[l];
                rr = a[r];
            }
        } else {
            if(ll > rr){
                ans += rr;
                ll -= rr;
                r--;
                rr = a[r];
            } else if(ll < rr){
                ans += ll;
                rr -= ll;
                l++;
                ll = a[l];
            } else {
                ans += ll;
                l++;
                r--;
                ll = a[l];
                rr = a[r];
            }
        }
    }
    cout << ans;
    return 0;
}
