#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 0, sum = 0, l = 1;
    for(int r = 1; r <= n; r++) {
        while(l < r && sum > m) sum -= a[r] - a[l++];
        sum += (r - l) * (a[r] - a[r - 1]);
        if(sum <= m) ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}