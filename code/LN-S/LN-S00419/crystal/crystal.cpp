#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, ans;
long long m, a[N], sum[N];
bool check(int x) {
   long long cnt = 0;
   for(int i = 1;i < x; i++) {
        cnt += sum[x] - sum[i];
   }
   return cnt <= m;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n; i++) sum[i] = a[i] - a[1];
    int l = 1, r = n;
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    ans = l;
    for(int i = l + 1; i <= n ;i++) {
        if(l == a[i]) ans++;
        else break;
    }
    cout << ans;
    return 0;

}
