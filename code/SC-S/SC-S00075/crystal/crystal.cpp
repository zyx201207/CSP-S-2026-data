#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 5e5 + 5;
int n; ll m;    
ll a[mxn] , sum[mxn];
inline bool check(int len){
    for(int i = len ; i <= n ; i++){
        ll cost = sum[i] - sum[i - len] - (a[i] - a[i - len]) * (ll)(i - len);
        if(cost <= m){ return true; }
    }
    return false;
}
int main(){
    freopen("crystal.in" , "r" , stdin); freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;   
    for(int i = 1 ; i <= n ; i++){ cin >> a[i]; }
    sort(a + 1 , a + 1 + n); sum[1] = 0;
    for(int i = 2 ; i <= n ; i++){ sum[i] = sum[i - 1] + (a[i] - a[i - 1]) * (i - 1); }  
    int l = 1 , r = n , ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){ ans = mid; l = mid + 1; }
        else{ r = mid - 1; }
    } cout << ans << "\n";
    return 0;
}