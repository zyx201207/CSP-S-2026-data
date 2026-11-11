#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
ll n, m, a[N], sum[N], ans;

bool check(ll k){
    for(int i = 1; i+k-1 <= n; i++){
        if(a[i+k-1]*k - sum[i+k-1] + sum[i-1] <= m) return true;
    }
    return false;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    ll L = 1, R = n, ans = -1;
    while(L <= R){
        ll mid = (L + R) / 2;
        if(check(mid)) ans = mid, L = mid+1;
        else R = mid-1;
    }
    cout << ans << endl;
    return 0;
}
