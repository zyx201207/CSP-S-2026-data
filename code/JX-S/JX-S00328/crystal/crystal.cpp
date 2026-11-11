#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 7;
int n;
ll a[N], sum[N], m;
bool check(int x) {
    for(int i = x; i <= n; i++) {
        int l = i - x + 1, r = i;
        ll s = sum[r] - sum[l - 1];
        ll res = a[i] * x;
        if(res - s <= m) return true;
    }
    return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>> n>> m;
    for(int i = 1; i <= n; i++) cin>> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, ans = 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout<< ans;
    return 0;
}
