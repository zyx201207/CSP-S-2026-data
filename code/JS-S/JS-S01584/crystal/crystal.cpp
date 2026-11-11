#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n;
ll m;
ll a[N];
ll sum[N];
bool check(int x){
    ll cnt1, cnt2;
    for(int i = x;i <= n;i++){
        cnt1 = a[i]*x;
        cnt2 = sum[i]-sum[i-x];
        if(cnt1-cnt2 <= m) return true;
    }
    return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    int l = 1, r = n;
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(check(n-mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << n-l;
    return 0;
}
