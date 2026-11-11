#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, m;int ans = 1;
ll a[N];
signed main(){
   freopen("crystal.in", "r", stdin);
   freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> n>> m;
    for(int i = 1;i <= n;i++){
        cin>> a[i];
    }sort(a + 1, a + n + 1);
    int l = 1, r = 1;
    while(r < n){
        while(r < n && (a[r + 1] - a[r]) * (r - l + 1) <= m){
            m -= (a[r + 1] - a[r]) * (r - l + 1);
            r++;
        }ans = max(ans, r - l + 1);
        while(l < r && (a[r + 1] - a[r]) * (r - l + 1) > m){
            m += a[r] - a[l];
            l++;
        }
        if(l == r){
            l++; r++;
        }
    }cout<< ans;
    return 0;
}
